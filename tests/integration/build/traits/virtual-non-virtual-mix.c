/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;
struct struct4;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

struct struct2 {
    void* _0;
    void* _1;
};

typedef int64_t(*function1)(void*, void*);

struct struct4 {
    int64_t* _0;
    int64_t* _1;
};

typedef int64_t(*function3)(int64_t*, int64_t*);

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*id)(void);
};

/* Function forward definitions */
int64_t _230_main(void);
int64_t _223_cmp(void* _223_$self_ptr, int64_t* _223_other);
int64_t _221_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _220_$vtable = {
    .id = _221_id,
};


/* Function definitions */
int64_t _230_main(void){
    int64_t _231_x;
    int64_t _231_y;
    int64_t* _230_t6;
    int64_t* _230_t7;
    function3 _230_t8;
    int64_t _230_t5;
    int64_t _230_t9;
    uint8_t _230_t11;
    int64_t _230_t12;
    int64_t _230_t13;
    int64_t _230_$retval;
    _231_x = 5;
    _231_y = 6;
    _230_t6 = &_231_x;
    _230_t7 = &_231_y;
    _230_t8 = (function3) _223_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _230_t5 = _230_t8(_230_t6, _230_t7);
    $line_idx--;
    _230_t9 = 1;
    _230_t11 = _230_t5==_230_t9;
    if (_230_t11) {
        goto BB161;
    } else {
        goto BB165;
    }
BB161:
    _230_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _230_t13 = _220_$vtable.id();
    $line_idx--;
    _230_$retval = $add_int64_t(_230_t12, _230_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _230_$retval;
BB165:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _223_cmp(void* _223_$self_ptr, int64_t* _223_other){
    int64_t _224_self;
    uint8_t _223_t2;
    int64_t _223_t1;
    int64_t _223_t5;
    int64_t _223_$retval;
    uint8_t _223_t7;
    _224_self = *(int64_t*)_223_$self_ptr;
    _223_t2 = _224_self>*_223_other;
    if (_223_t2) {
        goto BB143;
    } else {
        goto BB147;
    }
BB143:
    _223_t1 = -1;
    goto BB146;
BB147:
    _223_t7 = _224_self==*_223_other;
    if (_223_t7) {
        goto BB150;
    } else {
        goto BB153;
    }
BB146:
    _223_$retval = _223_t1;
    return _223_$retval;
BB150:
    _223_t5 = 0;
    goto BB152;
BB153:
    _223_t5 = 1;
    goto BB152;
BB152:
    _223_t1 = _223_t5;
    goto BB146;
}

int64_t _221_id(void){
    int64_t _221_$retval;
    _221_$retval = 4;
    return _221_$retval;
}


int main(void) {
  printf("%ld",_230_main());
  return 0;
}
