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
int64_t _1853_main(void);
int64_t _1846_cmp(void* _1846_$self_ptr, int64_t* _1846_other);
int64_t _1844_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1843_$vtable = {
    .id = _1844_id,
};


/* Function definitions */
int64_t _1853_main(void){
    int64_t _1854_x;
    int64_t _1854_y;
    int64_t* _1853_t6;
    int64_t* _1853_t7;
    function3 _1853_t8;
    int64_t _1853_t5;
    int64_t _1853_t9;
    uint8_t _1853_t11;
    int64_t _1853_t12;
    int64_t _1853_t13;
    int64_t _1853_$retval;
    _1854_x = 5;
    _1854_y = 6;
    _1853_t6 = &_1854_x;
    _1853_t7 = &_1854_y;
    _1853_t8 = (function3) _1846_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1853_t5 = _1853_t8(_1853_t6, _1853_t7);
    $line_idx--;
    _1853_t9 = 1;
    _1853_t11 = _1853_t5==_1853_t9;
    if (_1853_t11) {
        goto BB2021;
    } else {
        goto BB2025;
    }
BB2021:
    _1853_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1853_t13 = _1843_$vtable.id();
    $line_idx--;
    _1853_$retval = $add_int64_t(_1853_t12, _1853_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1853_$retval;
BB2025:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1846_cmp(void* _1846_$self_ptr, int64_t* _1846_other){
    int64_t _1847_self;
    uint8_t _1846_t2;
    int64_t _1846_t1;
    int64_t _1846_t5;
    int64_t _1846_$retval;
    uint8_t _1846_t7;
    _1847_self = *(int64_t*)_1846_$self_ptr;
    _1846_t2 = _1847_self>*_1846_other;
    if (_1846_t2) {
        goto BB2003;
    } else {
        goto BB2007;
    }
BB2003:
    _1846_t1 = -1;
    goto BB2006;
BB2007:
    _1846_t7 = _1847_self==*_1846_other;
    if (_1846_t7) {
        goto BB2010;
    } else {
        goto BB2013;
    }
BB2006:
    _1846_$retval = _1846_t1;
    return _1846_$retval;
BB2010:
    _1846_t5 = 0;
    goto BB2012;
BB2013:
    _1846_t5 = 1;
    goto BB2012;
BB2012:
    _1846_t1 = _1846_t5;
    goto BB2006;
}

int64_t _1844_id(void){
    int64_t _1844_$retval;
    _1844_$retval = 4;
    return _1844_$retval;
}


int main(void) {
  printf("%ld",_1853_main());
  return 0;
}
