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
int64_t _199_main(void);
int64_t _192_cmp(void* _192_$self_ptr, int64_t* _192_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _199_main(void){
    int64_t _200_x;
    int64_t _200_y;
    int64_t* _199_t6;
    int64_t* _199_t7;
    function2 _199_t8;
    int64_t _199_t5;
    int64_t _199_t9;
    uint8_t _199_t11;
    int64_t _199_$retval;
    _200_x = 5;
    _200_y = 6;
    _199_t6 = &_200_x;
    _199_t7 = &_200_y;
    _199_t8 = (function2) _192_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _199_t5 = _199_t8(_199_t6, _199_t7);
    $line_idx--;
    _199_t9 = 1;
    _199_t11 = _199_t5==_199_t9;
    if (_199_t11) {
        goto BB129;
    } else {
        goto BB133;
    }
BB129:
    _199_$retval = 301;
    return _199_$retval;
BB133:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _192_cmp(void* _192_$self_ptr, int64_t* _192_other){
    int64_t _193_self;
    uint8_t _192_t2;
    int64_t _192_t1;
    int64_t _192_t5;
    int64_t _192_$retval;
    uint8_t _192_t7;
    _193_self = *(int64_t*)_192_$self_ptr;
    _192_t2 = _193_self>*_192_other;
    if (_192_t2) {
        goto BB113;
    } else {
        goto BB117;
    }
BB113:
    _192_t1 = -1;
    goto BB116;
BB117:
    _192_t7 = _193_self==*_192_other;
    if (_192_t7) {
        goto BB120;
    } else {
        goto BB123;
    }
BB116:
    _192_$retval = _192_t1;
    return _192_$retval;
BB120:
    _192_t5 = 0;
    goto BB122;
BB123:
    _192_t5 = 1;
    goto BB122;
BB122:
    _192_t1 = _192_t5;
    goto BB116;
}


int main(void) {
  printf("%ld",_199_main());
  return 0;
}
