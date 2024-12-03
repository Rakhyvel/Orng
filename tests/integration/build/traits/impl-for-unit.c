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
int64_t _1658_main(void);
int64_t _1649_a(void* _1649_$self_ptr, int64_t _1649_x);
int64_t _1651_b(void* _1651_self, int64_t _1651_x);
int64_t _1654_a(void* _1654_$self_ptr, int64_t _1654_x);
int64_t _1656_b(void* _1656_self, int64_t _1656_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1658_main(void){
    int64_t _1659_y;
    void* _1658_t8;
    int64_t _1658_t9;
    function2 _1658_t10;
    int64_t _1658_t7;
    void* _1658_t12;
    int64_t _1658_t13;
    function2 _1658_t14;
    int64_t _1658_t11;
    int64_t _1658_t15;
    int64_t* _1658_t17;
    int64_t _1658_t18;
    function4 _1658_t19;
    int64_t _1658_t16;
    int64_t _1658_t20;
    int64_t* _1658_t22;
    int64_t _1658_t23;
    function4 _1658_t24;
    int64_t _1658_t21;
    int64_t _1658_$retval;
    _1659_y = 0;
    _1658_t8 = (void*) 0xAAAAAAAA;
    _1658_t9 = 100;
    _1658_t10 = (function2) _1649_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1658_t7 = _1658_t10(_1658_t8, _1658_t9);
    $line_idx--;
    _1658_t12 = (void*) 0xAAAAAAAA;
    _1658_t13 = 100;
    _1658_t14 = (function2) _1651_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1658_t11 = _1658_t14(_1658_t12, _1658_t13);
    $line_idx--;
    _1658_t15 = $add_int64_t(_1658_t7, _1658_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1658_t17 = &_1659_y;
    _1658_t18 = 12;
    _1658_t19 = (function4) _1654_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1658_t16 = _1658_t19(_1658_t17, _1658_t18);
    $line_idx--;
    _1658_t20 = $add_int64_t(_1658_t15, _1658_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1658_t22 = &_1659_y;
    _1658_t23 = 100;
    _1658_t24 = (function4) _1656_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1658_t21 = _1658_t24(_1658_t22, _1658_t23);
    $line_idx--;
    _1658_$retval = $add_int64_t(_1658_t20, _1658_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1658_$retval;
}

int64_t _1649_a(void* _1649_$self_ptr, int64_t _1649_x){
    int64_t _1649_$retval;
    (void)_1649_$self_ptr;
    goto BB1861;
BB1861:
    _1649_$retval = _1649_x;
    return _1649_$retval;
}

int64_t _1651_b(void* _1651_self, int64_t _1651_x){
    int64_t _1651_$retval;
    (void)_1651_self;
    goto BB1863;
BB1863:
    _1651_$retval = _1651_x;
    return _1651_$retval;
}

int64_t _1654_a(void* _1654_$self_ptr, int64_t _1654_x){
    int64_t _1655_self;
    int64_t _1654_$retval;
    _1655_self = *(int64_t*)_1654_$self_ptr;
    _1654_$retval = $add_int64_t(_1655_self, _1654_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1654_$retval;
}

int64_t _1656_b(void* _1656_self, int64_t _1656_x){
    int64_t _1656_$retval;
    *(int64_t*)_1656_self = _1656_x;
    _1656_$retval = _1656_x;
    return _1656_$retval;
}


int main(void) {
  printf("%ld",_1658_main());
  return 0;
}
