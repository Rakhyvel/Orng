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
int64_t _1723_main(void);
int64_t _1716_cmp(void* _1716_$self_ptr, int64_t* _1716_other);
int64_t _1714_id(void);

/* Trait vtable implementations */
struct vtable_My_Trait _1713_$vtable = {
    .id = _1714_id,
};


/* Function definitions */
int64_t _1723_main(void){
    int64_t _1724_x;
    int64_t _1724_y;
    int64_t* _1723_t6;
    int64_t* _1723_t7;
    function3 _1723_t8;
    int64_t _1723_t5;
    int64_t _1723_t9;
    uint8_t _1723_t11;
    int64_t _1723_t12;
    int64_t _1723_t13;
    int64_t _1723_$retval;
    _1724_x = 5;
    _1724_y = 6;
    _1723_t6 = &_1724_x;
    _1723_t7 = &_1724_y;
    _1723_t8 = (function3) _1716_cmp;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:25:11:\n    if x.>cmp(&y) == 1 {\n         ^";
    _1723_t5 = _1723_t8(_1723_t6, _1723_t7);
    $line_idx--;
    _1723_t9 = 1;
    _1723_t11 = _1723_t5==_1723_t9;
    if (_1723_t11) {
        goto BB1915;
    } else {
        goto BB1919;
    }
BB1915:
    _1723_t12 = 301;
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:26:18:\n        301 + x.>id()\n                ^";
    _1723_t13 = _1713_$vtable.id();
    $line_idx--;
    _1723_$retval = $add_int64_t(_1723_t12, _1723_t13, "tests/integration/traits/virtual-non-virtual-mix.orng:26:14:\n        301 + x.>id()\n            ^");
    return _1723_$retval;
BB1919:
    $lines[$line_idx++] = "tests/integration/traits/virtual-non-virtual-mix.orng:28:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _1716_cmp(void* _1716_$self_ptr, int64_t* _1716_other){
    int64_t _1717_self;
    uint8_t _1716_t2;
    int64_t _1716_t1;
    int64_t _1716_t5;
    int64_t _1716_$retval;
    uint8_t _1716_t7;
    _1717_self = *(int64_t*)_1716_$self_ptr;
    _1716_t2 = _1717_self>*_1716_other;
    if (_1716_t2) {
        goto BB1897;
    } else {
        goto BB1901;
    }
BB1897:
    _1716_t1 = -1;
    goto BB1900;
BB1901:
    _1716_t7 = _1717_self==*_1716_other;
    if (_1716_t7) {
        goto BB1904;
    } else {
        goto BB1907;
    }
BB1900:
    _1716_$retval = _1716_t1;
    return _1716_$retval;
BB1904:
    _1716_t5 = 0;
    goto BB1906;
BB1907:
    _1716_t5 = 1;
    goto BB1906;
BB1906:
    _1716_t1 = _1716_t5;
    goto BB1900;
}

int64_t _1714_id(void){
    int64_t _1714_$retval;
    _1714_$retval = 4;
    return _1714_$retval;
}


int main(void) {
  printf("%ld",_1723_main());
  return 0;
}
