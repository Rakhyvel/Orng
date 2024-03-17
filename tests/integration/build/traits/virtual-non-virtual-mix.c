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
int64_t _1685_main(void);
int64_t _1678_cmp(void* _1678_$self_ptr, int64_t* _1678_other);
int64_t _1676_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1675_$vtable = {
    .id = _1676_id,
};


/* Function definitions */
int64_t _1685_main(void){
    int64_t _1686_x;
    int64_t _1686_y;
    int64_t* _1685_t6;
    int64_t* _1685_t7;
    function3 _1685_t8;
    int64_t _1685_t5;
    int64_t _1685_t9;
    uint8_t _1685_t11;
    int64_t _1685_t12;
    int64_t _1685_t13;
    int64_t _1685_$retval;
    _1686_x = 5;
    _1686_y = 6;
    _1685_t6 = &_1686_x;
    _1685_t7 = &_1686_y;
    _1685_t8 = (function3) _1678_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1685_t5 = _1685_t8(_1685_t6, _1685_t7);
    $line_idx--;
    _1685_t9 = 1;
    _1685_t11 = _1685_t5==_1685_t9;
    if (_1685_t11) {
        goto BB1888;
    } else {
        goto BB1892;
    }
BB1888:
    _1685_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1685_t13 = _1675_$vtable.id();
    $line_idx--;
    _1685_$retval = $add_int64_t(_1685_t12, _1685_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1685_$retval;
BB1892:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1678_cmp(void* _1678_$self_ptr, int64_t* _1678_other){
    int64_t _1679_self;
    uint8_t _1678_t2;
    int64_t _1678_t1;
    int64_t _1678_t5;
    int64_t _1678_$retval;
    uint8_t _1678_t7;
    _1679_self = *(int64_t*)_1678_$self_ptr;
    _1678_t2 = _1679_self>*_1678_other;
    if (_1678_t2) {
        goto BB1870;
    } else {
        goto BB1874;
    }
BB1870:
    _1678_t1 = -1;
    goto BB1873;
BB1874:
    _1678_t7 = _1679_self==*_1678_other;
    if (_1678_t7) {
        goto BB1877;
    } else {
        goto BB1880;
    }
BB1873:
    _1678_$retval = _1678_t1;
    return _1678_$retval;
BB1877:
    _1678_t5 = 0;
    goto BB1879;
BB1880:
    _1678_t5 = 1;
    goto BB1879;
BB1879:
    _1678_t1 = _1678_t5;
    goto BB1873;
}

int64_t _1676_id(void){
    int64_t _1676_$retval;
    _1676_$retval = 4;
    return _1676_$retval;
}


int main(void) {
  printf("%ld",_1685_main());
  return 0;
}
