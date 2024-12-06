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
int64_t _1809_main(void);
int64_t _1802_cmp(void* _1802_$self_ptr, int64_t* _1802_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1809_main(void){
    int64_t _1810_x;
    int64_t _1810_y;
    int64_t* _1809_t6;
    int64_t* _1809_t7;
    function2 _1809_t8;
    int64_t _1809_t5;
    int64_t _1809_t9;
    uint8_t _1809_t11;
    int64_t _1809_$retval;
    _1810_x = 5;
    _1810_y = 6;
    _1809_t6 = &_1810_x;
    _1809_t7 = &_1810_y;
    _1809_t8 = (function2) _1802_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1809_t5 = _1809_t8(_1809_t6, _1809_t7);
    $line_idx--;
    _1809_t9 = 1;
    _1809_t11 = _1809_t5==_1809_t9;
    if (_1809_t11) {
        goto BB1976;
    } else {
        goto BB1980;
    }
BB1976:
    _1809_$retval = 301;
    return _1809_$retval;
BB1980:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1802_cmp(void* _1802_$self_ptr, int64_t* _1802_other){
    int64_t _1803_self;
    uint8_t _1802_t2;
    int64_t _1802_t1;
    int64_t _1802_t5;
    int64_t _1802_$retval;
    uint8_t _1802_t7;
    _1803_self = *(int64_t*)_1802_$self_ptr;
    _1802_t2 = _1803_self>*_1802_other;
    if (_1802_t2) {
        goto BB1960;
    } else {
        goto BB1964;
    }
BB1960:
    _1802_t1 = -1;
    goto BB1963;
BB1964:
    _1802_t7 = _1803_self==*_1802_other;
    if (_1802_t7) {
        goto BB1967;
    } else {
        goto BB1970;
    }
BB1963:
    _1802_$retval = _1802_t1;
    return _1802_$retval;
BB1967:
    _1802_t5 = 0;
    goto BB1969;
BB1970:
    _1802_t5 = 1;
    goto BB1969;
BB1969:
    _1802_t1 = _1802_t5;
    goto BB1963;
}


int main(void) {
  printf("%ld",_1809_main());
  return 0;
}
