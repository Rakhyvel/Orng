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
int64_t _1690_main(void);
int64_t _1683_cmp(void* _1683_$self_ptr, int64_t* _1683_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1690_main(void){
    int64_t _1691_x;
    int64_t _1691_y;
    int64_t* _1690_t6;
    int64_t* _1690_t7;
    function2 _1690_t8;
    int64_t _1690_t5;
    int64_t _1690_t9;
    uint8_t _1690_t11;
    int64_t _1690_$retval;
    _1691_x = 5;
    _1691_y = 6;
    _1690_t6 = &_1691_x;
    _1690_t7 = &_1691_y;
    _1690_t8 = (function2) _1683_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1690_t5 = _1690_t8(_1690_t6, _1690_t7);
    $line_idx--;
    _1690_t9 = 1;
    _1690_t11 = _1690_t5==_1690_t9;
    if (_1690_t11) {
        goto BB1910;
    } else {
        goto BB1914;
    }
BB1910:
    _1690_$retval = 301;
    return _1690_$retval;
BB1914:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1683_cmp(void* _1683_$self_ptr, int64_t* _1683_other){
    int64_t _1684_self;
    uint8_t _1683_t2;
    int64_t _1683_t1;
    int64_t _1683_t5;
    int64_t _1683_$retval;
    uint8_t _1683_t7;
    _1684_self = *(int64_t*)_1683_$self_ptr;
    _1683_t2 = _1684_self>*_1683_other;
    if (_1683_t2) {
        goto BB1894;
    } else {
        goto BB1898;
    }
BB1894:
    _1683_t1 = -1;
    goto BB1897;
BB1898:
    _1683_t7 = _1684_self==*_1683_other;
    if (_1683_t7) {
        goto BB1901;
    } else {
        goto BB1904;
    }
BB1897:
    _1683_$retval = _1683_t1;
    return _1683_$retval;
BB1901:
    _1683_t5 = 0;
    goto BB1903;
BB1904:
    _1683_t5 = 1;
    goto BB1903;
BB1903:
    _1683_t1 = _1683_t5;
    goto BB1897;
}


int main(void) {
  printf("%ld",_1690_main());
  return 0;
}
