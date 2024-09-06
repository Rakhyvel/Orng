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
int64_t _1792_main(void);
int64_t _1785_cmp(void* _1785_$self_ptr, int64_t* _1785_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1792_main(void){
    int64_t _1793_x;
    int64_t _1793_y;
    int64_t* _1792_t6;
    int64_t* _1792_t7;
    function2 _1792_t8;
    int64_t _1792_t5;
    int64_t _1792_t9;
    uint8_t _1792_t11;
    int64_t _1792_$retval;
    _1793_x = 5;
    _1793_y = 6;
    _1792_t6 = &_1793_x;
    _1792_t7 = &_1793_y;
    _1792_t8 = (function2) _1785_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1792_t5 = _1792_t8(_1792_t6, _1792_t7);
    $line_idx--;
    _1792_t9 = 1;
    _1792_t11 = _1792_t5==_1792_t9;
    if (_1792_t11) {
        goto BB1960;
    } else {
        goto BB1964;
    }
BB1960:
    _1792_$retval = 301;
    return _1792_$retval;
BB1964:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1785_cmp(void* _1785_$self_ptr, int64_t* _1785_other){
    int64_t _1786_self;
    uint8_t _1785_t2;
    int64_t _1785_t1;
    int64_t _1785_t5;
    int64_t _1785_$retval;
    uint8_t _1785_t7;
    _1786_self = *(int64_t*)_1785_$self_ptr;
    _1785_t2 = _1786_self>*_1785_other;
    if (_1785_t2) {
        goto BB1944;
    } else {
        goto BB1948;
    }
BB1944:
    _1785_t1 = -1;
    goto BB1947;
BB1948:
    _1785_t7 = _1786_self==*_1785_other;
    if (_1785_t7) {
        goto BB1951;
    } else {
        goto BB1954;
    }
BB1947:
    _1785_$retval = _1785_t1;
    return _1785_$retval;
BB1951:
    _1785_t5 = 0;
    goto BB1953;
BB1954:
    _1785_t5 = 1;
    goto BB1953;
BB1953:
    _1785_t1 = _1785_t5;
    goto BB1947;
}


int main(void) {
  printf("%ld",_1792_main());
  return 0;
}
