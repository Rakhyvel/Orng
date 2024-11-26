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
uint32_t _68_main(void);


/* Function definitions */
uint32_t _68_main(void){
    uint32_t _68_t1;
    uint32_t _68_t2;
    uint32_t _68_t3;
    uint32_t _68_t4;
    struct struct0 _69_x;
    int64_t _68_t6;
    int64_t _68_t7;
    uint32_t _68_$retval;
    _68_t1 = 49;
    _68_t2 = 50;
    _68_t3 = 51;
    _68_t4 = 52;
    _69_x = (struct struct0) {_68_t1, _68_t2, _68_t3, _68_t4};
    _68_t6 = 3;
    _68_t7 = 4;
    $bounds_check(_68_t6, _68_t7, "tests/integration/generics/templated-arr.orng:4:8:\nfn main() -> Char {\n      ^");
    _68_$retval = *((uint32_t*)&_69_x + _68_t6);
    return _68_$retval;
}


int main(void) {
  printf("%u",_68_main());
  return 0;
}
