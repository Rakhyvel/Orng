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
int64_t _1803_main(void);
int64_t _1796_cmp(void* _1796_$self_ptr, int64_t* _1796_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1803_main(void){
    int64_t _1804_x;
    int64_t _1804_y;
    int64_t* _1803_t6;
    int64_t* _1803_t7;
    function2 _1803_t8;
    int64_t _1803_t5;
    int64_t _1803_t9;
    uint8_t _1803_t11;
    int64_t _1803_$retval;
    _1804_x = 5;
    _1804_y = 6;
    _1803_t6 = &_1804_x;
    _1803_t7 = &_1804_y;
    _1803_t8 = (function2) _1796_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1803_t5 = _1803_t8(_1803_t6, _1803_t7);
    $line_idx--;
    _1803_t9 = 1;
    _1803_t11 = _1803_t5==_1803_t9;
    if (_1803_t11) {
        goto BB1967;
    } else {
        goto BB1971;
    }
BB1967:
    _1803_$retval = 301;
    return _1803_$retval;
BB1971:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1796_cmp(void* _1796_$self_ptr, int64_t* _1796_other){
    int64_t _1797_self;
    uint8_t _1796_t2;
    int64_t _1796_t1;
    int64_t _1796_t5;
    int64_t _1796_$retval;
    uint8_t _1796_t7;
    _1797_self = *(int64_t*)_1796_$self_ptr;
    _1796_t2 = _1797_self>*_1796_other;
    if (_1796_t2) {
        goto BB1951;
    } else {
        goto BB1955;
    }
BB1951:
    _1796_t1 = -1;
    goto BB1954;
BB1955:
    _1796_t7 = _1797_self==*_1796_other;
    if (_1796_t7) {
        goto BB1958;
    } else {
        goto BB1961;
    }
BB1954:
    _1796_$retval = _1796_t1;
    return _1796_$retval;
BB1958:
    _1796_t5 = 0;
    goto BB1960;
BB1961:
    _1796_t5 = 1;
    goto BB1960;
BB1960:
    _1796_t1 = _1796_t5;
    goto BB1954;
}


int main(void) {
  printf("%ld",_1803_main());
  return 0;
}
