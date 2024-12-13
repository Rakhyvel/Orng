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
};

/* Function forward definitions */
int64_t _14_main(void);


/* Function definitions */
int64_t _14_main(void){
    int64_t _14_t1;
    int64_t _14_t2;
    int64_t _14_t3;
    int64_t _14_t4;
    struct struct0 _15_x;
    struct struct0* _15_y;
    int64_t _14_t9;
    int64_t _14_t10;
    int64_t _14_t11;
    int64_t _14_t12;
    int64_t _14_$retval;
    _14_t1 = 1;
    _14_t2 = 2;
    _14_t3 = 3;
    _14_t4 = 4;
    _15_x = (struct struct0) {_14_t1, _14_t2, _14_t3, _14_t4};
    _15_y = &_15_x;
    _14_t9 = 2;
    _14_t10 = 4;
    $bounds_check(_14_t9, _14_t10, "tests/integration/arrays/addr-array.orng:5:15:\n    y^[2] = 70\n             ^");
    *((int64_t*)_15_y + _14_t9) = 70;
    _14_t11 = 2;
    _14_t12 = 4;
    $bounds_check(_14_t11, _14_t12, "tests/integration/arrays/addr-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _14_$retval = *((int64_t*)_15_y + _14_t11);
    return _14_$retval;
}


int main(void) {
  printf("%ld",_14_main());
  return 0;
}
