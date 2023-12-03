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
int64_t _1111_main(void);

/* Function definitions */
int64_t _1111_main(void) {
    int64_t _1111_t1;
    int64_t _1111_t4;
    struct0 _1112_x;
    struct0* _1112_y;
    int64_t _1111_$retval;
    _1111_t1 = 19;
    _1111_t4 = 39;
    _1112_x = (struct0) {_1111_t1, _1111_t4};
    _1112_y = &_1112_x;
    _1111_$retval = $add_int64_t((*_1112_y)._0, (*_1112_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1111_$retval;
}

int main(void) {
  printf("%ld",_1111_main());
  return 0;
}
