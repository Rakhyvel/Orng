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
int64_t _55_main(void);


/* Function definitions */
int64_t _55_main(void){
    int64_t _55_t1;
    int64_t _55_t2;
    int64_t _55_t3;
    int64_t _55_t4;
    int64_t _55_t5;
    struct struct0 _56_x;
    struct struct0* _56_y;
    int64_t _55_t9;
    int64_t _55_t10;
    int64_t _55_t11;
    int64_t _55_$retval;
    _55_t1 = 1;
    _55_t2 = 2;
    _55_t3 = 3;
    _55_t4 = 4;
    _55_t5 = 5;
    _56_x = (struct struct0) {_55_t1, _55_t2, _55_t3, _55_t4, _55_t5};
    _56_y = &_56_x;
    _55_t9 = 2;
    _55_t10 = 5;
    _55_t11 = 77;
    $bounds_check(_55_t9, _55_t10, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    _55_$retval = $add_int64_t(*((int64_t*)_56_y + _55_t9), _55_t11, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _55_$retval;
}


int main(void) {
  printf("%ld",_55_main());
  return 0;
}
