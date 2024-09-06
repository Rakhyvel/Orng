/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1795_main(void);


/* Function definitions */
int64_t _1795_main(void){
    int64_t _1795_t1;
    int64_t _1795_t4;
    struct struct0 _1796_x;
    struct struct0* _1796_y;
    int64_t _1795_$retval;
    _1795_t1 = 19;
    _1795_t4 = 39;
    _1796_x = (struct struct0) {_1795_t1, _1795_t4};
    _1796_y = &_1796_x;
    _1795_$retval = $add_int64_t((*_1796_y)._0, (*_1796_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1795_$retval;
}


int main(void) {
  printf("%ld",_1795_main());
  return 0;
}
