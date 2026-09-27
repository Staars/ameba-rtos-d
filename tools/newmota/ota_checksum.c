/* Host-side checksum updater for the AmebaD OTA container. */
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define OTA_HEADER_SIZE 32L
#define OTA_CHECKSUM_OFFSET 16L
#define CHECKSUM_BUFFER_SIZE 8192U

static int get_file_size(FILE *file, long *size)
{
	if (fseek(file, 0L, SEEK_END) != 0) {
		return -1;
	}

	*size = ftell(file);
	if (*size < 0 || fseek(file, 0L, SEEK_SET) != 0) {
		return -1;
	}
	return 0;
}

static int calculate_checksum(FILE *image, FILE *container, long image_size, uint32_t *checksum)
{
	unsigned char image_buffer[CHECKSUM_BUFFER_SIZE];
	unsigned char container_buffer[CHECKSUM_BUFFER_SIZE];
	uint32_t sum = 0;
	long remaining = image_size;

	if (fseek(image, 0L, SEEK_SET) != 0 || fseek(container, OTA_HEADER_SIZE, SEEK_SET) != 0) {
		return -1;
	}

	while (remaining > 0) {
		size_t count = remaining > (long)sizeof(image_buffer)
			? sizeof(image_buffer)
			: (size_t)remaining;
		size_t index;

		if (fread(image_buffer, 1, count, image) != count ||
			fread(container_buffer, 1, count, container) != count) {
			return -1;
		}
		if (memcmp(image_buffer, container_buffer, count) != 0) {
			return -1;
		}
		for (index = 0; index < count; ++index) {
			sum += image_buffer[index];
		}
		remaining -= (long)count;
	}

	*checksum = sum;
	return 0;
}

int main(int argc, char **argv)
{
	FILE *image;
	FILE *container;
	long image_size;
	long container_size;
	uint32_t checksum;
	unsigned char encoded_checksum[4];
	int result = 1;
	int close_error = 0;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <image> <OTA_All_with_header>\n", argv[0]);
		return 2;
	}

	image = fopen(argv[1], "rb");
	if (image == NULL) {
		perror(argv[1]);
		return 1;
	}
	container = fopen(argv[2], "r+b");
	if (container == NULL) {
		perror(argv[2]);
		fclose(image);
		return 1;
	}

	if (get_file_size(image, &image_size) != 0 ||
		get_file_size(container, &container_size) != 0) {
		fprintf(stderr, "cannot determine OTA input sizes\n");
		goto done;
	}
	if (image_size > LONG_MAX - OTA_HEADER_SIZE ||
		container_size != image_size + OTA_HEADER_SIZE) {
		fprintf(stderr, "OTA container size does not match its image\n");
		goto done;
	}
	if (calculate_checksum(image, container, image_size, &checksum) != 0) {
		fprintf(stderr, "OTA container payload does not match its image\n");
		goto done;
	}

	encoded_checksum[0] = (unsigned char)(checksum & 0xffU);
	encoded_checksum[1] = (unsigned char)((checksum >> 8) & 0xffU);
	encoded_checksum[2] = (unsigned char)((checksum >> 16) & 0xffU);
	encoded_checksum[3] = (unsigned char)((checksum >> 24) & 0xffU);
	if (fseek(container, OTA_CHECKSUM_OFFSET, SEEK_SET) != 0 ||
		fwrite(encoded_checksum, 1, sizeof(encoded_checksum), container) != sizeof(encoded_checksum) ||
		fflush(container) != 0) {
		fprintf(stderr, "cannot write OTA checksum\n");
		goto done;
	}

	result = 0;

done:
	if (fclose(image) != 0) {
		close_error = 1;
	}
	if (fclose(container) != 0) {
		close_error = 1;
	}
	return close_error ? 1 : result;
}
