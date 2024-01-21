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
int64_t _1526_main(void);

/* Function definitions */
int64_t _1526_main(void){
    int64_t _1526_t1;
    int64_t _1526_t4;
    struct struct0 _1527_x;
    struct struct0* _1527_y;
    int64_t _1526_$retval;
    _1526_t1 = 19;
    _1526_t4 = 39;
    _1527_x = (struct struct0) {_1526_t1, _1526_t4};
    _1527_y = &_1527_x;
    _1526_$retval = $add_int64_t((*_1527_y)._0, (*_1527_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1526_$retval;
}

int main(void) {
  printf("%ld",_1526_main());
  return 0;
}
