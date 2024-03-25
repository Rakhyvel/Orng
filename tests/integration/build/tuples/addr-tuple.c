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
int64_t _1732_main(void);


/* Function definitions */
int64_t _1732_main(void){
    int64_t _1732_t1;
    int64_t _1732_t4;
    struct struct0 _1733_x;
    struct struct0* _1733_y;
    int64_t _1732_$retval;
    _1732_t1 = 19;
    _1732_t4 = 39;
    _1733_x = (struct struct0) {_1732_t1, _1732_t4};
    _1733_y = &_1733_x;
    _1732_$retval = $add_int64_t((*_1733_y)._0, (*_1733_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1732_$retval;
}


int main(void) {
  printf("%ld",_1732_main());
  return 0;
}
