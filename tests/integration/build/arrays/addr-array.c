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
int64_t _12_main(void);


/* Function definitions */
int64_t _12_main(void){
    int64_t _12_t1;
    int64_t _12_t2;
    int64_t _12_t3;
    int64_t _12_t4;
    struct struct0 _13_x;
    struct struct0* _13_y;
    int64_t _12_t9;
    int64_t _12_t10;
    int64_t _12_t11;
    int64_t _12_t12;
    int64_t _12_$retval;
    _12_t1 = 1;
    _12_t2 = 2;
    _12_t3 = 3;
    _12_t4 = 4;
    _13_x = (struct struct0) {_12_t1, _12_t2, _12_t3, _12_t4};
    _13_y = &_13_x;
    _12_t9 = 2;
    _12_t10 = 4;
    $bounds_check(_12_t9, _12_t10, "tests/integration/arrays/addr-array.orng:5:15:\n    y^[2] = 70\n             ^");
    *((int64_t*)_13_y + _12_t9) = 70;
    _12_t11 = 2;
    _12_t12 = 4;
    $bounds_check(_12_t11, _12_t12, "tests/integration/arrays/addr-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _12_$retval = *((int64_t*)_13_y + _12_t11);
    return _12_$retval;
}


int main(void) {
  printf("%ld",_12_main());
  return 0;
}
