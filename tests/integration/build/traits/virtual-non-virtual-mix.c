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
int64_t _174_main(void);
int64_t _167_cmp(void* _167_$self_ptr, int64_t* _167_other);
int64_t _165_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _164_$vtable = {
    .id = _165_id,
};


/* Function definitions */
int64_t _174_main(void){
    int64_t _175_x;
    int64_t _175_y;
    int64_t* _174_t6;
    int64_t* _174_t7;
    function3 _174_t8;
    int64_t _174_t5;
    int64_t _174_t9;
    uint8_t _174_t11;
    int64_t _174_t12;
    int64_t _174_t13;
    int64_t _174_$retval;
    _175_x = 5;
    _175_y = 6;
    _174_t6 = &_175_x;
    _174_t7 = &_175_y;
    _174_t8 = (function3) _167_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _174_t5 = _174_t8(_174_t6, _174_t7);
    $line_idx--;
    _174_t9 = 1;
    _174_t11 = _174_t5==_174_t9;
    if (_174_t11) {
        goto BB140;
    } else {
        goto BB144;
    }
BB140:
    _174_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _174_t13 = _164_$vtable.id();
    $line_idx--;
    _174_$retval = $add_int64_t(_174_t12, _174_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _174_$retval;
BB144:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _167_cmp(void* _167_$self_ptr, int64_t* _167_other){
    int64_t _168_self;
    uint8_t _167_t2;
    int64_t _167_t1;
    int64_t _167_t5;
    int64_t _167_$retval;
    uint8_t _167_t7;
    _168_self = *(int64_t*)_167_$self_ptr;
    _167_t2 = _168_self>*_167_other;
    if (_167_t2) {
        goto BB122;
    } else {
        goto BB126;
    }
BB122:
    _167_t1 = -1;
    goto BB125;
BB126:
    _167_t7 = _168_self==*_167_other;
    if (_167_t7) {
        goto BB129;
    } else {
        goto BB132;
    }
BB125:
    _167_$retval = _167_t1;
    return _167_$retval;
BB129:
    _167_t5 = 0;
    goto BB131;
BB132:
    _167_t5 = 1;
    goto BB131;
BB131:
    _167_t1 = _167_t5;
    goto BB125;
}

int64_t _165_id(void){
    int64_t _165_$retval;
    _165_$retval = 4;
    return _165_$retval;
}


int main(void) {
  printf("%ld",_174_main());
  return 0;
}
