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
int64_t _1746_main(void);
int64_t _1739_cmp(void* _1739_$self_ptr, int64_t* _1739_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1746_main(void){
    int64_t _1747_x;
    int64_t _1747_y;
    int64_t* _1746_t6;
    int64_t* _1746_t7;
    function2 _1746_t8;
    int64_t _1746_t5;
    int64_t _1746_t9;
    uint8_t _1746_t11;
    int64_t _1746_$retval;
    _1747_x = 5;
    _1747_y = 6;
    _1746_t6 = &_1747_x;
    _1746_t7 = &_1747_y;
    _1746_t8 = (function2) _1739_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1746_t5 = _1746_t8(_1746_t6, _1746_t7);
    $line_idx--;
    _1746_t9 = 1;
    _1746_t11 = _1746_t5==_1746_t9;
    if (_1746_t11) {
        goto BB1942;
    } else {
        goto BB1946;
    }
BB1942:
    _1746_$retval = 301;
    return _1746_$retval;
BB1946:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1739_cmp(void* _1739_$self_ptr, int64_t* _1739_other){
    int64_t _1740_self;
    uint8_t _1739_t2;
    int64_t _1739_t1;
    int64_t _1739_t5;
    int64_t _1739_$retval;
    uint8_t _1739_t7;
    _1740_self = *(int64_t*)_1739_$self_ptr;
    _1739_t2 = _1740_self>*_1739_other;
    if (_1739_t2) {
        goto BB1926;
    } else {
        goto BB1930;
    }
BB1926:
    _1739_t1 = -1;
    goto BB1929;
BB1930:
    _1739_t7 = _1740_self==*_1739_other;
    if (_1739_t7) {
        goto BB1933;
    } else {
        goto BB1936;
    }
BB1929:
    _1739_$retval = _1739_t1;
    return _1739_$retval;
BB1933:
    _1739_t5 = 0;
    goto BB1935;
BB1936:
    _1739_t5 = 1;
    goto BB1935;
BB1935:
    _1739_t1 = _1739_t5;
    goto BB1929;
}


int main(void) {
  printf("%ld",_1746_main());
  return 0;
}
