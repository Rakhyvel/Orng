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
int64_t _1682_main(void);
int64_t _1675_cmp(void* _1675_$self_ptr, int64_t* _1675_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1682_main(void){
    int64_t _1683_x;
    int64_t _1683_y;
    int64_t* _1682_t6;
    int64_t* _1682_t7;
    function2 _1682_t8;
    int64_t _1682_t5;
    int64_t _1682_t9;
    uint8_t _1682_t11;
    int64_t _1682_$retval;
    _1683_x = 5;
    _1683_y = 6;
    _1682_t6 = &_1683_x;
    _1682_t7 = &_1683_y;
    _1682_t8 = (function2) _1675_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1682_t5 = _1682_t8(_1682_t6, _1682_t7);
    $line_idx--;
    _1682_t9 = 1;
    _1682_t11 = _1682_t5==_1682_t9;
    if (_1682_t11) {
        goto BB1873;
    } else {
        goto BB1877;
    }
BB1873:
    _1682_$retval = 301;
    return _1682_$retval;
BB1877:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1675_cmp(void* _1675_$self_ptr, int64_t* _1675_other){
    int64_t _1676_self;
    uint8_t _1675_t2;
    int64_t _1675_t1;
    int64_t _1675_t5;
    int64_t _1675_$retval;
    uint8_t _1675_t7;
    _1676_self = *(int64_t*)_1675_$self_ptr;
    _1675_t2 = _1676_self>*_1675_other;
    if (_1675_t2) {
        goto BB1857;
    } else {
        goto BB1861;
    }
BB1857:
    _1675_t1 = -1;
    goto BB1860;
BB1861:
    _1675_t7 = _1676_self==*_1675_other;
    if (_1675_t7) {
        goto BB1864;
    } else {
        goto BB1867;
    }
BB1860:
    _1675_$retval = _1675_t1;
    return _1675_$retval;
BB1864:
    _1675_t5 = 0;
    goto BB1866;
BB1867:
    _1675_t5 = 1;
    goto BB1866;
BB1866:
    _1675_t1 = _1675_t5;
    goto BB1860;
}


int main(void) {
  printf("%ld",_1682_main());
  return 0;
}
