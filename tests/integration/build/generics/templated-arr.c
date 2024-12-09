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
uint32_t _1102_main(void);


/* Function definitions */
uint32_t _1102_main(void){
    uint32_t _1102_t1;
    uint32_t _1102_t2;
    uint32_t _1102_t3;
    uint32_t _1102_t4;
    struct struct0 _1103_x;
    int64_t _1102_t6;
    int64_t _1102_t7;
    uint32_t _1102_$retval;
    _1102_t1 = 49;
    _1102_t2 = 50;
    _1102_t3 = 51;
    _1102_t4 = 52;
    _1103_x = (struct struct0) {_1102_t1, _1102_t2, _1102_t3, _1102_t4};
    _1102_t6 = 3;
    _1102_t7 = 4;
    $bounds_check(_1102_t6, _1102_t7, "tests/integration/generics/templated-arr.orng:4:8:\nfn main() -> Char {\n      ^");
    _1102_$retval = *((uint32_t*)&_1103_x + _1102_t6);
    return _1102_$retval;
}


int main(void) {
  printf("%u",_1102_main());
  return 0;
}
