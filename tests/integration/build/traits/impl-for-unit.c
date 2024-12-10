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
int64_t _1698_main(void);
int64_t _1689_a(void* _1689_$self_ptr, int64_t _1689_x);
int64_t _1691_b(void* _1691_self, int64_t _1691_x);
int64_t _1694_a(void* _1694_$self_ptr, int64_t _1694_x);
int64_t _1696_b(void* _1696_self, int64_t _1696_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1698_main(void){
    int64_t _1699_y;
    void* _1698_t8;
    int64_t _1698_t9;
    function2 _1698_t10;
    int64_t _1698_t7;
    void* _1698_t12;
    int64_t _1698_t13;
    function2 _1698_t14;
    int64_t _1698_t11;
    int64_t _1698_t15;
    int64_t* _1698_t17;
    int64_t _1698_t18;
    function4 _1698_t19;
    int64_t _1698_t16;
    int64_t _1698_t20;
    int64_t* _1698_t22;
    int64_t _1698_t23;
    function4 _1698_t24;
    int64_t _1698_t21;
    int64_t _1698_$retval;
    _1699_y = 0;
    _1698_t8 = (void*) 0xAAAAAAAA;
    _1698_t9 = 100;
    _1698_t10 = (function2) _1689_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1698_t7 = _1698_t10(_1698_t8, _1698_t9);
    $line_idx--;
    _1698_t12 = (void*) 0xAAAAAAAA;
    _1698_t13 = 100;
    _1698_t14 = (function2) _1691_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1698_t11 = _1698_t14(_1698_t12, _1698_t13);
    $line_idx--;
    _1698_t15 = $add_int64_t(_1698_t7, _1698_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1698_t17 = &_1699_y;
    _1698_t18 = 12;
    _1698_t19 = (function4) _1694_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1698_t16 = _1698_t19(_1698_t17, _1698_t18);
    $line_idx--;
    _1698_t20 = $add_int64_t(_1698_t15, _1698_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1698_t22 = &_1699_y;
    _1698_t23 = 100;
    _1698_t24 = (function4) _1696_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1698_t21 = _1698_t24(_1698_t22, _1698_t23);
    $line_idx--;
    _1698_$retval = $add_int64_t(_1698_t20, _1698_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1698_$retval;
}

int64_t _1689_a(void* _1689_$self_ptr, int64_t _1689_x){
    int64_t _1689_$retval;
    (void)_1689_$self_ptr;
    goto BB1902;
BB1902:
    _1689_$retval = _1689_x;
    return _1689_$retval;
}

int64_t _1691_b(void* _1691_self, int64_t _1691_x){
    int64_t _1691_$retval;
    (void)_1691_self;
    goto BB1904;
BB1904:
    _1691_$retval = _1691_x;
    return _1691_$retval;
}

int64_t _1694_a(void* _1694_$self_ptr, int64_t _1694_x){
    int64_t _1695_self;
    int64_t _1694_$retval;
    _1695_self = *(int64_t*)_1694_$self_ptr;
    _1694_$retval = $add_int64_t(_1695_self, _1694_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1694_$retval;
}

int64_t _1696_b(void* _1696_self, int64_t _1696_x){
    int64_t _1696_$retval;
    *(int64_t*)_1696_self = _1696_x;
    _1696_$retval = _1696_x;
    return _1696_$retval;
}


int main(void) {
  printf("%ld",_1698_main());
  return 0;
}
