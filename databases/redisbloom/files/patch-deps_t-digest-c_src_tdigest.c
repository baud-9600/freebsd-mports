--- deps/t-digest-c/src/tdigest.c.orig
+++ deps/t-digest-c/src/tdigest.c
@@ -7,10 +7,12 @@
 #include <stdint.h>
 
 #ifndef TD_MALLOC_INCLUDE
-#define TD_MALLOC_INCLUDE "td_malloc.h"
+#define td_malloc_ malloc
+#define td_calloc_ calloc
+#define td_realloc_ realloc
+#define td_free_ free
 #endif
 
-#include TD_MALLOC_INCLUDE
 
 #define __td_max(x, y) (((x) > (y)) ? (x) : (y))
 #define __td_min(x, y) (((x) < (y)) ? (x) : (y))
