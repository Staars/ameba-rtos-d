# TODO

## Experimental: remove selected WLAN diagnostic strings

The application links the prebuilt `lib_wlan.a`. `SDK_LOG_LEVEL=none` can suppress
runtime diagnostics, but it does not remove strings from this archive. A prior `bw16-2m`
image scan found 92 `RTL8721D[Driver]` strings totaling 5,460 bytes; this is candidate
string data, not a measured size saving.

Try a scratch-only transformation of an archive copy for `SDK_LOG_LEVEL=none` before
considering integration:

- Guard the transformation with the exact input archive hash and an audited string
  allowlist. Some mergeable string sections mix diagnostics with operational strings, and
  other messages come through string tables.
- Preserve section sizes and offsets, then relink and compare loadable image size and
  relocation results against an unchanged baseline. The transformation would remove string
  payload only; log branches and argument setup would remain.
- Do not integrate unless the scratch result is safe and shows a real size reduction. If
  string-only rewriting is insufficient, obtain matching WLAN sources or a vendor-built
  no-log archive.
- Validate runtime behavior before accepting the change. Any board or serial test requires
  explicit user permission.
