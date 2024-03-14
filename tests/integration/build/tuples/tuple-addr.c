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
    int64_t* _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1777_main(void);


/* Function definitions */
int64_t _1777_main(void){
    int64_t _1778_x;
    int64_t _1778_y;
    int64_t* _1777_t5;
    int64_t* _1777_t6;
    struct struct0 _1778_z;
    int64_t _1777_$retval;
    _1778_x = 30;
    _1778_y = 29;
    _1777_t5 = &_1778_x;
    _1777_t6 = &_1778_y;
    _1778_z = (struct struct0) {_1777_t5, _1777_t6};
    _1777_$retval = $add_int64_t(*_1778_z._0, *_1778_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1777_$retval;
}


int main(void) {
  printf("%ld",_1777_main());
  return 0;
}
