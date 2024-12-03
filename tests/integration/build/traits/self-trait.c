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
int64_t _1797_main(void);
int64_t _1790_cmp(void* _1790_$self_ptr, int64_t* _1790_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1797_main(void){
    int64_t _1798_x;
    int64_t _1798_y;
    int64_t* _1797_t6;
    int64_t* _1797_t7;
    function2 _1797_t8;
    int64_t _1797_t5;
    int64_t _1797_t9;
    uint8_t _1797_t11;
    int64_t _1797_$retval;
    _1798_x = 5;
    _1798_y = 6;
    _1797_t6 = &_1798_x;
    _1797_t7 = &_1798_y;
    _1797_t8 = (function2) _1790_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1797_t5 = _1797_t8(_1797_t6, _1797_t7);
    $line_idx--;
    _1797_t9 = 1;
    _1797_t11 = _1797_t5==_1797_t9;
    if (_1797_t11) {
        goto BB1964;
    } else {
        goto BB1968;
    }
BB1964:
    _1797_$retval = 301;
    return _1797_$retval;
BB1968:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1790_cmp(void* _1790_$self_ptr, int64_t* _1790_other){
    int64_t _1791_self;
    uint8_t _1790_t2;
    int64_t _1790_t1;
    int64_t _1790_t5;
    int64_t _1790_$retval;
    uint8_t _1790_t7;
    _1791_self = *(int64_t*)_1790_$self_ptr;
    _1790_t2 = _1791_self>*_1790_other;
    if (_1790_t2) {
        goto BB1948;
    } else {
        goto BB1952;
    }
BB1948:
    _1790_t1 = -1;
    goto BB1951;
BB1952:
    _1790_t7 = _1791_self==*_1790_other;
    if (_1790_t7) {
        goto BB1955;
    } else {
        goto BB1958;
    }
BB1951:
    _1790_$retval = _1790_t1;
    return _1790_$retval;
BB1955:
    _1790_t5 = 0;
    goto BB1957;
BB1958:
    _1790_t5 = 1;
    goto BB1957;
BB1957:
    _1790_t1 = _1790_t5;
    goto BB1951;
}


int main(void) {
  printf("%ld",_1797_main());
  return 0;
}
