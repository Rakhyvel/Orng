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
int64_t _10_main(void);


/* Function definitions */
int64_t _10_main(void){
    int64_t _10_t1;
    int64_t _10_t2;
    int64_t _10_t3;
    int64_t _10_t4;
    struct struct0 _11_x;
    struct struct0* _11_y;
    int64_t _10_t9;
    int64_t _10_t10;
    int64_t _10_t11;
    int64_t _10_t12;
    int64_t _10_$retval;
    _10_t1 = 1;
    _10_t2 = 2;
    _10_t3 = 3;
    _10_t4 = 4;
    _11_x = (struct struct0) {_10_t1, _10_t2, _10_t3, _10_t4};
    _11_y = &_11_x;
    _10_t9 = 2;
    _10_t10 = 4;
    $bounds_check(_10_t9, _10_t10, "tests/integration/arrays/addr-array.orng:5:15:\n    y^[2] = 70\n             ^");
    *((int64_t*)_11_y + _10_t9) = 70;
    _10_t11 = 2;
    _10_t12 = 4;
    $bounds_check(_10_t11, _10_t12, "tests/integration/arrays/addr-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _10_$retval = *((int64_t*)_11_y + _10_t11);
    return _10_$retval;
}


int main(void) {
  printf("%ld",_10_main());
  return 0;
}
