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
int64_t _1648_main(void);
int64_t _1639_a(void* _1639_$self_ptr, int64_t _1639_x);
int64_t _1641_b(void* _1641_self, int64_t _1641_x);
int64_t _1644_a(void* _1644_$self_ptr, int64_t _1644_x);
int64_t _1646_b(void* _1646_self, int64_t _1646_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1648_main(void){
    int64_t _1649_y;
    void* _1648_t8;
    int64_t _1648_t9;
    function2 _1648_t10;
    int64_t _1648_t7;
    void* _1648_t12;
    int64_t _1648_t13;
    function2 _1648_t14;
    int64_t _1648_t11;
    int64_t _1648_t15;
    int64_t* _1648_t17;
    int64_t _1648_t18;
    function4 _1648_t19;
    int64_t _1648_t16;
    int64_t _1648_t20;
    int64_t* _1648_t22;
    int64_t _1648_t23;
    function4 _1648_t24;
    int64_t _1648_t21;
    int64_t _1648_$retval;
    _1649_y = 0;
    _1648_t8 = (void*) 0xAAAAAAAA;
    _1648_t9 = 100;
    _1648_t10 = (function2) _1639_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1648_t7 = _1648_t10(_1648_t8, _1648_t9);
    $line_idx--;
    _1648_t12 = (void*) 0xAAAAAAAA;
    _1648_t13 = 100;
    _1648_t14 = (function2) _1641_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1648_t11 = _1648_t14(_1648_t12, _1648_t13);
    $line_idx--;
    _1648_t15 = $add_int64_t(_1648_t7, _1648_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1648_t17 = &_1649_y;
    _1648_t18 = 12;
    _1648_t19 = (function4) _1644_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1648_t16 = _1648_t19(_1648_t17, _1648_t18);
    $line_idx--;
    _1648_t20 = $add_int64_t(_1648_t15, _1648_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1648_t22 = &_1649_y;
    _1648_t23 = 100;
    _1648_t24 = (function4) _1646_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1648_t21 = _1648_t24(_1648_t22, _1648_t23);
    $line_idx--;
    _1648_$retval = $add_int64_t(_1648_t20, _1648_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1648_$retval;
}

int64_t _1639_a(void* _1639_$self_ptr, int64_t _1639_x){
    int64_t _1639_$retval;
    (void)_1639_$self_ptr;
    goto BB1853;
BB1853:
    _1639_$retval = _1639_x;
    return _1639_$retval;
}

int64_t _1641_b(void* _1641_self, int64_t _1641_x){
    int64_t _1641_$retval;
    (void)_1641_self;
    goto BB1855;
BB1855:
    _1641_$retval = _1641_x;
    return _1641_$retval;
}

int64_t _1644_a(void* _1644_$self_ptr, int64_t _1644_x){
    int64_t _1645_self;
    int64_t _1644_$retval;
    _1645_self = *(int64_t*)_1644_$self_ptr;
    _1644_$retval = $add_int64_t(_1645_self, _1644_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1644_$retval;
}

int64_t _1646_b(void* _1646_self, int64_t _1646_x){
    int64_t _1646_$retval;
    *(int64_t*)_1646_self = _1646_x;
    _1646_$retval = _1646_x;
    return _1646_$retval;
}


int main(void) {
  printf("%ld",_1648_main());
  return 0;
}
