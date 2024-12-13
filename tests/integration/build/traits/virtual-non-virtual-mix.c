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
int64_t _1870_main(void);
int64_t _1863_cmp(void* _1863_$self_ptr, int64_t* _1863_other);
int64_t _1861_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1860_$vtable = {
    .id = _1861_id,
};


/* Function definitions */
int64_t _1870_main(void){
    int64_t _1871_x;
    int64_t _1871_y;
    int64_t* _1870_t6;
    int64_t* _1870_t7;
    function3 _1870_t8;
    int64_t _1870_t5;
    int64_t _1870_t9;
    uint8_t _1870_t11;
    int64_t _1870_t12;
    int64_t _1870_t13;
    int64_t _1870_$retval;
    _1871_x = 5;
    _1871_y = 6;
    _1870_t6 = &_1871_x;
    _1870_t7 = &_1871_y;
    _1870_t8 = (function3) _1863_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1870_t5 = _1870_t8(_1870_t6, _1870_t7);
    $line_idx--;
    _1870_t9 = 1;
    _1870_t11 = _1870_t5==_1870_t9;
    if (_1870_t11) {
        goto BB2039;
    } else {
        goto BB2043;
    }
BB2039:
    _1870_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1870_t13 = _1860_$vtable.id();
    $line_idx--;
    _1870_$retval = $add_int64_t(_1870_t12, _1870_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1870_$retval;
BB2043:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1863_cmp(void* _1863_$self_ptr, int64_t* _1863_other){
    int64_t _1864_self;
    uint8_t _1863_t2;
    int64_t _1863_t1;
    int64_t _1863_t5;
    int64_t _1863_$retval;
    uint8_t _1863_t7;
    _1864_self = *(int64_t*)_1863_$self_ptr;
    _1863_t2 = _1864_self>*_1863_other;
    if (_1863_t2) {
        goto BB2021;
    } else {
        goto BB2025;
    }
BB2021:
    _1863_t1 = -1;
    goto BB2024;
BB2025:
    _1863_t7 = _1864_self==*_1863_other;
    if (_1863_t7) {
        goto BB2028;
    } else {
        goto BB2031;
    }
BB2024:
    _1863_$retval = _1863_t1;
    return _1863_$retval;
BB2028:
    _1863_t5 = 0;
    goto BB2030;
BB2031:
    _1863_t5 = 1;
    goto BB2030;
BB2030:
    _1863_t1 = _1863_t5;
    goto BB2024;
}

int64_t _1861_id(void){
    int64_t _1861_$retval;
    _1861_$retval = 4;
    return _1861_$retval;
}


int main(void) {
  printf("%ld",_1870_main());
  return 0;
}
