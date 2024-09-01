/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    void* _1;
};

typedef int64_t(*function0)(void*, void*);

struct struct3 {
    int64_t* _0;
    int64_t* _1;
};

typedef int64_t(*function2)(int64_t*, int64_t*);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1735_main(void);
int64_t _1728_cmp(void* _1728_$self_ptr, int64_t* _1728_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1735_main(void){
    int64_t _1736_x;
    int64_t _1736_y;
    int64_t* _1735_t6;
    int64_t* _1735_t7;
    function2 _1735_t8;
    int64_t _1735_t5;
    int64_t _1735_t9;
    uint8_t _1735_t11;
    int64_t _1735_$retval;
    _1736_x = 5;
    _1736_y = 6;
    _1735_t6 = &_1736_x;
    _1735_t7 = &_1736_y;
    _1735_t8 = (function2) _1728_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1735_t5 = _1735_t8(_1735_t6, _1735_t7);
    $line_idx--;
    _1735_t9 = 1;
    _1735_t11 = _1735_t5==_1735_t9;
    if (_1735_t11) {
        goto BB1931;
    } else {
        goto BB1935;
    }
BB1931:
    _1735_$retval = 301;
    return _1735_$retval;
BB1935:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1728_cmp(void* _1728_$self_ptr, int64_t* _1728_other){
    int64_t _1729_self;
    uint8_t _1728_t2;
    int64_t _1728_t1;
    int64_t _1728_t5;
    int64_t _1728_$retval;
    uint8_t _1728_t7;
    _1729_self = *(int64_t*)_1728_$self_ptr;
    _1728_t2 = _1729_self>*_1728_other;
    if (_1728_t2) {
        goto BB1915;
    } else {
        goto BB1919;
    }
BB1915:
    _1728_t1 = -1;
    goto BB1918;
BB1919:
    _1728_t7 = _1729_self==*_1728_other;
    if (_1728_t7) {
        goto BB1922;
    } else {
        goto BB1925;
    }
BB1918:
    _1728_$retval = _1728_t1;
    return _1728_$retval;
BB1922:
    _1728_t5 = 0;
    goto BB1924;
BB1925:
    _1728_t5 = 1;
    goto BB1924;
BB1924:
    _1728_t1 = _1728_t5;
    goto BB1918;
}


int main(void) {
  printf("%ld",_1735_main());
  return 0;
}
