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
int64_t _157_main(void);
int64_t _150_cmp(void* _150_$self_ptr, int64_t* _150_other);

/* Trait vtable implementations */

/* Function definitions */
int64_t _157_main(void){
    int64_t _158_x;
    int64_t _158_y;
    int64_t* _157_t6;
    int64_t* _157_t7;
    function2 _157_t8;
    int64_t _157_t5;
    int64_t _157_t9;
    uint8_t _157_t11;
    int64_t _157_$retval;
    _158_x = 5;
    _158_y = 6;
    _157_t6 = &_158_x;
    _157_t7 = &_158_y;
    _157_t8 = (function2) _150_cmp;
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:21:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _157_t5 = _157_t8(_157_t6, _157_t7);
    $line_idx--;
    _157_t9 = 1;
    _157_t11 = _157_t5==_157_t9;
    if (_157_t11) {
        goto BB115;
    } else {
        goto BB119;
    }
BB115:
    _157_$retval = 301;
    return _157_$retval;
BB119:
    $lines[$line_idx++] = "tests/integration/traits/self-trait.orng:24:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _150_cmp(void* _150_$self_ptr, int64_t* _150_other){
    int64_t _151_self;
    uint8_t _150_t2;
    int64_t _150_t1;
    int64_t _150_t5;
    int64_t _150_$retval;
    uint8_t _150_t7;
    _151_self = *(int64_t*)_150_$self_ptr;
    _150_t2 = _151_self>*_150_other;
    if (_150_t2) {
        goto BB99;
    } else {
        goto BB103;
    }
BB99:
    _150_t1 = -1;
    goto BB102;
BB103:
    _150_t7 = _151_self==*_150_other;
    if (_150_t7) {
        goto BB106;
    } else {
        goto BB109;
    }
BB102:
    _150_$retval = _150_t1;
    return _150_$retval;
BB106:
    _150_t5 = 0;
    goto BB108;
BB109:
    _150_t5 = 1;
    goto BB108;
BB108:
    _150_t1 = _150_t5;
    goto BB102;
}


int main(void) {
  printf("%ld",_157_main());
  return 0;
}
