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
};

struct struct1 {
    struct struct0 _0;
    struct struct0 _1;
    struct struct0 _2;
};

/* Function forward definitions */
int64_t _51_main(void);


/* Function definitions */
int64_t _51_main(void){
    int64_t _51_t2;
    int64_t _51_t3;
    struct struct0 _51_t1;
    int64_t _51_t5;
    int64_t _51_t6;
    struct struct0 _51_t4;
    int64_t _51_t8;
    int64_t _51_t9;
    struct struct0 _51_t7;
    struct struct1 _52_x;
    int64_t _51_t12;
    int64_t _51_t13;
    int64_t _51_t14;
    int64_t _51_t15;
    int64_t _51_$retval;
    _51_t2 = 1;
    _51_t3 = 2;
    _51_t1 = (struct struct0) {_51_t2, _51_t3};
    _51_t5 = 3;
    _51_t6 = 4;
    _51_t4 = (struct struct0) {_51_t5, _51_t6};
    _51_t8 = 5;
    _51_t9 = 6;
    _51_t7 = (struct struct0) {_51_t8, _51_t9};
    _52_x = (struct struct1) {_51_t1, _51_t4, _51_t7};
    _51_t12 = 1;
    _51_t13 = 3;
    $bounds_check(_51_t12, _51_t13, "tests/integration/arrays/array-select.orng:7:16:\n    x[1].a = 73\n              ^");
    (*((struct struct0*)&_52_x + _51_t12))._0 = 73;
    _51_t14 = 1;
    _51_t15 = 3;
    $bounds_check(_51_t14, _51_t15, "tests/integration/arrays/array-select.orng:2:8:\nfn main() -> Int {\n      ^");
    _51_$retval = (*((struct struct0*)&_52_x + _51_t14))._0;
    return _51_$retval;
}


int main(void) {
  printf("%ld",_51_main());
  return 0;
}
