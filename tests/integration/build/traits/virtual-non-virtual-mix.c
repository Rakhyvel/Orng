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
int64_t _1868_main(void);
int64_t _1861_cmp(void* _1861_$self_ptr, int64_t* _1861_other);
int64_t _1859_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1858_$vtable = {
    .id = _1859_id,
};


/* Function definitions */
int64_t _1868_main(void){
    int64_t _1869_x;
    int64_t _1869_y;
    int64_t* _1868_t6;
    int64_t* _1868_t7;
    function3 _1868_t8;
    int64_t _1868_t5;
    int64_t _1868_t9;
    uint8_t _1868_t11;
    int64_t _1868_t12;
    int64_t _1868_t13;
    int64_t _1868_$retval;
    _1869_x = 5;
    _1869_y = 6;
    _1868_t6 = &_1869_x;
    _1868_t7 = &_1869_y;
    _1868_t8 = (function3) _1861_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1868_t5 = _1868_t8(_1868_t6, _1868_t7);
    $line_idx--;
    _1868_t9 = 1;
    _1868_t11 = _1868_t5==_1868_t9;
    if (_1868_t11) {
        goto BB2037;
    } else {
        goto BB2041;
    }
BB2037:
    _1868_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1868_t13 = _1858_$vtable.id();
    $line_idx--;
    _1868_$retval = $add_int64_t(_1868_t12, _1868_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1868_$retval;
BB2041:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1861_cmp(void* _1861_$self_ptr, int64_t* _1861_other){
    int64_t _1862_self;
    uint8_t _1861_t2;
    int64_t _1861_t1;
    int64_t _1861_t5;
    int64_t _1861_$retval;
    uint8_t _1861_t7;
    _1862_self = *(int64_t*)_1861_$self_ptr;
    _1861_t2 = _1862_self>*_1861_other;
    if (_1861_t2) {
        goto BB2019;
    } else {
        goto BB2023;
    }
BB2019:
    _1861_t1 = -1;
    goto BB2022;
BB2023:
    _1861_t7 = _1862_self==*_1861_other;
    if (_1861_t7) {
        goto BB2026;
    } else {
        goto BB2029;
    }
BB2022:
    _1861_$retval = _1861_t1;
    return _1861_$retval;
BB2026:
    _1861_t5 = 0;
    goto BB2028;
BB2029:
    _1861_t5 = 1;
    goto BB2028;
BB2028:
    _1861_t1 = _1861_t5;
    goto BB2022;
}

int64_t _1859_id(void){
    int64_t _1859_$retval;
    _1859_$retval = 4;
    return _1859_$retval;
}


int main(void) {
  printf("%ld",_1868_main());
  return 0;
}
