PORTNAME=	technitium
DISTVERSION=	15.6.2
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
	@${MKDIR} ${STAGEDIR}/opt/technitium
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/opt/technitium

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/technitium
	@${ECHO_CMD} "@dir /opt/technitium" > ${TMPPLIST}
	@cd ${STAGEDIR}/opt/technitium && ${FIND} . -type f | ${SED} 's|^\.|/opt/technitium|' | ${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}/opt/technitium && ${FIND} * -type d | ${SED} 's|^|@dir /opt/technitium/|' | ${SORT} -r >> ${TMPPLIST}
	@${ECHO_CMD} "@dir /var/db/technitium" >> ${TMPPLIST}

.include <bsd.port.mk>
