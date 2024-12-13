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
int64_t _1700_main(void);
int64_t _1691_a(void* _1691_$self_ptr, int64_t _1691_x);
int64_t _1693_b(void* _1693_self, int64_t _1693_x);
int64_t _1696_a(void* _1696_$self_ptr, int64_t _1696_x);
int64_t _1698_b(void* _1698_self, int64_t _1698_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1700_main(void){
    int64_t _1701_y;
    void* _1700_t8;
    int64_t _1700_t9;
    function2 _1700_t10;
    int64_t _1700_t7;
    void* _1700_t12;
    int64_t _1700_t13;
    function2 _1700_t14;
    int64_t _1700_t11;
    int64_t _1700_t15;
    int64_t* _1700_t17;
    int64_t _1700_t18;
    function4 _1700_t19;
    int64_t _1700_t16;
    int64_t _1700_t20;
    int64_t* _1700_t22;
    int64_t _1700_t23;
    function4 _1700_t24;
    int64_t _1700_t21;
    int64_t _1700_$retval;
    _1701_y = 0;
    _1700_t8 = (void*) 0xAAAAAAAA;
    _1700_t9 = 100;
    _1700_t10 = (function2) _1691_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1700_t7 = _1700_t10(_1700_t8, _1700_t9);
    $line_idx--;
    _1700_t12 = (void*) 0xAAAAAAAA;
    _1700_t13 = 100;
    _1700_t14 = (function2) _1693_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1700_t11 = _1700_t14(_1700_t12, _1700_t13);
    $line_idx--;
    _1700_t15 = $add_int64_t(_1700_t7, _1700_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1700_t17 = &_1701_y;
    _1700_t18 = 12;
    _1700_t19 = (function4) _1696_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1700_t16 = _1700_t19(_1700_t17, _1700_t18);
    $line_idx--;
    _1700_t20 = $add_int64_t(_1700_t15, _1700_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1700_t22 = &_1701_y;
    _1700_t23 = 100;
    _1700_t24 = (function4) _1698_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1700_t21 = _1700_t24(_1700_t22, _1700_t23);
    $line_idx--;
    _1700_$retval = $add_int64_t(_1700_t20, _1700_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1700_$retval;
}

int64_t _1691_a(void* _1691_$self_ptr, int64_t _1691_x){
    int64_t _1691_$retval;
    (void)_1691_$self_ptr;
    goto BB1904;
BB1904:
    _1691_$retval = _1691_x;
    return _1691_$retval;
}

int64_t _1693_b(void* _1693_self, int64_t _1693_x){
    int64_t _1693_$retval;
    (void)_1693_self;
    goto BB1906;
BB1906:
    _1693_$retval = _1693_x;
    return _1693_$retval;
}

int64_t _1696_a(void* _1696_$self_ptr, int64_t _1696_x){
    int64_t _1697_self;
    int64_t _1696_$retval;
    _1697_self = *(int64_t*)_1696_$self_ptr;
    _1696_$retval = $add_int64_t(_1697_self, _1696_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1696_$retval;
}

int64_t _1698_b(void* _1698_self, int64_t _1698_x){
    int64_t _1698_$retval;
    *(int64_t*)_1698_self = _1698_x;
    _1698_$retval = _1698_x;
    return _1698_$retval;
}


int main(void) {
  printf("%ld",_1700_main());
  return 0;
}
