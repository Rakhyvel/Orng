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
int64_t _1817_main(void);
int64_t _1810_cmp(void* _1810_$self_ptr, int64_t* _1810_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1817_main(void){
    int64_t _1818_x;
    int64_t _1818_y;
    int64_t* _1817_t6;
    int64_t* _1817_t7;
    function2 _1817_t8;
    int64_t _1817_t5;
    int64_t _1817_t9;
    uint8_t _1817_t11;
    int64_t _1817_$retval;
    _1818_x = 5;
    _1818_y = 6;
    _1817_t6 = &_1818_x;
    _1817_t7 = &_1818_y;
    _1817_t8 = (function2) _1810_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1817_t5 = _1817_t8(_1817_t6, _1817_t7);
    $line_idx--;
    _1817_t9 = 1;
    _1817_t11 = _1817_t5==_1817_t9;
    if (_1817_t11) {
        goto BB1986;
    } else {
        goto BB1990;
    }
BB1986:
    _1817_$retval = 301;
    return _1817_$retval;
BB1990:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1810_cmp(void* _1810_$self_ptr, int64_t* _1810_other){
    int64_t _1811_self;
    uint8_t _1810_t2;
    int64_t _1810_t1;
    int64_t _1810_t5;
    int64_t _1810_$retval;
    uint8_t _1810_t7;
    _1811_self = *(int64_t*)_1810_$self_ptr;
    _1810_t2 = _1811_self>*_1810_other;
    if (_1810_t2) {
        goto BB1970;
    } else {
        goto BB1974;
    }
BB1970:
    _1810_t1 = -1;
    goto BB1973;
BB1974:
    _1810_t7 = _1811_self==*_1810_other;
    if (_1810_t7) {
        goto BB1977;
    } else {
        goto BB1980;
    }
BB1973:
    _1810_$retval = _1810_t1;
    return _1810_$retval;
BB1977:
    _1810_t5 = 0;
    goto BB1979;
BB1980:
    _1810_t5 = 1;
    goto BB1979;
BB1979:
    _1810_t1 = _1810_t5;
    goto BB1973;
}


int main(void) {
  printf("%ld",_1817_main());
  return 0;
}
