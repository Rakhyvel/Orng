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
int64_t _1788_main(void);


/* Function definitions */
int64_t _1788_main(void){
    int64_t _1789_x;
    int64_t _1789_y;
    int64_t* _1788_t5;
    int64_t* _1788_t6;
    struct struct0 _1789_z;
    int64_t _1788_$retval;
    _1789_x = 30;
    _1789_y = 29;
    _1788_t5 = &_1789_x;
    _1788_t6 = &_1789_y;
    _1789_z = (struct struct0) {_1788_t5, _1788_t6};
    _1788_$retval = $add_int64_t(*_1789_z._0, *_1789_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1788_$retval;
}


int main(void) {
  printf("%ld",_1788_main());
  return 0;
}
