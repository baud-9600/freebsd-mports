PORTNAME=	typerelay-server
PORTVERSION=	0.6.0
PORTREVISION=	1
PORTCAT=	server

MAINTAINER=	typerelay@example.com
COMMENT=	TypeRelay server component - Express-based self-hosted web app and API with MongoDB

LICENSE=	AGPL-3.0-only
LICENSE_FILE=	${WRKSRC}/LICENSE
WWW=	https://typerelay.com

# Node.js engine requirement (>=24)
USES=	node
NODEJS_VERSION=	24

# pnpm workspace package manager
USEPNPM=	yes
PNPM_VERSION=	12.18.0

# ES module application (package.json type: module)
NODEJS_ESM=	yes

# Runtime dependencies
RUN_DEPENDS+=	mongodb>=6.0:databases/mongodb \
		memcached>=1.4:net/memcached

# The server bundles the code/rich editors with esbuild at build time
BUILD_DEPENDS+=	esbuild:www/esbuild

PLIST_SUBST+=	%%EDITOR_OUTDIR%%

# Default editor output dir (matches scripts/build-editor.js default)
EDITOR_OUTDIR=	${PREFIX}/typerelay-editor

pre-build:
	@${ECHO_MSG} "Installing workspace dependencies"
	${ENV} ${MAKE_ENV} ${PNPM} install

do-build:
	@${ECHO_MSG} "Building TypeRelay server and editor bundles"
	${ENV} ${MAKE_ENV} EDITOR_OUTDIR=${EDITOR_OUTDIR} ${PNPM} --filter @typerelay/server build
	@${MKDIR} ${EDITOR_OUTDIR}
	@if [ -f "${WRKSRC}/template.wasm" ]; then \
		@${CP} -p "${WRKSRC}/template.wasm" "${EDITOR_OUTDIR}/template.wasm"; \
	fi
	@${ECHO_MSG} "Editor bundles installed to ${EDITOR_OUTDIR}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/typerelay-server
	@cp -R ${WRKSRC}/apps/server ${STAGEDIR}${PREFIX}/typerelay-server/apps/server
	@cp -R ${WRKSRC}/packages/observability ${STAGEDIR}${PREFIX}/typerelay-server/packages/observability
	@cp -p ${WRKSRC}/pnpm-workspace.yaml ${STAGEDIR}${PREFIX}/typerelay-server/pnpm-workspace.yaml
	@cp -p ${WRKSRC}/.env.example ${STAGEDIR}${PREFIX}/typerelay-server/.env.example
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${FILESDIR}/config.env.sample ${STAGEDIR}${ETCDIR}/typerelay-server.env
	@${MKDIR} ${STAGEDIR}${LOCALBASE}etc/rc.d
	@${INSTALL_DATA} ${FILESDIR}/typerelay-server.rc ${STAGEDIR}${LOCALBASE}etc/rc.d/typerelay-server.rc

do-post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "=========================================================="
	@${ECHO_MSG} " TypeRelay server installed to ${PREFIX}/typerelay-server"
	@${ECHO_MSG} " Sample config:       ${ETCDIR}/typerelay-server.env"
	@${ECHO_MSG} " Editor bundles dir:  ${EDITOR_OUTDIR}/"
	@${ECHO_MSG} " Enable with:         sysrc typerelay_server_enable=YES"
	@${ECHO_MSG} "=========================================================="

.include <bsd.port.mk>
