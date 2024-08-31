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
int64_t _1793_main(void);


/* Function definitions */
int64_t _1793_main(void){
    int64_t _1794_x;
    int64_t _1794_y;
    int64_t* _1793_t5;
    int64_t* _1793_t6;
    struct struct0 _1794_z;
    int64_t _1793_$retval;
    _1794_x = 30;
    _1794_y = 29;
    _1793_t5 = &_1794_x;
    _1793_t6 = &_1794_y;
    _1794_z = (struct struct0) {_1793_t5, _1793_t6};
    _1793_$retval = $add_int64_t(*_1794_z._0, *_1794_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1793_$retval;
}


int main(void) {
  printf("%ld",_1793_main());
  return 0;
}
