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
    uint32_t _0;
    uint32_t _1;
    uint32_t _2;
    uint32_t _3;
};

/* Function forward definitions */
uint32_t _1078_main(void);


/* Function definitions */
uint32_t _1078_main(void){
    uint32_t _1078_t1;
    uint32_t _1078_t2;
    uint32_t _1078_t3;
    uint32_t _1078_t4;
    struct struct0 _1079_x;
    int64_t _1078_t6;
    int64_t _1078_t7;
    uint32_t _1078_$retval;
    _1078_t1 = 49;
    _1078_t2 = 50;
    _1078_t3 = 51;
    _1078_t4 = 52;
    _1079_x = (struct struct0) {_1078_t1, _1078_t2, _1078_t3, _1078_t4};
    _1078_t6 = 3;
    _1078_t7 = 4;
    $bounds_check(_1078_t6, _1078_t7, "tests/integration/generics/templated-arr.orng:4:8:\nfn main() -> Char {\n      ^");
    _1078_$retval = *((uint32_t*)&_1079_x + _1078_t6);
    return _1078_$retval;
}


int main(void) {
  printf("%u",_1078_main());
  return 0;
}
