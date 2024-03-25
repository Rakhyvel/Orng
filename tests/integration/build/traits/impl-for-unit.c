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
int64_t _1573_main(void);
int64_t _1564_a(void* _1564_$self_ptr, int64_t _1564_x);
int64_t _1566_b(void* _1566_self, int64_t _1566_x);
int64_t _1569_a(void* _1569_$self_ptr, int64_t _1569_x);
int64_t _1571_b(void* _1571_self, int64_t _1571_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1573_main(void){
    int64_t _1574_y;
    void* _1573_t8;
    int64_t _1573_t9;
    function2 _1573_t10;
    int64_t _1573_t7;
    void* _1573_t12;
    int64_t _1573_t13;
    function2 _1573_t14;
    int64_t _1573_t11;
    int64_t _1573_t15;
    int64_t* _1573_t17;
    int64_t _1573_t18;
    function4 _1573_t19;
    int64_t _1573_t16;
    int64_t _1573_t20;
    int64_t* _1573_t22;
    int64_t _1573_t23;
    function4 _1573_t24;
    int64_t _1573_t21;
    int64_t _1573_$retval;
    _1574_y = 0;
    _1573_t8 = (void*) 0xAAAAAAAA;
    _1573_t9 = 100;
    _1573_t10 = (function2) _1564_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1573_t7 = _1573_t10(_1573_t8, _1573_t9);
    $line_idx--;
    _1573_t12 = (void*) 0xAAAAAAAA;
    _1573_t13 = 100;
    _1573_t14 = (function2) _1566_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1573_t11 = _1573_t14(_1573_t12, _1573_t13);
    $line_idx--;
    _1573_t15 = $add_int64_t(_1573_t7, _1573_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1573_t17 = &_1574_y;
    _1573_t18 = 12;
    _1573_t19 = (function4) _1569_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1573_t16 = _1573_t19(_1573_t17, _1573_t18);
    $line_idx--;
    _1573_t20 = $add_int64_t(_1573_t15, _1573_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1573_t22 = &_1574_y;
    _1573_t23 = 100;
    _1573_t24 = (function4) _1571_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1573_t21 = _1573_t24(_1573_t22, _1573_t23);
    $line_idx--;
    _1573_$retval = $add_int64_t(_1573_t20, _1573_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1573_$retval;
}

int64_t _1564_a(void* _1564_$self_ptr, int64_t _1564_x){
    int64_t _1564_$retval;
    (void)_1564_$self_ptr;
    _1564_$retval = _1564_x;
    return _1564_$retval;
}

int64_t _1566_b(void* _1566_self, int64_t _1566_x){
    int64_t _1566_$retval;
    (void)_1566_self;
    _1566_$retval = _1566_x;
    return _1566_$retval;
}

int64_t _1569_a(void* _1569_$self_ptr, int64_t _1569_x){
    int64_t _1570_self;
    int64_t _1569_$retval;
    _1570_self = *(int64_t*)_1569_$self_ptr;
    _1569_$retval = $add_int64_t(_1570_self, _1569_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1569_$retval;
}

int64_t _1571_b(void* _1571_self, int64_t _1571_x){
    int64_t _1571_$retval;
    *(int64_t*)_1571_self = _1571_x;
    _1571_$retval = _1571_x;
    return _1571_$retval;
}


int main(void) {
  printf("%ld",_1573_main());
  return 0;
}
