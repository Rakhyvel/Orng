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
int64_t _1822_main(void);
int64_t _1815_cmp(void* _1815_$self_ptr, int64_t* _1815_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1822_main(void){
    int64_t _1823_x;
    int64_t _1823_y;
    int64_t* _1822_t6;
    int64_t* _1822_t7;
    function2 _1822_t8;
    int64_t _1822_t5;
    int64_t _1822_t9;
    uint8_t _1822_t11;
    int64_t _1822_$retval;
    _1823_x = 5;
    _1823_y = 6;
    _1822_t6 = &_1823_x;
    _1822_t7 = &_1823_y;
    _1822_t8 = (function2) _1815_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1822_t5 = _1822_t8(_1822_t6, _1822_t7);
    $line_idx--;
    _1822_t9 = 1;
    _1822_t11 = _1822_t5==_1822_t9;
    if (_1822_t11) {
        goto BB1989;
    } else {
        goto BB1993;
    }
BB1989:
    _1822_$retval = 301;
    return _1822_$retval;
BB1993:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1815_cmp(void* _1815_$self_ptr, int64_t* _1815_other){
    int64_t _1816_self;
    uint8_t _1815_t2;
    int64_t _1815_t1;
    int64_t _1815_t5;
    int64_t _1815_$retval;
    uint8_t _1815_t7;
    _1816_self = *(int64_t*)_1815_$self_ptr;
    _1815_t2 = _1816_self>*_1815_other;
    if (_1815_t2) {
        goto BB1973;
    } else {
        goto BB1977;
    }
BB1973:
    _1815_t1 = -1;
    goto BB1976;
BB1977:
    _1815_t7 = _1816_self==*_1815_other;
    if (_1815_t7) {
        goto BB1980;
    } else {
        goto BB1983;
    }
BB1976:
    _1815_$retval = _1815_t1;
    return _1815_$retval;
BB1980:
    _1815_t5 = 0;
    goto BB1982;
BB1983:
    _1815_t5 = 1;
    goto BB1982;
BB1982:
    _1815_t1 = _1815_t5;
    goto BB1976;
}


int main(void) {
  printf("%ld",_1822_main());
  return 0;
}
