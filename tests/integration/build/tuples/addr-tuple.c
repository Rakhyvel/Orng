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
int64_t _1832_main(void);


/* Function definitions */
int64_t _1832_main(void){
    int64_t _1832_t1;
    int64_t _1832_t4;
    struct struct0 _1833_x;
    struct struct0* _1833_y;
    int64_t _1832_$retval;
    _1832_t1 = 19;
    _1832_t4 = 39;
    _1833_x = (struct struct0) {_1832_t1, _1832_t4};
    _1833_y = &_1833_x;
    _1832_$retval = $add_int64_t((*_1833_y)._0, (*_1833_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _1832_$retval;
}


int main(void) {
  printf("%ld",_1832_main());
  return 0;
}
