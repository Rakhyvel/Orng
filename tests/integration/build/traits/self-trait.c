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
int64_t _1782_main(void);
int64_t _1775_cmp(void* _1775_$self_ptr, int64_t* _1775_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1782_main(void){
    int64_t _1783_x;
    int64_t _1783_y;
    int64_t* _1782_t6;
    int64_t* _1782_t7;
    function2 _1782_t8;
    int64_t _1782_t5;
    int64_t _1782_t9;
    uint8_t _1782_t11;
    int64_t _1782_$retval;
    _1783_x = 5;
    _1783_y = 6;
    _1782_t6 = &_1783_x;
    _1782_t7 = &_1783_y;
    _1782_t8 = (function2) _1775_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1782_t5 = _1782_t8(_1782_t6, _1782_t7);
    $line_idx--;
    _1782_t9 = 1;
    _1782_t11 = _1782_t5==_1782_t9;
    if (_1782_t11) {
        goto BB1956;
    } else {
        goto BB1960;
    }
BB1956:
    _1782_$retval = 301;
    return _1782_$retval;
BB1960:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1775_cmp(void* _1775_$self_ptr, int64_t* _1775_other){
    int64_t _1776_self;
    uint8_t _1775_t2;
    int64_t _1775_t1;
    int64_t _1775_t5;
    int64_t _1775_$retval;
    uint8_t _1775_t7;
    _1776_self = *(int64_t*)_1775_$self_ptr;
    _1775_t2 = _1776_self>*_1775_other;
    if (_1775_t2) {
        goto BB1940;
    } else {
        goto BB1944;
    }
BB1940:
    _1775_t1 = -1;
    goto BB1943;
BB1944:
    _1775_t7 = _1776_self==*_1775_other;
    if (_1775_t7) {
        goto BB1947;
    } else {
        goto BB1950;
    }
BB1943:
    _1775_$retval = _1775_t1;
    return _1775_$retval;
BB1947:
    _1775_t5 = 0;
    goto BB1949;
BB1950:
    _1775_t5 = 1;
    goto BB1949;
BB1949:
    _1775_t1 = _1775_t5;
    goto BB1943;
}


int main(void) {
  printf("%ld",_1782_main());
  return 0;
}
