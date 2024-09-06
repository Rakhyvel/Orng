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
int64_t _1789_main(void);
int64_t _1782_cmp(void* _1782_$self_ptr, int64_t* _1782_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1789_main(void){
    int64_t _1790_x;
    int64_t _1790_y;
    int64_t* _1789_t6;
    int64_t* _1789_t7;
    function2 _1789_t8;
    int64_t _1789_t5;
    int64_t _1789_t9;
    uint8_t _1789_t11;
    int64_t _1789_$retval;
    _1790_x = 5;
    _1790_y = 6;
    _1789_t6 = &_1790_x;
    _1789_t7 = &_1790_y;
    _1789_t8 = (function2) _1782_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1789_t5 = _1789_t8(_1789_t6, _1789_t7);
    $line_idx--;
    _1789_t9 = 1;
    _1789_t11 = _1789_t5==_1789_t9;
    if (_1789_t11) {
        goto BB1958;
    } else {
        goto BB1962;
    }
BB1958:
    _1789_$retval = 301;
    return _1789_$retval;
BB1962:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1782_cmp(void* _1782_$self_ptr, int64_t* _1782_other){
    int64_t _1783_self;
    uint8_t _1782_t2;
    int64_t _1782_t1;
    int64_t _1782_t5;
    int64_t _1782_$retval;
    uint8_t _1782_t7;
    _1783_self = *(int64_t*)_1782_$self_ptr;
    _1782_t2 = _1783_self>*_1782_other;
    if (_1782_t2) {
        goto BB1942;
    } else {
        goto BB1946;
    }
BB1942:
    _1782_t1 = -1;
    goto BB1945;
BB1946:
    _1782_t7 = _1783_self==*_1782_other;
    if (_1782_t7) {
        goto BB1949;
    } else {
        goto BB1952;
    }
BB1945:
    _1782_$retval = _1782_t1;
    return _1782_$retval;
BB1949:
    _1782_t5 = 0;
    goto BB1951;
BB1952:
    _1782_t5 = 1;
    goto BB1951;
BB1951:
    _1782_t1 = _1782_t5;
    goto BB1945;
}


int main(void) {
  printf("%ld",_1789_main());
  return 0;
}
