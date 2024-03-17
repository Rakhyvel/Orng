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
int64_t _1668_main(void);
int64_t _1661_cmp(void* _1661_$self_ptr, int64_t* _1661_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1668_main(void){
    int64_t _1669_x;
    int64_t _1669_y;
    int64_t* _1668_t6;
    int64_t* _1668_t7;
    function2 _1668_t8;
    int64_t _1668_t5;
    int64_t _1668_t9;
    uint8_t _1668_t11;
    int64_t _1668_$retval;
    _1669_x = 5;
    _1669_y = 6;
    _1668_t6 = &_1669_x;
    _1668_t7 = &_1669_y;
    _1668_t8 = (function2) _1661_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1668_t5 = _1668_t8(_1668_t6, _1668_t7);
    $line_idx--;
    _1668_t9 = 1;
    _1668_t11 = _1668_t5==_1668_t9;
    if (_1668_t11) {
        goto BB1863;
    } else {
        goto BB1867;
    }
BB1863:
    _1668_$retval = 301;
    return _1668_$retval;
BB1867:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1661_cmp(void* _1661_$self_ptr, int64_t* _1661_other){
    int64_t _1662_self;
    uint8_t _1661_t2;
    int64_t _1661_t1;
    int64_t _1661_t5;
    int64_t _1661_$retval;
    uint8_t _1661_t7;
    _1662_self = *(int64_t*)_1661_$self_ptr;
    _1661_t2 = _1662_self>*_1661_other;
    if (_1661_t2) {
        goto BB1847;
    } else {
        goto BB1851;
    }
BB1847:
    _1661_t1 = -1;
    goto BB1850;
BB1851:
    _1661_t7 = _1662_self==*_1661_other;
    if (_1661_t7) {
        goto BB1854;
    } else {
        goto BB1857;
    }
BB1850:
    _1661_$retval = _1661_t1;
    return _1661_$retval;
BB1854:
    _1661_t5 = 0;
    goto BB1856;
BB1857:
    _1661_t5 = 1;
    goto BB1856;
BB1856:
    _1661_t1 = _1661_t5;
    goto BB1850;
}


int main(void) {
  printf("%ld",_1668_main());
  return 0;
}
