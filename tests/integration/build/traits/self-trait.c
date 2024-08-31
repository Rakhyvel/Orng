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
int64_t _1696_main(void);
int64_t _1689_cmp(void* _1689_$self_ptr, int64_t* _1689_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1696_main(void){
    int64_t _1697_x;
    int64_t _1697_y;
    int64_t* _1696_t6;
    int64_t* _1696_t7;
    function2 _1696_t8;
    int64_t _1696_t5;
    int64_t _1696_t9;
    uint8_t _1696_t11;
    int64_t _1696_$retval;
    _1697_x = 5;
    _1697_y = 6;
    _1696_t6 = &_1697_x;
    _1696_t7 = &_1697_y;
    _1696_t8 = (function2) _1689_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1696_t5 = _1696_t8(_1696_t6, _1696_t7);
    $line_idx--;
    _1696_t9 = 1;
    _1696_t11 = _1696_t5==_1696_t9;
    if (_1696_t11) {
        goto BB1883;
    } else {
        goto BB1887;
    }
BB1883:
    _1696_$retval = 301;
    return _1696_$retval;
BB1887:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1689_cmp(void* _1689_$self_ptr, int64_t* _1689_other){
    int64_t _1690_self;
    uint8_t _1689_t2;
    int64_t _1689_t1;
    int64_t _1689_t5;
    int64_t _1689_$retval;
    uint8_t _1689_t7;
    _1690_self = *(int64_t*)_1689_$self_ptr;
    _1689_t2 = _1690_self>*_1689_other;
    if (_1689_t2) {
        goto BB1867;
    } else {
        goto BB1871;
    }
BB1867:
    _1689_t1 = -1;
    goto BB1870;
BB1871:
    _1689_t7 = _1690_self==*_1689_other;
    if (_1689_t7) {
        goto BB1874;
    } else {
        goto BB1877;
    }
BB1870:
    _1689_$retval = _1689_t1;
    return _1689_$retval;
BB1874:
    _1689_t5 = 0;
    goto BB1876;
BB1877:
    _1689_t5 = 1;
    goto BB1876;
BB1876:
    _1689_t1 = _1689_t5;
    goto BB1870;
}


int main(void) {
  printf("%ld",_1696_main());
  return 0;
}
