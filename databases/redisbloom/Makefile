PORTNAME=	redisbloom
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.3
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Probabilistic data structures module for Redis (Bloom Filter, Cuckoo Filter, etc.)
WWW=		https://github.com/RedisBloom/RedisBloom

LICENSE=	AGPLv3 RSALv2 SSPLv1
LICENSE_COMB=	dual
LICENSE_NAME_RSALv2=	Redis Source Available License v2
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS_RSALv2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	cmake:devel/cmake

USE_GITHUB=	yes
GH_ACCOUNT=	RedisBloom
GH_PROJECT=	RedisBloom

GH_TUPLE=	RedisLabsModules:RedisModulesSDK:3b2f684:sdk/deps/RedisModulesSDK \
		RedisLabsModules:readies:f31347b:readies/deps/readies \
		RedisBloom:t-digest-c:5b89d70:tdigest/deps/t-digest-c

USES=		gmake
USE_GCC=	yes

PLIST_FILES=	lib/redis/modules/redisbloom.so

do-build:
	cd ${WRKSRC} && ${SETENV} CC=${CC} \
		${GMAKE} SO_LD_FLAGS="-shared -fPIC"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/redis/modules
	${INSTALL_PROGRAM} \
		${WRKSRC}/bin/freebsd-amd64-release/redisbloom.so \
		${STAGEDIR}${PREFIX}/lib/redis/modules/redisbloom.so

.include <bsd.port.mk>
