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
int64_t _1617_main(void);
int64_t _1608_a(void* _1608_$self_ptr, int64_t _1608_x);
int64_t _1610_b(void* _1610_self, int64_t _1610_x);
int64_t _1613_a(void* _1613_$self_ptr, int64_t _1613_x);
int64_t _1615_b(void* _1615_self, int64_t _1615_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1617_main(void){
    int64_t _1618_y;
    void* _1617_t8;
    int64_t _1617_t9;
    function2 _1617_t10;
    int64_t _1617_t7;
    void* _1617_t12;
    int64_t _1617_t13;
    function2 _1617_t14;
    int64_t _1617_t11;
    int64_t _1617_t15;
    int64_t* _1617_t17;
    int64_t _1617_t18;
    function4 _1617_t19;
    int64_t _1617_t16;
    int64_t _1617_t20;
    int64_t* _1617_t22;
    int64_t _1617_t23;
    function4 _1617_t24;
    int64_t _1617_t21;
    int64_t _1617_$retval;
    _1618_y = 0;
    _1617_t8 = (void*) 0xAAAAAAAA;
    _1617_t9 = 100;
    _1617_t10 = (function2) _1608_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1617_t7 = _1617_t10(_1617_t8, _1617_t9);
    $line_idx--;
    _1617_t12 = (void*) 0xAAAAAAAA;
    _1617_t13 = 100;
    _1617_t14 = (function2) _1610_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1617_t11 = _1617_t14(_1617_t12, _1617_t13);
    $line_idx--;
    _1617_t15 = $add_int64_t(_1617_t7, _1617_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1617_t17 = &_1618_y;
    _1617_t18 = 12;
    _1617_t19 = (function4) _1613_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1617_t16 = _1617_t19(_1617_t17, _1617_t18);
    $line_idx--;
    _1617_t20 = $add_int64_t(_1617_t15, _1617_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1617_t22 = &_1618_y;
    _1617_t23 = 100;
    _1617_t24 = (function4) _1615_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1617_t21 = _1617_t24(_1617_t22, _1617_t23);
    $line_idx--;
    _1617_$retval = $add_int64_t(_1617_t20, _1617_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1617_$retval;
}

int64_t _1608_a(void* _1608_$self_ptr, int64_t _1608_x){
    int64_t _1608_$retval;
    (void)_1608_$self_ptr;
    _1608_$retval = _1608_x;
    return _1608_$retval;
}

int64_t _1610_b(void* _1610_self, int64_t _1610_x){
    int64_t _1610_$retval;
    (void)_1610_self;
    _1610_$retval = _1610_x;
    return _1610_$retval;
}

int64_t _1613_a(void* _1613_$self_ptr, int64_t _1613_x){
    int64_t _1614_self;
    int64_t _1613_$retval;
    _1614_self = *(int64_t*)_1613_$self_ptr;
    _1613_$retval = $add_int64_t(_1614_self, _1613_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1613_$retval;
}

int64_t _1615_b(void* _1615_self, int64_t _1615_x){
    int64_t _1615_$retval;
    *(int64_t*)_1615_self = _1615_x;
    _1615_$retval = _1615_x;
    return _1615_$retval;
}


int main(void) {
  printf("%ld",_1617_main());
  return 0;
}
