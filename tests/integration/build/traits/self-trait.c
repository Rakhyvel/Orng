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
int64_t _1837_main(void);
int64_t _1830_cmp(void* _1830_$self_ptr, int64_t* _1830_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1837_main(void){
    int64_t _1838_x;
    int64_t _1838_y;
    int64_t* _1837_t6;
    int64_t* _1837_t7;
    function2 _1837_t8;
    int64_t _1837_t5;
    int64_t _1837_t9;
    uint8_t _1837_t11;
    int64_t _1837_$retval;
    _1838_x = 5;
    _1838_y = 6;
    _1837_t6 = &_1838_x;
    _1837_t7 = &_1838_y;
    _1837_t8 = (function2) _1830_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1837_t5 = _1837_t8(_1837_t6, _1837_t7);
    $line_idx--;
    _1837_t9 = 1;
    _1837_t11 = _1837_t5==_1837_t9;
    if (_1837_t11) {
        goto BB2005;
    } else {
        goto BB2009;
    }
BB2005:
    _1837_$retval = 301;
    return _1837_$retval;
BB2009:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1830_cmp(void* _1830_$self_ptr, int64_t* _1830_other){
    int64_t _1831_self;
    uint8_t _1830_t2;
    int64_t _1830_t1;
    int64_t _1830_t5;
    int64_t _1830_$retval;
    uint8_t _1830_t7;
    _1831_self = *(int64_t*)_1830_$self_ptr;
    _1830_t2 = _1831_self>*_1830_other;
    if (_1830_t2) {
        goto BB1989;
    } else {
        goto BB1993;
    }
BB1989:
    _1830_t1 = -1;
    goto BB1992;
BB1993:
    _1830_t7 = _1831_self==*_1830_other;
    if (_1830_t7) {
        goto BB1996;
    } else {
        goto BB1999;
    }
BB1992:
    _1830_$retval = _1830_t1;
    return _1830_$retval;
BB1996:
    _1830_t5 = 0;
    goto BB1998;
BB1999:
    _1830_t5 = 1;
    goto BB1998;
BB1998:
    _1830_t1 = _1830_t5;
    goto BB1992;
}


int main(void) {
  printf("%ld",_1837_main());
  return 0;
}
