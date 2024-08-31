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
int64_t _1578_main(void);
int64_t _1569_a(void* _1569_$self_ptr, int64_t _1569_x);
int64_t _1571_b(void* _1571_self, int64_t _1571_x);
int64_t _1574_a(void* _1574_$self_ptr, int64_t _1574_x);
int64_t _1576_b(void* _1576_self, int64_t _1576_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1578_main(void){
    int64_t _1579_y;
    void* _1578_t8;
    int64_t _1578_t9;
    function2 _1578_t10;
    int64_t _1578_t7;
    void* _1578_t12;
    int64_t _1578_t13;
    function2 _1578_t14;
    int64_t _1578_t11;
    int64_t _1578_t15;
    int64_t* _1578_t17;
    int64_t _1578_t18;
    function4 _1578_t19;
    int64_t _1578_t16;
    int64_t _1578_t20;
    int64_t* _1578_t22;
    int64_t _1578_t23;
    function4 _1578_t24;
    int64_t _1578_t21;
    int64_t _1578_$retval;
    _1579_y = 0;
    _1578_t8 = (void*) 0xAAAAAAAA;
    _1578_t9 = 100;
    _1578_t10 = (function2) _1569_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1578_t7 = _1578_t10(_1578_t8, _1578_t9);
    $line_idx--;
    _1578_t12 = (void*) 0xAAAAAAAA;
    _1578_t13 = 100;
    _1578_t14 = (function2) _1571_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1578_t11 = _1578_t14(_1578_t12, _1578_t13);
    $line_idx--;
    _1578_t15 = $add_int64_t(_1578_t7, _1578_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1578_t17 = &_1579_y;
    _1578_t18 = 12;
    _1578_t19 = (function4) _1574_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1578_t16 = _1578_t19(_1578_t17, _1578_t18);
    $line_idx--;
    _1578_t20 = $add_int64_t(_1578_t15, _1578_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1578_t22 = &_1579_y;
    _1578_t23 = 100;
    _1578_t24 = (function4) _1576_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1578_t21 = _1578_t24(_1578_t22, _1578_t23);
    $line_idx--;
    _1578_$retval = $add_int64_t(_1578_t20, _1578_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1578_$retval;
}

int64_t _1569_a(void* _1569_$self_ptr, int64_t _1569_x){
    int64_t _1569_$retval;
    (void)_1569_$self_ptr;
    _1569_$retval = _1569_x;
    return _1569_$retval;
}

int64_t _1571_b(void* _1571_self, int64_t _1571_x){
    int64_t _1571_$retval;
    (void)_1571_self;
    _1571_$retval = _1571_x;
    return _1571_$retval;
}

int64_t _1574_a(void* _1574_$self_ptr, int64_t _1574_x){
    int64_t _1575_self;
    int64_t _1574_$retval;
    _1575_self = *(int64_t*)_1574_$self_ptr;
    _1574_$retval = $add_int64_t(_1575_self, _1574_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1574_$retval;
}

int64_t _1576_b(void* _1576_self, int64_t _1576_x){
    int64_t _1576_$retval;
    *(int64_t*)_1576_self = _1576_x;
    _1576_$retval = _1576_x;
    return _1576_$retval;
}


int main(void) {
  printf("%ld",_1578_main());
  return 0;
}
