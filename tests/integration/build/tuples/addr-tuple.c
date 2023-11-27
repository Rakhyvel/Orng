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
int64_t _1076_main(void);

/* Function definitions */
int64_t _1076_main(void) {
    int64_t _1076_t1;
    int64_t _1076_t4;
    struct0 _1077_x;
    struct0* _1077_y;
    int64_t _1076_$retval;
    _1076_t1 = 19;
    _1076_t4 = 39;
    _1077_x = (struct0) {_1076_t1, _1076_t4};
    _1077_y = &_1077_x;
    _1076_$retval = $add_int64_t((*_1077_y)._0, (*_1077_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1076_$retval;
}

int main(void) {
  printf("%ld",_1076_main());
  return 0;
}
