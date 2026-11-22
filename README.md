# mports

FreeBSD ports overlay used by the Sylve jails on `srv01`.

## Ports

| Origin | Version | Notes |
| --- | --- | --- |
| `audio/beets` | 2.12.0 | |
| `comms/zigbee2mqtt` | 2.14.0 | ships the node_modules tarball in the port |
| `databases/redisbloom` | 2.8.3 | |
| `dns/technitium` | 15.6.2 | new port; .NET 10 (`lang/dotnet`), installs to `/opt/technitium` |
| `multimedia/jellyfin` | 10.11.11 | |
| `net-im/signal-cli` | 0.14.7 | |
| `net-p2p/slskd` | 0.26.2 | .NET 10, self-contained single-file build |
| `sysutils/anytype` | 1.4.3-2026-04-21 | |
| `sysutils/grub2-bhyve` | | overlay patch for the port in the main tree |
| `www/opodsync` | 0.5.3 | |

`filesystems/zfstools` was not imported: it only contains a patch fragment and
no `Makefile`, so it is not a usable port on its own.

## Building with poudriere

Register the overlay as a null ports tree:

```sh
poudriere ports -c -p overlay -m null -M /usr/mports
```

Then build ports in the normal tree with the overlay applied:

```sh
poudriere bulk -j freebsd_15-1x64 -p HEAD -O overlay -z defaultopts dns/technitium net-p2p/slskd
```

The `defaultopts` set is optional. It is useful when the official package
repository should be used for dependencies that were built with default port
options.

## Local UID/GID

`net-p2p/slskd` uses UID/GID 789. The `UIDs` and `GIDs` files in this repo are
intended to be copied to the poudriere environment (for example
`/usr/local/etc/poudriere-UIDs` and `/usr/local/etc/poudriere-GIDs`) and copied
into the build jail by an executable poudriere hook. They are deliberately not
added to the host's `passwd`/`group` databases.

## Technitium

The port installs the application into `/opt/technitium`; configuration, zones
and cache live in `/var/db/technitium`. The web console listens on port 5380 and
the DNS service on port 53.

```sh
sysrc technitium_enable=YES
service technitium start
```
