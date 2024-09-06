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
int64_t _1650_main(void);
int64_t _1641_a(void* _1641_$self_ptr, int64_t _1641_x);
int64_t _1643_b(void* _1643_self, int64_t _1643_x);
int64_t _1646_a(void* _1646_$self_ptr, int64_t _1646_x);
int64_t _1648_b(void* _1648_self, int64_t _1648_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1650_main(void){
    int64_t _1651_y;
    void* _1650_t8;
    int64_t _1650_t9;
    function2 _1650_t10;
    int64_t _1650_t7;
    void* _1650_t12;
    int64_t _1650_t13;
    function2 _1650_t14;
    int64_t _1650_t11;
    int64_t _1650_t15;
    int64_t* _1650_t17;
    int64_t _1650_t18;
    function4 _1650_t19;
    int64_t _1650_t16;
    int64_t _1650_t20;
    int64_t* _1650_t22;
    int64_t _1650_t23;
    function4 _1650_t24;
    int64_t _1650_t21;
    int64_t _1650_$retval;
    _1651_y = 0;
    _1650_t8 = (void*) 0xAAAAAAAA;
    _1650_t9 = 100;
    _1650_t10 = (function2) _1641_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1650_t7 = _1650_t10(_1650_t8, _1650_t9);
    $line_idx--;
    _1650_t12 = (void*) 0xAAAAAAAA;
    _1650_t13 = 100;
    _1650_t14 = (function2) _1643_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1650_t11 = _1650_t14(_1650_t12, _1650_t13);
    $line_idx--;
    _1650_t15 = $add_int64_t(_1650_t7, _1650_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1650_t17 = &_1651_y;
    _1650_t18 = 12;
    _1650_t19 = (function4) _1646_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1650_t16 = _1650_t19(_1650_t17, _1650_t18);
    $line_idx--;
    _1650_t20 = $add_int64_t(_1650_t15, _1650_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1650_t22 = &_1651_y;
    _1650_t23 = 100;
    _1650_t24 = (function4) _1648_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1650_t21 = _1650_t24(_1650_t22, _1650_t23);
    $line_idx--;
    _1650_$retval = $add_int64_t(_1650_t20, _1650_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1650_$retval;
}

int64_t _1641_a(void* _1641_$self_ptr, int64_t _1641_x){
    int64_t _1641_$retval;
    (void)_1641_$self_ptr;
    goto BB1855;
BB1855:
    _1641_$retval = _1641_x;
    return _1641_$retval;
}

int64_t _1643_b(void* _1643_self, int64_t _1643_x){
    int64_t _1643_$retval;
    (void)_1643_self;
    goto BB1857;
BB1857:
    _1643_$retval = _1643_x;
    return _1643_$retval;
}

int64_t _1646_a(void* _1646_$self_ptr, int64_t _1646_x){
    int64_t _1647_self;
    int64_t _1646_$retval;
    _1647_self = *(int64_t*)_1646_$self_ptr;
    _1646_$retval = $add_int64_t(_1647_self, _1646_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1646_$retval;
}

int64_t _1648_b(void* _1648_self, int64_t _1648_x){
    int64_t _1648_$retval;
    *(int64_t*)_1648_self = _1648_x;
    _1648_$retval = _1648_x;
    return _1648_$retval;
}


int main(void) {
  printf("%ld",_1650_main());
  return 0;
}
