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
int64_t _112_main(void);
int64_t _105_cmp(void* _105_$self_ptr, int64_t* _105_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _112_main(void){
    int64_t _113_x;
    int64_t _113_y;
    int64_t* _112_t4;
    int64_t* _112_t5;
    function2 _112_t6;
    int64_t _112_t3;
    int64_t _112_t7;
    uint8_t _112_t9;
    int64_t _112_$retval;
    _113_x = 5;
    _113_y = 6;
    _112_t4 = &_113_x;
    _112_t5 = &_113_y;
    _112_t6 = (function2) _105_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _112_t3 = _112_t6(_112_t4, _112_t5);
    $line_idx--;
    _112_t7 = 1;
    _112_t9 = _112_t3==_112_t7;
    if (_112_t9) {
        goto BB89;
    } else {
        goto BB93;
    }
BB89:
    _112_$retval = 301;
    return _112_$retval;
BB93:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _105_cmp(void* _105_$self_ptr, int64_t* _105_other){
    int64_t _106_self;
    uint8_t _105_t1;
    int64_t _105_t0;
    int64_t _105_t4;
    int64_t _105_$retval;
    uint8_t _105_t6;
    _106_self = *(int64_t*)_105_$self_ptr;
    _105_t1 = _106_self>*_105_other;
    if (_105_t1) {
        goto BB73;
    } else {
        goto BB77;
    }
BB73:
    _105_t0 = -1;
    goto BB76;
BB77:
    _105_t6 = _106_self==*_105_other;
    if (_105_t6) {
        goto BB80;
    } else {
        goto BB83;
    }
BB76:
    _105_$retval = _105_t0;
    return _105_$retval;
BB80:
    _105_t4 = 0;
    goto BB82;
BB83:
    _105_t4 = 1;
    goto BB82;
BB82:
    _105_t0 = _105_t4;
    goto BB76;
}


int main(void) {
  printf("%ld",_112_main());
  return 0;
}
