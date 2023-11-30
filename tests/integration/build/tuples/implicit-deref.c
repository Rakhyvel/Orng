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
int64_t _31_main(void);

/* Function definitions */
int64_t _31_main(void) {
    int64_t _31_t1;
    int64_t _31_t2;
    struct0 _32_x;
    struct0* _32_y;
    int64_t _31_$retval;
    _31_t1 = 11;
    _31_t2 = 11;
    _32_x = (struct0) {_31_t1, _31_t2};
    _32_y = &_32_x;
    (*_32_y)._0 = 50;
    _31_$retval = $add_int64_t((*_32_y)._0, (*_32_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _31_$retval;
}

int main(void) {
  printf("%ld",_31_main());
  return 0;
}
