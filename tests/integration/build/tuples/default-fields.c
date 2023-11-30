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
int64_t _1481_main(void);

/* Function definitions */
int64_t _1481_main(void) {
    int64_t _1481_t1;
    int64_t _1481_t2;
    struct0 _1482_x;
    int64_t _1481_$retval;
    _1481_t1 = 50;
    _1481_t2 = 7;
    _1482_x = (struct0) {_1481_t1, _1481_t2};
    _1481_$retval = $add_int64_t(_1482_x._0, _1482_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1481_$retval;
}

int main(void) {
  printf("%ld",_1481_main());
  return 0;
}
