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
int64_t _1839_main(void);
int64_t _1832_cmp(void* _1832_$self_ptr, int64_t* _1832_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1839_main(void){
    int64_t _1840_x;
    int64_t _1840_y;
    int64_t* _1839_t6;
    int64_t* _1839_t7;
    function2 _1839_t8;
    int64_t _1839_t5;
    int64_t _1839_t9;
    uint8_t _1839_t11;
    int64_t _1839_$retval;
    _1840_x = 5;
    _1840_y = 6;
    _1839_t6 = &_1840_x;
    _1839_t7 = &_1840_y;
    _1839_t8 = (function2) _1832_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1839_t5 = _1839_t8(_1839_t6, _1839_t7);
    $line_idx--;
    _1839_t9 = 1;
    _1839_t11 = _1839_t5==_1839_t9;
    if (_1839_t11) {
        goto BB2007;
    } else {
        goto BB2011;
    }
BB2007:
    _1839_$retval = 301;
    return _1839_$retval;
BB2011:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1832_cmp(void* _1832_$self_ptr, int64_t* _1832_other){
    int64_t _1833_self;
    uint8_t _1832_t2;
    int64_t _1832_t1;
    int64_t _1832_t5;
    int64_t _1832_$retval;
    uint8_t _1832_t7;
    _1833_self = *(int64_t*)_1832_$self_ptr;
    _1832_t2 = _1833_self>*_1832_other;
    if (_1832_t2) {
        goto BB1991;
    } else {
        goto BB1995;
    }
BB1991:
    _1832_t1 = -1;
    goto BB1994;
BB1995:
    _1832_t7 = _1833_self==*_1832_other;
    if (_1832_t7) {
        goto BB1998;
    } else {
        goto BB2001;
    }
BB1994:
    _1832_$retval = _1832_t1;
    return _1832_$retval;
BB1998:
    _1832_t5 = 0;
    goto BB2000;
BB2001:
    _1832_t5 = 1;
    goto BB2000;
BB2000:
    _1832_t1 = _1832_t5;
    goto BB1994;
}


int main(void) {
  printf("%ld",_1839_main());
  return 0;
}
