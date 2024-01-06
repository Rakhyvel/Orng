/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1498_main(void);

/* Function definitions */
int64_t _1498_main(void){
    int64_t _1498_t1;
    int64_t _1498_t4;
    struct struct0 _1499_x;
    struct struct0* _1499_y;
    int64_t _1498_$retval;
    _1498_t1 = 19;
    _1498_t4 = 39;
    _1499_x = (struct struct0) {_1498_t1, _1498_t4};
    _1499_y = &_1499_x;
    _1498_$retval = $add_int64_t((*_1499_y)._0, (*_1499_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1498_$retval;
}

int main(void) {
  printf("%ld",_1498_main());
  return 0;
}
