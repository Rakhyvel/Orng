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
int64_t _121_main(void);
int64_t _114_cmp(void* _114_$self_ptr, int64_t* _114_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _121_main(void){
    int64_t _122_x;
    int64_t _122_y;
    int64_t* _121_t4;
    int64_t* _121_t5;
    function2 _121_t6;
    int64_t _121_t3;
    int64_t _121_t7;
    uint8_t _121_t9;
    int64_t _121_$retval;
    _122_x = 5;
    _122_y = 6;
    _121_t4 = &_122_x;
    _121_t5 = &_122_y;
    _121_t6 = (function2) _114_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _121_t3 = _121_t6(_121_t4, _121_t5);
    $line_idx--;
    _121_t7 = 1;
    _121_t9 = _121_t3==_121_t7;
    if (_121_t9) {
        goto BB89;
    } else {
        goto BB93;
    }
BB89:
    _121_$retval = 301;
    return _121_$retval;
BB93:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _114_cmp(void* _114_$self_ptr, int64_t* _114_other){
    int64_t _115_self;
    uint8_t _114_t1;
    int64_t _114_t0;
    int64_t _114_t4;
    int64_t _114_$retval;
    uint8_t _114_t6;
    _115_self = *(int64_t*)_114_$self_ptr;
    _114_t1 = _115_self>*_114_other;
    if (_114_t1) {
        goto BB73;
    } else {
        goto BB77;
    }
BB73:
    _114_t0 = -1;
    goto BB76;
BB77:
    _114_t6 = _115_self==*_114_other;
    if (_114_t6) {
        goto BB80;
    } else {
        goto BB83;
    }
BB76:
    _114_$retval = _114_t0;
    return _114_$retval;
BB80:
    _114_t4 = 0;
    goto BB82;
BB83:
    _114_t4 = 1;
    goto BB82;
BB82:
    _114_t0 = _114_t4;
    goto BB76;
}


int main(void) {
  printf("%ld",_121_main());
  return 0;
}
