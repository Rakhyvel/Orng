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
int64_t _1469_main(void);

/* Function definitions */
int64_t _1469_main(void) {
    int64_t _1469_t1;
    int64_t _1469_t2;
    struct0 _1470_x;
    struct0* _1470_y;
    int64_t _1469_$retval;
    _1469_t1 = 11;
    _1469_t2 = 11;
    _1470_x = (struct0) {_1469_t1, _1469_t2};
    _1470_y = &_1470_x;
    (*_1470_y)._0 = 50;
    _1469_$retval = $add_int64_t((*_1470_y)._0, (*_1470_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _1469_$retval;
}

int main(void) {
  printf("%ld",_1469_main());
  return 0;
}
