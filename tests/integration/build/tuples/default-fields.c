/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1195_main(void);

/* Function definitions */
int64_t _1195_main(void) {
    int64_t _1195_t1;
    int64_t _1195_t2;
    struct0 _1196_x;
    int64_t _1195_$retval;
    _1195_t1 = 50;
    _1195_t2 = 7;
    _1196_x = (struct0) {_1195_t1, _1195_t2};
    _1195_$retval = $add_int64_t(_1196_x._0, _1196_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1195_$retval;
}

int main(void) {
  printf("%ld",_1195_main());
  return 0;
}
