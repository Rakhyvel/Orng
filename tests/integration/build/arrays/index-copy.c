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
int64_t _72_main(void);


/* Function definitions */
int64_t _72_main(void){
    int64_t _72_t1;
    int64_t _72_t2;
    int64_t _72_t3;
    int64_t _72_t4;
    struct struct0 _73_x;
    int64_t _72_t7;
    int64_t _72_t8;
    int64_t _72_t9;
    int64_t _72_t10;
    int64_t _72_$retval;
    _72_t1 = 1;
    _72_t2 = 2;
    _72_t3 = 3;
    _72_t4 = 4;
    _73_x = (struct struct0) {_72_t1, _72_t2, _72_t3, _72_t4};
    _72_t7 = 2;
    _72_t8 = 4;
    $bounds_check(_72_t7, _72_t8, "tests/integration/arrays/index-copy.orng:4:14:\n    x[2] = 62\n            ^");
    *((int64_t*)&_73_x + _72_t7) = 62;
    _72_t9 = 2;
    _72_t10 = 4;
    $bounds_check(_72_t9, _72_t10, "tests/integration/arrays/index-copy.orng:2:8:\nfn main() -> Int {\n      ^");
    _72_$retval = *((int64_t*)&_73_x + _72_t9);
    return _72_$retval;
}


int main(void) {
  printf("%ld",_72_main());
  return 0;
}
