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
int64_t _71_main(void);


/* Function definitions */
int64_t _71_main(void){
    int64_t _71_t1;
    int64_t _71_t2;
    int64_t _71_t3;
    int64_t _71_t4;
    int64_t _71_t5;
    struct struct0 _72_x;
    struct struct0* _72_y;
    int64_t _71_t9;
    int64_t _71_t10;
    int64_t _71_t11;
    int64_t _71_$retval;
    _71_t1 = 1;
    _71_t2 = 2;
    _71_t3 = 3;
    _71_t4 = 4;
    _71_t5 = 5;
    _72_x = (struct struct0) {_71_t1, _71_t2, _71_t3, _71_t4, _71_t5};
    _72_y = &_72_x;
    _71_t9 = 2;
    _71_t10 = 5;
    _71_t11 = 77;
    $bounds_check(_71_t9, _71_t10, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    _71_$retval = $add_int64_t(*((int64_t*)_72_y + _71_t9), _71_t11, "tests/integration/arrays/implicit-deref.orng:5:11:\n    y[2] + 77\n         ^");
    return _71_$retval;
}


int main(void) {
  printf("%ld",_71_main());
  return 0;
}
