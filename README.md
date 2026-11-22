# freebsd-mports

FreeBSD ports overlay used by the Sylve jails on `srv01`.

## Ports in this overlay

| Origin | Version | Notes |
| --- | --- | --- |
| `audio/beets` | 2.12.0_2 | overlay fix: adds `www/py-requests-ratelimiter` for the MusicBrainz plugin |
| `dns/technitium` | 15.6.2_1 | .NET 10 (`lang/dotnet`); `/usr/local/technitium`, data in `/var/db/technitium` |
| `net-p2p/slskd` | 0.26.2_1 | .NET 10, self-contained single-file build; fixed rc.d script |
| `sysutils/anytype` | 1.4.3-2026-04-21 | self-hosted Anytype sync server |
| `sysutils/grub2-bhyve` | | overlay patch for the port in the main tree |
| `www/opodsync` | 0.5.3 | minimalist GPodder-compatible podcast sync server |
| `comms/zigbee2mqtt` | 2.14.0_1 | WIP: the main-tree origin is expired; it uses Node 24 and a FreeBSD-specific npm cache |

The following ports are in the main tree and are **not** duplicated in this
overlay: `databases/redisbloom`, `multimedia/jellyfin`, `net-im/signal-cli`.

`filesystems/zfstools` was not imported: it only contains a patch fragment and
no `Makefile`, so it is not a usable port on its own.

## Related repositories

The `net-p2p/slskd` port is also maintained in the separate
[baud-9600/slskd-port](https://github.com/baud-9600/slskd-port) repository.
This overlay includes a copy so that the mports overlay is self-contained.

## Building with poudriere

Register the overlay as a null ports tree:

```sh
poudriere ports -c -p overlay -m null -M /usr/mports
```

Then build ports in the normal tree with the overlay applied:

```sh
poudriere bulk -j freebsd_15-1x64 -p HEAD -O overlay -z defaultopts -f /usr/local/etc/poudriere.d/port-list
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

The port installs the application into `/usr/local/technitium`; configuration,
zones and cache live in `/var/db/technitium`. The web console listens on port
5380 and the DNS service on port 53.

```sh
sysrc technitium_enable=YES
service technitium start
```

## beets / MusicBrainz

The main-tree `audio/beets` 2.12.0_1 does not depend on
`www/py-requests-ratelimiter`; the MusicBrainz plugin fails to load with
`No module named 'requests_ratelimiter'`. The overlay port is based on the
main-tree 2.12.0_1 and adds that runtime dependency (`PORTREVISION=2`).

## zigbee2mqtt caveat

The `comms/zigbee2mqtt` origin is marked expired in the main tree (it used to
depend on `www/node20`). The overlay port uses Node 24 and the installed
2.14.0_1 package is working, so the port is kept as WIP. When bumping it,
regenerate the npm cache tarball on FreeBSD: `serialport/bindings-cpp` is
platform-specific.
