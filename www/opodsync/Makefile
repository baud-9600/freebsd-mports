PORTNAME=	opodsync
DISTVERSION=	0.5.3
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimalist self-hosted GPodder-compatible podcast sync server
WWW=		https://github.com/kd2org/opodsync

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	kd2org
GH_PROJECT=	opodsync
GH_TAGNAME=	9e9cf0f0a6309952b8dbe57bca292c1f1f99c395

NO_BUILD=	yes
NO_ARCH=	yes

USES=		php:web
USE_PHP=	sqlite3 session filter ctype
DEFAULT_VERSIONS+=	php=8.4

WWWOWN=		www
WWWGRP=		www
WWWDIR=		${PREFIX}/www/${PORTNAME}

PORTDOCS=	README.md CHANGES.md TODO.md
OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC}/server && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/config.dist.php ${STAGEDIR}${WWWDIR}/config.dist.php
	${MKDIR} ${STAGEDIR}${WWWDIR}/data

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
