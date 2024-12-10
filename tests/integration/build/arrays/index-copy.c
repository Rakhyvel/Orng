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
int64_t _79_main(void);


/* Function definitions */
int64_t _79_main(void){
    int64_t _79_t1;
    int64_t _79_t2;
    int64_t _79_t3;
    int64_t _79_t4;
    struct struct0 _80_x;
    int64_t _79_t7;
    int64_t _79_t8;
    int64_t _79_t9;
    int64_t _79_t10;
    int64_t _79_$retval;
    _79_t1 = 1;
    _79_t2 = 2;
    _79_t3 = 3;
    _79_t4 = 4;
    _80_x = (struct struct0) {_79_t1, _79_t2, _79_t3, _79_t4};
    _79_t7 = 2;
    _79_t8 = 4;
    $bounds_check(_79_t7, _79_t8, "tests/integration/arrays/index-copy.orng:4:14:\n    x[2] = 62\n            ^");
    *((int64_t*)&_80_x + _79_t7) = 62;
    _79_t9 = 2;
    _79_t10 = 4;
    $bounds_check(_79_t9, _79_t10, "tests/integration/arrays/index-copy.orng:2:8:\nfn main() -> Int {\n      ^");
    _79_$retval = *((int64_t*)&_80_x + _79_t9);
    return _79_$retval;
}


int main(void) {
  printf("%ld",_79_main());
  return 0;
}
