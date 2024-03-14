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
int64_t _5_main(void);


/* Function definitions */
int64_t _5_main(void){
    int64_t _5_t1;
    int64_t _5_t2;
    int64_t _5_t3;
    int64_t _5_t4;
    struct struct0 _6_x;
    struct struct0* _6_y;
    int64_t _5_t9;
    int64_t _5_t10;
    int64_t _5_t11;
    int64_t _5_t12;
    int64_t _5_$retval;
    _5_t1 = 1;
    _5_t2 = 2;
    _5_t3 = 3;
    _5_t4 = 4;
    _6_x = (struct struct0) {_5_t1, _5_t2, _5_t3, _5_t4};
    _6_y = &_6_x;
    _5_t9 = 2;
    _5_t10 = 4;
    $bounds_check(_5_t9, _5_t10, "tests/integration/arrays/addr-array.orng:5:15:\n    y^[2] = 70\n             ^");
    *((int64_t*)_6_y + _5_t9) = 70;
    _5_t11 = 2;
    _5_t12 = 4;
    $bounds_check(_5_t11, _5_t12, "tests/integration/arrays/addr-array.orng:2:3:\nfn main() -> Int {\n ^");
    _5_$retval = *((int64_t*)_6_y + _5_t11);
    return _5_$retval;
}


int main(void) {
  printf("%ld",_5_main());
  return 0;
}
