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
int64_t _1673_main(void);
int64_t _1666_cmp(void* _1666_$self_ptr, int64_t* _1666_other);
int64_t _1664_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1663_$vtable = {
    .id = _1664_id,
};


/* Function definitions */
int64_t _1673_main(void){
    int64_t _1674_x;
    int64_t _1674_y;
    int64_t* _1673_t6;
    int64_t* _1673_t7;
    function3 _1673_t8;
    int64_t _1673_t5;
    int64_t _1673_t9;
    uint8_t _1673_t11;
    int64_t _1673_t12;
    int64_t _1673_t13;
    int64_t _1673_$retval;
    _1674_x = 5;
    _1674_y = 6;
    _1673_t6 = &_1674_x;
    _1673_t7 = &_1674_y;
    _1673_t8 = (function3) _1666_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1673_t5 = _1673_t8(_1673_t6, _1673_t7);
    $line_idx--;
    _1673_t9 = 1;
    _1673_t11 = _1673_t5==_1673_t9;
    if (_1673_t11) {
        goto BB1882;
    } else {
        goto BB1886;
    }
BB1882:
    _1673_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1673_t13 = _1663_$vtable.id();
    $line_idx--;
    _1673_$retval = $add_int64_t(_1673_t12, _1673_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1673_$retval;
BB1886:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1666_cmp(void* _1666_$self_ptr, int64_t* _1666_other){
    int64_t _1667_self;
    uint8_t _1666_t2;
    int64_t _1666_t1;
    int64_t _1666_t5;
    int64_t _1666_$retval;
    uint8_t _1666_t7;
    _1667_self = *(int64_t*)_1666_$self_ptr;
    _1666_t2 = _1667_self>*_1666_other;
    if (_1666_t2) {
        goto BB1864;
    } else {
        goto BB1868;
    }
BB1864:
    _1666_t1 = -1;
    goto BB1867;
BB1868:
    _1666_t7 = _1667_self==*_1666_other;
    if (_1666_t7) {
        goto BB1871;
    } else {
        goto BB1874;
    }
BB1867:
    _1666_$retval = _1666_t1;
    return _1666_$retval;
BB1871:
    _1666_t5 = 0;
    goto BB1873;
BB1874:
    _1666_t5 = 1;
    goto BB1873;
BB1873:
    _1666_t1 = _1666_t5;
    goto BB1867;
}

int64_t _1664_id(void){
    int64_t _1664_$retval;
    _1664_$retval = 4;
    return _1664_$retval;
}


int main(void) {
  printf("%ld",_1673_main());
  return 0;
}
