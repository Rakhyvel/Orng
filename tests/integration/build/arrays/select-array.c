/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
};

/* Function forward definitions */
int64_t _74_main(void);


/* Function definitions */
int64_t _74_main(void){
    int64_t _74_t2;
    int64_t _74_t3;
    int64_t _74_t4;
    struct struct0 _74_t1;
    int64_t _74_t6;
    int64_t _74_t7;
    int64_t _74_t8;
    struct struct0 _74_t5;
    struct struct1 _75_x;
    int64_t _74_t11;
    int64_t _74_t12;
    int64_t _74_t13;
    int64_t _74_t14;
    int64_t _74_$retval;
    _74_t2 = 1;
    _74_t3 = 2;
    _74_t4 = 3;
    _74_t1 = (struct struct0) {_74_t2, _74_t3, _74_t4};
    _74_t6 = 4;
    _74_t7 = 5;
    _74_t8 = 6;
    _74_t5 = (struct struct0) {_74_t6, _74_t7, _74_t8};
    _75_x = (struct struct1) {_74_t1, _74_t5};
    _74_t11 = 1;
    _74_t12 = 3;
    $bounds_check(_74_t11, _74_t12, "tests/integration/arrays/select-array.orng:4:16:\n    x.a[1] = 72\n              ^");
    *((int64_t*)&_75_x._0 + _74_t11) = 72;
    _74_t13 = 1;
    _74_t14 = 3;
    $bounds_check(_74_t13, _74_t14, "tests/integration/arrays/select-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _74_$retval = *((int64_t*)&_75_x._0 + _74_t13);
    return _74_$retval;
}


int main(void) {
  printf("%ld",_74_main());
  return 0;
}
