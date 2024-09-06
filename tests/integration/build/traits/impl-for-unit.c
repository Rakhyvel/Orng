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
int64_t _1643_main(void);
int64_t _1634_a(void* _1634_$self_ptr, int64_t _1634_x);
int64_t _1636_b(void* _1636_self, int64_t _1636_x);
int64_t _1639_a(void* _1639_$self_ptr, int64_t _1639_x);
int64_t _1641_b(void* _1641_self, int64_t _1641_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1643_main(void){
    int64_t _1644_y;
    void* _1643_t8;
    int64_t _1643_t9;
    function2 _1643_t10;
    int64_t _1643_t7;
    void* _1643_t12;
    int64_t _1643_t13;
    function2 _1643_t14;
    int64_t _1643_t11;
    int64_t _1643_t15;
    int64_t* _1643_t17;
    int64_t _1643_t18;
    function4 _1643_t19;
    int64_t _1643_t16;
    int64_t _1643_t20;
    int64_t* _1643_t22;
    int64_t _1643_t23;
    function4 _1643_t24;
    int64_t _1643_t21;
    int64_t _1643_$retval;
    _1644_y = 0;
    _1643_t8 = (void*) 0xAAAAAAAA;
    _1643_t9 = 100;
    _1643_t10 = (function2) _1634_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1643_t7 = _1643_t10(_1643_t8, _1643_t9);
    $line_idx--;
    _1643_t12 = (void*) 0xAAAAAAAA;
    _1643_t13 = 100;
    _1643_t14 = (function2) _1636_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1643_t11 = _1643_t14(_1643_t12, _1643_t13);
    $line_idx--;
    _1643_t15 = $add_int64_t(_1643_t7, _1643_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1643_t17 = &_1644_y;
    _1643_t18 = 12;
    _1643_t19 = (function4) _1639_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1643_t16 = _1643_t19(_1643_t17, _1643_t18);
    $line_idx--;
    _1643_t20 = $add_int64_t(_1643_t15, _1643_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1643_t22 = &_1644_y;
    _1643_t23 = 100;
    _1643_t24 = (function4) _1641_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1643_t21 = _1643_t24(_1643_t22, _1643_t23);
    $line_idx--;
    _1643_$retval = $add_int64_t(_1643_t20, _1643_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1643_$retval;
}

int64_t _1634_a(void* _1634_$self_ptr, int64_t _1634_x){
    int64_t _1634_$retval;
    (void)_1634_$self_ptr;
    goto BB1853;
BB1853:
    _1634_$retval = _1634_x;
    return _1634_$retval;
}

int64_t _1636_b(void* _1636_self, int64_t _1636_x){
    int64_t _1636_$retval;
    (void)_1636_self;
    goto BB1855;
BB1855:
    _1636_$retval = _1636_x;
    return _1636_$retval;
}

int64_t _1639_a(void* _1639_$self_ptr, int64_t _1639_x){
    int64_t _1640_self;
    int64_t _1639_$retval;
    _1640_self = *(int64_t*)_1639_$self_ptr;
    _1639_$retval = $add_int64_t(_1640_self, _1639_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1639_$retval;
}

int64_t _1641_b(void* _1641_self, int64_t _1641_x){
    int64_t _1641_$retval;
    *(int64_t*)_1641_self = _1641_x;
    _1641_$retval = _1641_x;
    return _1641_$retval;
}


int main(void) {
  printf("%ld",_1643_main());
  return 0;
}
