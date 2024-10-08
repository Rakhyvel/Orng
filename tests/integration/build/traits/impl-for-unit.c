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
int64_t _1653_main(void);
int64_t _1644_a(void* _1644_$self_ptr, int64_t _1644_x);
int64_t _1646_b(void* _1646_self, int64_t _1646_x);
int64_t _1649_a(void* _1649_$self_ptr, int64_t _1649_x);
int64_t _1651_b(void* _1651_self, int64_t _1651_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1653_main(void){
    int64_t _1654_y;
    void* _1653_t8;
    int64_t _1653_t9;
    function2 _1653_t10;
    int64_t _1653_t7;
    void* _1653_t12;
    int64_t _1653_t13;
    function2 _1653_t14;
    int64_t _1653_t11;
    int64_t _1653_t15;
    int64_t* _1653_t17;
    int64_t _1653_t18;
    function4 _1653_t19;
    int64_t _1653_t16;
    int64_t _1653_t20;
    int64_t* _1653_t22;
    int64_t _1653_t23;
    function4 _1653_t24;
    int64_t _1653_t21;
    int64_t _1653_$retval;
    _1654_y = 0;
    _1653_t8 = (void*) 0xAAAAAAAA;
    _1653_t9 = 100;
    _1653_t10 = (function2) _1644_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1653_t7 = _1653_t10(_1653_t8, _1653_t9);
    $line_idx--;
    _1653_t12 = (void*) 0xAAAAAAAA;
    _1653_t13 = 100;
    _1653_t14 = (function2) _1646_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1653_t11 = _1653_t14(_1653_t12, _1653_t13);
    $line_idx--;
    _1653_t15 = $add_int64_t(_1653_t7, _1653_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1653_t17 = &_1654_y;
    _1653_t18 = 12;
    _1653_t19 = (function4) _1649_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1653_t16 = _1653_t19(_1653_t17, _1653_t18);
    $line_idx--;
    _1653_t20 = $add_int64_t(_1653_t15, _1653_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1653_t22 = &_1654_y;
    _1653_t23 = 100;
    _1653_t24 = (function4) _1651_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1653_t21 = _1653_t24(_1653_t22, _1653_t23);
    $line_idx--;
    _1653_$retval = $add_int64_t(_1653_t20, _1653_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1653_$retval;
}

int64_t _1644_a(void* _1644_$self_ptr, int64_t _1644_x){
    int64_t _1644_$retval;
    (void)_1644_$self_ptr;
    goto BB1857;
BB1857:
    _1644_$retval = _1644_x;
    return _1644_$retval;
}

int64_t _1646_b(void* _1646_self, int64_t _1646_x){
    int64_t _1646_$retval;
    (void)_1646_self;
    goto BB1859;
BB1859:
    _1646_$retval = _1646_x;
    return _1646_$retval;
}

int64_t _1649_a(void* _1649_$self_ptr, int64_t _1649_x){
    int64_t _1650_self;
    int64_t _1649_$retval;
    _1650_self = *(int64_t*)_1649_$self_ptr;
    _1649_$retval = $add_int64_t(_1650_self, _1649_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1649_$retval;
}

int64_t _1651_b(void* _1651_self, int64_t _1651_x){
    int64_t _1651_$retval;
    *(int64_t*)_1651_self = _1651_x;
    _1651_$retval = _1651_x;
    return _1651_$retval;
}


int main(void) {
  printf("%ld",_1653_main());
  return 0;
}
