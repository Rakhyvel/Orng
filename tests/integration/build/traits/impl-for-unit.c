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
int64_t _1683_main(void);
int64_t _1674_a(void* _1674_$self_ptr, int64_t _1674_x);
int64_t _1676_b(void* _1676_self, int64_t _1676_x);
int64_t _1679_a(void* _1679_$self_ptr, int64_t _1679_x);
int64_t _1681_b(void* _1681_self, int64_t _1681_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1683_main(void){
    int64_t _1684_y;
    void* _1683_t8;
    int64_t _1683_t9;
    function2 _1683_t10;
    int64_t _1683_t7;
    void* _1683_t12;
    int64_t _1683_t13;
    function2 _1683_t14;
    int64_t _1683_t11;
    int64_t _1683_t15;
    int64_t* _1683_t17;
    int64_t _1683_t18;
    function4 _1683_t19;
    int64_t _1683_t16;
    int64_t _1683_t20;
    int64_t* _1683_t22;
    int64_t _1683_t23;
    function4 _1683_t24;
    int64_t _1683_t21;
    int64_t _1683_$retval;
    _1684_y = 0;
    _1683_t8 = (void*) 0xAAAAAAAA;
    _1683_t9 = 100;
    _1683_t10 = (function2) _1674_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1683_t7 = _1683_t10(_1683_t8, _1683_t9);
    $line_idx--;
    _1683_t12 = (void*) 0xAAAAAAAA;
    _1683_t13 = 100;
    _1683_t14 = (function2) _1676_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1683_t11 = _1683_t14(_1683_t12, _1683_t13);
    $line_idx--;
    _1683_t15 = $add_int64_t(_1683_t7, _1683_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1683_t17 = &_1684_y;
    _1683_t18 = 12;
    _1683_t19 = (function4) _1679_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1683_t16 = _1683_t19(_1683_t17, _1683_t18);
    $line_idx--;
    _1683_t20 = $add_int64_t(_1683_t15, _1683_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1683_t22 = &_1684_y;
    _1683_t23 = 100;
    _1683_t24 = (function4) _1681_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1683_t21 = _1683_t24(_1683_t22, _1683_t23);
    $line_idx--;
    _1683_$retval = $add_int64_t(_1683_t20, _1683_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1683_$retval;
}

int64_t _1674_a(void* _1674_$self_ptr, int64_t _1674_x){
    int64_t _1674_$retval;
    (void)_1674_$self_ptr;
    goto BB1886;
BB1886:
    _1674_$retval = _1674_x;
    return _1674_$retval;
}

int64_t _1676_b(void* _1676_self, int64_t _1676_x){
    int64_t _1676_$retval;
    (void)_1676_self;
    goto BB1888;
BB1888:
    _1676_$retval = _1676_x;
    return _1676_$retval;
}

int64_t _1679_a(void* _1679_$self_ptr, int64_t _1679_x){
    int64_t _1680_self;
    int64_t _1679_$retval;
    _1680_self = *(int64_t*)_1679_$self_ptr;
    _1679_$retval = $add_int64_t(_1680_self, _1679_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1679_$retval;
}

int64_t _1681_b(void* _1681_self, int64_t _1681_x){
    int64_t _1681_$retval;
    *(int64_t*)_1681_self = _1681_x;
    _1681_$retval = _1681_x;
    return _1681_$retval;
}


int main(void) {
  printf("%ld",_1683_main());
  return 0;
}
