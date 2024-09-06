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
int64_t _1820_main(void);
int64_t _1813_cmp(void* _1813_$self_ptr, int64_t* _1813_other);
int64_t _1811_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1810_$vtable = {
    .id = _1811_id,
};


/* Function definitions */
int64_t _1820_main(void){
    int64_t _1821_x;
    int64_t _1821_y;
    int64_t* _1820_t6;
    int64_t* _1820_t7;
    function3 _1820_t8;
    int64_t _1820_t5;
    int64_t _1820_t9;
    uint8_t _1820_t11;
    int64_t _1820_t12;
    int64_t _1820_t13;
    int64_t _1820_$retval;
    _1821_x = 5;
    _1821_y = 6;
    _1820_t6 = &_1821_x;
    _1820_t7 = &_1821_y;
    _1820_t8 = (function3) _1813_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1820_t5 = _1820_t8(_1820_t6, _1820_t7);
    $line_idx--;
    _1820_t9 = 1;
    _1820_t11 = _1820_t5==_1820_t9;
    if (_1820_t11) {
        goto BB1990;
    } else {
        goto BB1994;
    }
BB1990:
    _1820_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1820_t13 = _1810_$vtable.id();
    $line_idx--;
    _1820_$retval = $add_int64_t(_1820_t12, _1820_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1820_$retval;
BB1994:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1813_cmp(void* _1813_$self_ptr, int64_t* _1813_other){
    int64_t _1814_self;
    uint8_t _1813_t2;
    int64_t _1813_t1;
    int64_t _1813_t5;
    int64_t _1813_$retval;
    uint8_t _1813_t7;
    _1814_self = *(int64_t*)_1813_$self_ptr;
    _1813_t2 = _1814_self>*_1813_other;
    if (_1813_t2) {
        goto BB1972;
    } else {
        goto BB1976;
    }
BB1972:
    _1813_t1 = -1;
    goto BB1975;
BB1976:
    _1813_t7 = _1814_self==*_1813_other;
    if (_1813_t7) {
        goto BB1979;
    } else {
        goto BB1982;
    }
BB1975:
    _1813_$retval = _1813_t1;
    return _1813_$retval;
BB1979:
    _1813_t5 = 0;
    goto BB1981;
BB1982:
    _1813_t5 = 1;
    goto BB1981;
BB1981:
    _1813_t1 = _1813_t5;
    goto BB1975;
}

int64_t _1811_id(void){
    int64_t _1811_$retval;
    _1811_$retval = 4;
    return _1811_$retval;
}


int main(void) {
  printf("%ld",_1820_main());
  return 0;
}
