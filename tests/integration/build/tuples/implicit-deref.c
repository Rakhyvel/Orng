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
int64_t _18_main(void);

/* Function definitions */
int64_t _18_main(void) {
    int64_t _18_t1;
    int64_t _18_t2;
    struct0 _19_x;
    struct0* _19_y;
    int64_t _18_$retval;
    _18_t1 = 11;
    _18_t2 = 11;
    _19_x = (struct0) {_18_t1, _18_t2};
    _19_y = &_19_x;
    (*_19_y)._0 = 50;
    _18_$retval = $add_int64_t((*_19_y)._0, (*_19_y)._1, "tests/integration/tuples/implicit-deref.orng:6:10:\n    y.a + y.b\n        ^");
    return _18_$retval;
}

int main(void) {
  printf("%ld",_18_main());
  return 0;
}
