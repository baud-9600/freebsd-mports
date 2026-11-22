PORTNAME=	technitium
DISTVERSION=	15.6.2
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://download.technitium.com/dns/
DISTFILES=	DnsServerPortable.tar.gz
DIST_SUBDIR=	technitium/${DISTVERSION}
DISTNAME=	technitium-${DISTVERSION}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	mk@asdfghasdfgh.de
COMMENT=	Technitium DNS Server
WWW=		https://technitium.com/dns/

LICENSE=	GPLv3

RUN_DEPENDS=	dotnet:lang/dotnet

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

USE_RC_SUBR=	technitium

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/technitium
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/technitium

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/technitium
	@${ECHO_CMD} "@dir technitium" > ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/technitium && ${FIND} . -type f | ${SED} 's|^\./|technitium/|' | ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/technitium && ${FIND} * -type d | ${SED} 's|^|@dir technitium/|' | ${SORT} -r >> ${TMPPLIST}
	@${ECHO_CMD} "@dir /var/db/technitium" >> ${TMPPLIST}

.include <bsd.port.mk>
