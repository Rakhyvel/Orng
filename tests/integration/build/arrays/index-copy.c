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
int64_t _77_main(void);


/* Function definitions */
int64_t _77_main(void){
    int64_t _77_t1;
    int64_t _77_t2;
    int64_t _77_t3;
    int64_t _77_t4;
    struct struct0 _78_x;
    int64_t _77_t7;
    int64_t _77_t8;
    int64_t _77_t9;
    int64_t _77_t10;
    int64_t _77_$retval;
    _77_t1 = 1;
    _77_t2 = 2;
    _77_t3 = 3;
    _77_t4 = 4;
    _78_x = (struct struct0) {_77_t1, _77_t2, _77_t3, _77_t4};
    _77_t7 = 2;
    _77_t8 = 4;
    $bounds_check(_77_t7, _77_t8, "tests/integration/arrays/index-copy.orng:4:14:\n    x[2] = 62\n            ^");
    *((int64_t*)&_78_x + _77_t7) = 62;
    _77_t9 = 2;
    _77_t10 = 4;
    $bounds_check(_77_t9, _77_t10, "tests/integration/arrays/index-copy.orng:2:8:\nfn main() -> Int {\n      ^");
    _77_$retval = *((int64_t*)&_78_x + _77_t9);
    return _77_$retval;
}


int main(void) {
  printf("%ld",_77_main());
  return 0;
}
