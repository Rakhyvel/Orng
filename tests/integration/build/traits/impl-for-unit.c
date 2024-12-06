/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;
struct struct5;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

struct struct3 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function2)(void*, int64_t);

struct struct5 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function4)(int64_t*, int64_t);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _1670_main(void);
int64_t _1661_a(void* _1661_$self_ptr, int64_t _1661_x);
int64_t _1663_b(void* _1663_self, int64_t _1663_x);
int64_t _1666_a(void* _1666_$self_ptr, int64_t _1666_x);
int64_t _1668_b(void* _1668_self, int64_t _1668_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1670_main(void){
    int64_t _1671_y;
    void* _1670_t8;
    int64_t _1670_t9;
    function2 _1670_t10;
    int64_t _1670_t7;
    void* _1670_t12;
    int64_t _1670_t13;
    function2 _1670_t14;
    int64_t _1670_t11;
    int64_t _1670_t15;
    int64_t* _1670_t17;
    int64_t _1670_t18;
    function4 _1670_t19;
    int64_t _1670_t16;
    int64_t _1670_t20;
    int64_t* _1670_t22;
    int64_t _1670_t23;
    function4 _1670_t24;
    int64_t _1670_t21;
    int64_t _1670_$retval;
    _1671_y = 0;
    _1670_t8 = (void*) 0xAAAAAAAA;
    _1670_t9 = 100;
    _1670_t10 = (function2) _1661_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1670_t7 = _1670_t10(_1670_t8, _1670_t9);
    $line_idx--;
    _1670_t12 = (void*) 0xAAAAAAAA;
    _1670_t13 = 100;
    _1670_t14 = (function2) _1663_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1670_t11 = _1670_t14(_1670_t12, _1670_t13);
    $line_idx--;
    _1670_t15 = $add_int64_t(_1670_t7, _1670_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1670_t17 = &_1671_y;
    _1670_t18 = 12;
    _1670_t19 = (function4) _1666_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1670_t16 = _1670_t19(_1670_t17, _1670_t18);
    $line_idx--;
    _1670_t20 = $add_int64_t(_1670_t15, _1670_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1670_t22 = &_1671_y;
    _1670_t23 = 100;
    _1670_t24 = (function4) _1668_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1670_t21 = _1670_t24(_1670_t22, _1670_t23);
    $line_idx--;
    _1670_$retval = $add_int64_t(_1670_t20, _1670_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1670_$retval;
}

int64_t _1661_a(void* _1661_$self_ptr, int64_t _1661_x){
    int64_t _1661_$retval;
    (void)_1661_$self_ptr;
    goto BB1873;
BB1873:
    _1661_$retval = _1661_x;
    return _1661_$retval;
}

int64_t _1663_b(void* _1663_self, int64_t _1663_x){
    int64_t _1663_$retval;
    (void)_1663_self;
    goto BB1875;
BB1875:
    _1663_$retval = _1663_x;
    return _1663_$retval;
}

int64_t _1666_a(void* _1666_$self_ptr, int64_t _1666_x){
    int64_t _1667_self;
    int64_t _1666_$retval;
    _1667_self = *(int64_t*)_1666_$self_ptr;
    _1666_$retval = $add_int64_t(_1667_self, _1666_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1666_$retval;
}

int64_t _1668_b(void* _1668_self, int64_t _1668_x){
    int64_t _1668_$retval;
    *(int64_t*)_1668_self = _1668_x;
    _1668_$retval = _1668_x;
    return _1668_$retval;
}


int main(void) {
  printf("%ld",_1670_main());
  return 0;
}
