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
int64_t _1691_main(void);
int64_t _1684_cmp(void* _1684_$self_ptr, int64_t* _1684_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1691_main(void){
    int64_t _1692_x;
    int64_t _1692_y;
    int64_t* _1691_t6;
    int64_t* _1691_t7;
    function2 _1691_t8;
    int64_t _1691_t5;
    int64_t _1691_t9;
    uint8_t _1691_t11;
    int64_t _1691_$retval;
    _1692_x = 5;
    _1692_y = 6;
    _1691_t6 = &_1692_x;
    _1691_t7 = &_1692_y;
    _1691_t8 = (function2) _1684_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1691_t5 = _1691_t8(_1691_t6, _1691_t7);
    $line_idx--;
    _1691_t9 = 1;
    _1691_t11 = _1691_t5==_1691_t9;
    if (_1691_t11) {
        goto BB1879;
    } else {
        goto BB1883;
    }
BB1879:
    _1691_$retval = 301;
    return _1691_$retval;
BB1883:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1684_cmp(void* _1684_$self_ptr, int64_t* _1684_other){
    int64_t _1685_self;
    uint8_t _1684_t2;
    int64_t _1684_t1;
    int64_t _1684_t5;
    int64_t _1684_$retval;
    uint8_t _1684_t7;
    _1685_self = *(int64_t*)_1684_$self_ptr;
    _1684_t2 = _1685_self>*_1684_other;
    if (_1684_t2) {
        goto BB1863;
    } else {
        goto BB1867;
    }
BB1863:
    _1684_t1 = -1;
    goto BB1866;
BB1867:
    _1684_t7 = _1685_self==*_1684_other;
    if (_1684_t7) {
        goto BB1870;
    } else {
        goto BB1873;
    }
BB1866:
    _1684_$retval = _1684_t1;
    return _1684_$retval;
BB1870:
    _1684_t5 = 0;
    goto BB1872;
BB1873:
    _1684_t5 = 1;
    goto BB1872;
BB1872:
    _1684_t1 = _1684_t5;
    goto BB1866;
}


int main(void) {
  printf("%ld",_1691_main());
  return 0;
}
