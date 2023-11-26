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
int64_t _16_main(void);

/* Function definitions */
int64_t _16_main(void) {
    int64_t _16_t1;
    int64_t _16_t2;
    struct0 _17_x;
    struct0* _17_y;
    int64_t _16_$retval;
    _16_t1 = 11;
    _16_t2 = 11;
    _17_x = (struct0) {_16_t1, _16_t2};
    _17_y = &_17_x;
    (*_17_y)._0 = 50;
    _16_$retval = $add_int64_t((*_17_y)._0, (*_17_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _16_$retval;
}

int main(void) {
  printf("%ld",_16_main());
  return 0;
}
