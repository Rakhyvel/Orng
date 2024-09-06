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
int64_t _1754_main(void);
int64_t _1747_cmp(void* _1747_$self_ptr, int64_t* _1747_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1754_main(void){
    int64_t _1755_x;
    int64_t _1755_y;
    int64_t* _1754_t6;
    int64_t* _1754_t7;
    function2 _1754_t8;
    int64_t _1754_t5;
    int64_t _1754_t9;
    uint8_t _1754_t11;
    int64_t _1754_$retval;
    _1755_x = 5;
    _1755_y = 6;
    _1754_t6 = &_1755_x;
    _1754_t7 = &_1755_y;
    _1754_t8 = (function2) _1747_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1754_t5 = _1754_t8(_1754_t6, _1754_t7);
    $line_idx--;
    _1754_t9 = 1;
    _1754_t11 = _1754_t5==_1754_t9;
    if (_1754_t11) {
        goto BB1952;
    } else {
        goto BB1956;
    }
BB1952:
    _1754_$retval = 301;
    return _1754_$retval;
BB1956:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1747_cmp(void* _1747_$self_ptr, int64_t* _1747_other){
    int64_t _1748_self;
    uint8_t _1747_t2;
    int64_t _1747_t1;
    int64_t _1747_t5;
    int64_t _1747_$retval;
    uint8_t _1747_t7;
    _1748_self = *(int64_t*)_1747_$self_ptr;
    _1747_t2 = _1748_self>*_1747_other;
    if (_1747_t2) {
        goto BB1936;
    } else {
        goto BB1940;
    }
BB1936:
    _1747_t1 = -1;
    goto BB1939;
BB1940:
    _1747_t7 = _1748_self==*_1747_other;
    if (_1747_t7) {
        goto BB1943;
    } else {
        goto BB1946;
    }
BB1939:
    _1747_$retval = _1747_t1;
    return _1747_$retval;
BB1943:
    _1747_t5 = 0;
    goto BB1945;
BB1946:
    _1747_t5 = 1;
    goto BB1945;
BB1945:
    _1747_t1 = _1747_t5;
    goto BB1939;
}


int main(void) {
  printf("%ld",_1754_main());
  return 0;
}
