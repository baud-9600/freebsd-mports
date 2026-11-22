PORTNAME=	anytype
DISTVERSION=	1.4.3-2026-04-21
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Self-hosted sync server for Anytype (any-sync-bundle)
WWW=		https://github.com/grishy/any-sync-bundle

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/LICENSE

MASTER_SITES=	https://github.com/grishy/any-sync-bundle/releases/download/v${DISTVERSION}/
DISTNAME=	any-sync-bundle_${DISTVERSION}_freebsd_amd64
DIST_SUBDIR=	any-sync-bundle
EXTRACT_SUFX=	.tar.gz

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
STRIP=

USE_RC_SUBR=	anytype

PLIST_FILES=	bin/any-sync-bundle

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/any-sync-bundle \
		${STAGEDIR}${PREFIX}/bin/any-sync-bundle

.include <bsd.port.mk>
