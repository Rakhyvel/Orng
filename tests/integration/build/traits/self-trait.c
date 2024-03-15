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
int64_t _1656_main(void);
int64_t _1649_cmp(void* _1649_$self_ptr, int64_t* _1649_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1656_main(void){
    int64_t _1657_x;
    int64_t _1657_y;
    int64_t* _1656_t6;
    int64_t* _1656_t7;
    function2 _1656_t8;
    int64_t _1656_t5;
    int64_t _1656_t9;
    uint8_t _1656_t11;
    int64_t _1656_$retval;
    _1657_x = 5;
    _1657_y = 6;
    _1656_t6 = &_1657_x;
    _1656_t7 = &_1657_y;
    _1656_t8 = (function2) _1649_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1656_t5 = _1656_t8(_1656_t6, _1656_t7);
    $line_idx--;
    _1656_t9 = 1;
    _1656_t11 = _1656_t5==_1656_t9;
    if (_1656_t11) {
        goto BB1857;
    } else {
        goto BB1861;
    }
BB1857:
    _1656_$retval = 301;
    return _1656_$retval;
BB1861:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1649_cmp(void* _1649_$self_ptr, int64_t* _1649_other){
    int64_t _1650_self;
    uint8_t _1649_t2;
    int64_t _1649_t1;
    int64_t _1649_t5;
    int64_t _1649_$retval;
    uint8_t _1649_t7;
    _1650_self = *(int64_t*)_1649_$self_ptr;
    _1649_t2 = _1650_self>*_1649_other;
    if (_1649_t2) {
        goto BB1841;
    } else {
        goto BB1845;
    }
BB1841:
    _1649_t1 = -1;
    goto BB1844;
BB1845:
    _1649_t7 = _1650_self==*_1649_other;
    if (_1649_t7) {
        goto BB1848;
    } else {
        goto BB1851;
    }
BB1844:
    _1649_$retval = _1649_t1;
    return _1649_$retval;
BB1848:
    _1649_t5 = 0;
    goto BB1850;
BB1851:
    _1649_t5 = 1;
    goto BB1850;
BB1850:
    _1649_t1 = _1649_t5;
    goto BB1844;
}


int main(void) {
  printf("%ld",_1656_main());
  return 0;
}
