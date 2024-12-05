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
int64_t _1664_main(void);
int64_t _1655_a(void* _1655_$self_ptr, int64_t _1655_x);
int64_t _1657_b(void* _1657_self, int64_t _1657_x);
int64_t _1660_a(void* _1660_$self_ptr, int64_t _1660_x);
int64_t _1662_b(void* _1662_self, int64_t _1662_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1664_main(void){
    int64_t _1665_y;
    void* _1664_t8;
    int64_t _1664_t9;
    function2 _1664_t10;
    int64_t _1664_t7;
    void* _1664_t12;
    int64_t _1664_t13;
    function2 _1664_t14;
    int64_t _1664_t11;
    int64_t _1664_t15;
    int64_t* _1664_t17;
    int64_t _1664_t18;
    function4 _1664_t19;
    int64_t _1664_t16;
    int64_t _1664_t20;
    int64_t* _1664_t22;
    int64_t _1664_t23;
    function4 _1664_t24;
    int64_t _1664_t21;
    int64_t _1664_$retval;
    _1665_y = 0;
    _1664_t8 = (void*) 0xAAAAAAAA;
    _1664_t9 = 100;
    _1664_t10 = (function2) _1655_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1664_t7 = _1664_t10(_1664_t8, _1664_t9);
    $line_idx--;
    _1664_t12 = (void*) 0xAAAAAAAA;
    _1664_t13 = 100;
    _1664_t14 = (function2) _1657_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1664_t11 = _1664_t14(_1664_t12, _1664_t13);
    $line_idx--;
    _1664_t15 = $add_int64_t(_1664_t7, _1664_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1664_t17 = &_1665_y;
    _1664_t18 = 12;
    _1664_t19 = (function4) _1660_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1664_t16 = _1664_t19(_1664_t17, _1664_t18);
    $line_idx--;
    _1664_t20 = $add_int64_t(_1664_t15, _1664_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1664_t22 = &_1665_y;
    _1664_t23 = 100;
    _1664_t24 = (function4) _1662_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1664_t21 = _1664_t24(_1664_t22, _1664_t23);
    $line_idx--;
    _1664_$retval = $add_int64_t(_1664_t20, _1664_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1664_$retval;
}

int64_t _1655_a(void* _1655_$self_ptr, int64_t _1655_x){
    int64_t _1655_$retval;
    (void)_1655_$self_ptr;
    goto BB1864;
BB1864:
    _1655_$retval = _1655_x;
    return _1655_$retval;
}

int64_t _1657_b(void* _1657_self, int64_t _1657_x){
    int64_t _1657_$retval;
    (void)_1657_self;
    goto BB1866;
BB1866:
    _1657_$retval = _1657_x;
    return _1657_$retval;
}

int64_t _1660_a(void* _1660_$self_ptr, int64_t _1660_x){
    int64_t _1661_self;
    int64_t _1660_$retval;
    _1661_self = *(int64_t*)_1660_$self_ptr;
    _1660_$retval = $add_int64_t(_1661_self, _1660_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1660_$retval;
}

int64_t _1662_b(void* _1662_self, int64_t _1662_x){
    int64_t _1662_$retval;
    *(int64_t*)_1662_self = _1662_x;
    _1662_$retval = _1662_x;
    return _1662_$retval;
}


int main(void) {
  printf("%ld",_1664_main());
  return 0;
}
