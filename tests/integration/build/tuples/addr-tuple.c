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
int64_t _1737_main(void);


/* Function definitions */
int64_t _1737_main(void){
    int64_t _1737_t1;
    int64_t _1737_t4;
    struct struct0 _1738_x;
    struct struct0* _1738_y;
    int64_t _1737_$retval;
    _1737_t1 = 19;
    _1737_t4 = 39;
    _1738_x = (struct struct0) {_1737_t1, _1737_t4};
    _1738_y = &_1738_x;
    _1737_$retval = $add_int64_t((*_1738_y)._0, (*_1738_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1737_$retval;
}


int main(void) {
  printf("%ld",_1737_main());
  return 0;
}
