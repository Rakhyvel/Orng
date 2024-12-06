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
int64_t _1840_main(void);
int64_t _1833_cmp(void* _1833_$self_ptr, int64_t* _1833_other);
int64_t _1831_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1830_$vtable = {
    .id = _1831_id,
};


/* Function definitions */
int64_t _1840_main(void){
    int64_t _1841_x;
    int64_t _1841_y;
    int64_t* _1840_t6;
    int64_t* _1840_t7;
    function3 _1840_t8;
    int64_t _1840_t5;
    int64_t _1840_t9;
    uint8_t _1840_t11;
    int64_t _1840_t12;
    int64_t _1840_t13;
    int64_t _1840_$retval;
    _1841_x = 5;
    _1841_y = 6;
    _1840_t6 = &_1841_x;
    _1840_t7 = &_1841_y;
    _1840_t8 = (function3) _1833_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1840_t5 = _1840_t8(_1840_t6, _1840_t7);
    $line_idx--;
    _1840_t9 = 1;
    _1840_t11 = _1840_t5==_1840_t9;
    if (_1840_t11) {
        goto BB2008;
    } else {
        goto BB2012;
    }
BB2008:
    _1840_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1840_t13 = _1830_$vtable.id();
    $line_idx--;
    _1840_$retval = $add_int64_t(_1840_t12, _1840_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1840_$retval;
BB2012:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1833_cmp(void* _1833_$self_ptr, int64_t* _1833_other){
    int64_t _1834_self;
    uint8_t _1833_t2;
    int64_t _1833_t1;
    int64_t _1833_t5;
    int64_t _1833_$retval;
    uint8_t _1833_t7;
    _1834_self = *(int64_t*)_1833_$self_ptr;
    _1833_t2 = _1834_self>*_1833_other;
    if (_1833_t2) {
        goto BB1990;
    } else {
        goto BB1994;
    }
BB1990:
    _1833_t1 = -1;
    goto BB1993;
BB1994:
    _1833_t7 = _1834_self==*_1833_other;
    if (_1833_t7) {
        goto BB1997;
    } else {
        goto BB2000;
    }
BB1993:
    _1833_$retval = _1833_t1;
    return _1833_$retval;
BB1997:
    _1833_t5 = 0;
    goto BB1999;
BB2000:
    _1833_t5 = 1;
    goto BB1999;
BB1999:
    _1833_t1 = _1833_t5;
    goto BB1993;
}

int64_t _1831_id(void){
    int64_t _1831_$retval;
    _1831_$retval = 4;
    return _1831_$retval;
}


int main(void) {
  printf("%ld",_1840_main());
  return 0;
}
