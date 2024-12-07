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
int64_t _1678_main(void);
int64_t _1669_a(void* _1669_$self_ptr, int64_t _1669_x);
int64_t _1671_b(void* _1671_self, int64_t _1671_x);
int64_t _1674_a(void* _1674_$self_ptr, int64_t _1674_x);
int64_t _1676_b(void* _1676_self, int64_t _1676_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1678_main(void){
    int64_t _1679_y;
    void* _1678_t8;
    int64_t _1678_t9;
    function2 _1678_t10;
    int64_t _1678_t7;
    void* _1678_t12;
    int64_t _1678_t13;
    function2 _1678_t14;
    int64_t _1678_t11;
    int64_t _1678_t15;
    int64_t* _1678_t17;
    int64_t _1678_t18;
    function4 _1678_t19;
    int64_t _1678_t16;
    int64_t _1678_t20;
    int64_t* _1678_t22;
    int64_t _1678_t23;
    function4 _1678_t24;
    int64_t _1678_t21;
    int64_t _1678_$retval;
    _1679_y = 0;
    _1678_t8 = (void*) 0xAAAAAAAA;
    _1678_t9 = 100;
    _1678_t10 = (function2) _1669_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1678_t7 = _1678_t10(_1678_t8, _1678_t9);
    $line_idx--;
    _1678_t12 = (void*) 0xAAAAAAAA;
    _1678_t13 = 100;
    _1678_t14 = (function2) _1671_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1678_t11 = _1678_t14(_1678_t12, _1678_t13);
    $line_idx--;
    _1678_t15 = $add_int64_t(_1678_t7, _1678_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1678_t17 = &_1679_y;
    _1678_t18 = 12;
    _1678_t19 = (function4) _1674_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1678_t16 = _1678_t19(_1678_t17, _1678_t18);
    $line_idx--;
    _1678_t20 = $add_int64_t(_1678_t15, _1678_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1678_t22 = &_1679_y;
    _1678_t23 = 100;
    _1678_t24 = (function4) _1676_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1678_t21 = _1678_t24(_1678_t22, _1678_t23);
    $line_idx--;
    _1678_$retval = $add_int64_t(_1678_t20, _1678_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1678_$retval;
}

int64_t _1669_a(void* _1669_$self_ptr, int64_t _1669_x){
    int64_t _1669_$retval;
    (void)_1669_$self_ptr;
    goto BB1883;
BB1883:
    _1669_$retval = _1669_x;
    return _1669_$retval;
}

int64_t _1671_b(void* _1671_self, int64_t _1671_x){
    int64_t _1671_$retval;
    (void)_1671_self;
    goto BB1885;
BB1885:
    _1671_$retval = _1671_x;
    return _1671_$retval;
}

int64_t _1674_a(void* _1674_$self_ptr, int64_t _1674_x){
    int64_t _1675_self;
    int64_t _1674_$retval;
    _1675_self = *(int64_t*)_1674_$self_ptr;
    _1674_$retval = $add_int64_t(_1675_self, _1674_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1674_$retval;
}

int64_t _1676_b(void* _1676_self, int64_t _1676_x){
    int64_t _1676_$retval;
    *(int64_t*)_1676_self = _1676_x;
    _1676_$retval = _1676_x;
    return _1676_$retval;
}


int main(void) {
  printf("%ld",_1678_main());
  return 0;
}
