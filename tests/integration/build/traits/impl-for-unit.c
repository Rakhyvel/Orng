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
int64_t _1564_main(void);
int64_t _1555_a(void* _1555_$self_ptr, int64_t _1555_x);
int64_t _1557_b(void* _1557_self, int64_t _1557_x);
int64_t _1560_a(void* _1560_$self_ptr, int64_t _1560_x);
int64_t _1562_b(void* _1562_self, int64_t _1562_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1564_main(void){
    int64_t _1565_y;
    void* _1564_t8;
    int64_t _1564_t9;
    function2 _1564_t10;
    int64_t _1564_t7;
    void* _1564_t12;
    int64_t _1564_t13;
    function2 _1564_t14;
    int64_t _1564_t11;
    int64_t _1564_t15;
    int64_t* _1564_t17;
    int64_t _1564_t18;
    function4 _1564_t19;
    int64_t _1564_t16;
    int64_t _1564_t20;
    int64_t* _1564_t22;
    int64_t _1564_t23;
    function4 _1564_t24;
    int64_t _1564_t21;
    int64_t _1564_$retval;
    _1565_y = 0;
    _1564_t8 = (void*) 0xAAAAAAAA;
    _1564_t9 = 100;
    _1564_t10 = (function2) _1555_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1564_t7 = _1564_t10(_1564_t8, _1564_t9);
    $line_idx--;
    _1564_t12 = (void*) 0xAAAAAAAA;
    _1564_t13 = 100;
    _1564_t14 = (function2) _1557_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1564_t11 = _1564_t14(_1564_t12, _1564_t13);
    $line_idx--;
    _1564_t15 = $add_int64_t(_1564_t7, _1564_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1564_t17 = &_1565_y;
    _1564_t18 = 12;
    _1564_t19 = (function4) _1560_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1564_t16 = _1564_t19(_1564_t17, _1564_t18);
    $line_idx--;
    _1564_t20 = $add_int64_t(_1564_t15, _1564_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1564_t22 = &_1565_y;
    _1564_t23 = 100;
    _1564_t24 = (function4) _1562_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1564_t21 = _1564_t24(_1564_t22, _1564_t23);
    $line_idx--;
    _1564_$retval = $add_int64_t(_1564_t20, _1564_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1564_$retval;
}

int64_t _1555_a(void* _1555_$self_ptr, int64_t _1555_x){
    int64_t _1555_$retval;
    (void)_1555_$self_ptr;
    _1555_$retval = _1555_x;
    return _1555_$retval;
}

int64_t _1557_b(void* _1557_self, int64_t _1557_x){
    int64_t _1557_$retval;
    (void)_1557_self;
    _1557_$retval = _1557_x;
    return _1557_$retval;
}

int64_t _1560_a(void* _1560_$self_ptr, int64_t _1560_x){
    int64_t _1561_self;
    int64_t _1560_$retval;
    _1561_self = *(int64_t*)_1560_$self_ptr;
    _1560_$retval = $add_int64_t(_1561_self, _1560_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1560_$retval;
}

int64_t _1562_b(void* _1562_self, int64_t _1562_x){
    int64_t _1562_$retval;
    *(int64_t*)_1562_self = _1562_x;
    _1562_$retval = _1562_x;
    return _1562_$retval;
}


int main(void) {
  printf("%ld",_1564_main());
  return 0;
}
