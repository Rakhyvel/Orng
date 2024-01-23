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
    int64_t _2;
    int64_t _3;
    int64_t _4;
};

/* Function forward definitions */
int64_t _64_main(void);


/* Function definitions */
int64_t _64_main(void){
    int64_t _64_t1;
    int64_t _64_t2;
    int64_t _64_t3;
    int64_t _64_t4;
    int64_t _64_t5;
    struct struct0 _65_x;
    struct struct0* _65_y;
    int64_t _64_t7;
    int64_t _64_t8;
    int64_t _64_t9;
    int64_t _64_$retval;
    _64_t1 = 1;
    _64_t2 = 2;
    _64_t3 = 3;
    _64_t4 = 4;
    _64_t5 = 5;
    _65_x = (struct struct0) {_64_t1, _64_t2, _64_t3, _64_t4, _64_t5};
    _65_y = &_65_x;
    _64_t7 = 2;
    _64_t8 = 5;
    _64_t9 = 77;
    $bounds_check(_64_t7, _64_t8, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    _64_$retval = $add_int64_t(*((int64_t*)_65_y + _64_t7), _64_t9, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _64_$retval;
}


int main(void) {
  printf("%ld",_64_main());
  return 0;
}
