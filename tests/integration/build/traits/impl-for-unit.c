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
int64_t _1636_main(void);
int64_t _1627_a(void* _1627_$self_ptr, int64_t _1627_x);
int64_t _1629_b(void* _1629_self, int64_t _1629_x);
int64_t _1632_a(void* _1632_$self_ptr, int64_t _1632_x);
int64_t _1634_b(void* _1634_self, int64_t _1634_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _1636_main(void){
    int64_t _1637_y;
    void* _1636_t8;
    int64_t _1636_t9;
    function2 _1636_t10;
    int64_t _1636_t7;
    void* _1636_t12;
    int64_t _1636_t13;
    function2 _1636_t14;
    int64_t _1636_t11;
    int64_t _1636_t15;
    int64_t* _1636_t17;
    int64_t _1636_t18;
    function4 _1636_t19;
    int64_t _1636_t16;
    int64_t _1636_t20;
    int64_t* _1636_t22;
    int64_t _1636_t23;
    function4 _1636_t24;
    int64_t _1636_t21;
    int64_t _1636_$retval;
    _1637_y = 0;
    _1636_t8 = (void*) 0xAAAAAAAA;
    _1636_t9 = 100;
    _1636_t10 = (function2) _1627_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _1636_t7 = _1636_t10(_1636_t8, _1636_t9);
    $line_idx--;
    _1636_t12 = (void*) 0xAAAAAAAA;
    _1636_t13 = 100;
    _1636_t14 = (function2) _1629_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _1636_t11 = _1636_t14(_1636_t12, _1636_t13);
    $line_idx--;
    _1636_t15 = $add_int64_t(_1636_t7, _1636_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _1636_t17 = &_1637_y;
    _1636_t18 = 12;
    _1636_t19 = (function4) _1632_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _1636_t16 = _1636_t19(_1636_t17, _1636_t18);
    $line_idx--;
    _1636_t20 = $add_int64_t(_1636_t15, _1636_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _1636_t22 = &_1637_y;
    _1636_t23 = 100;
    _1636_t24 = (function4) _1634_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _1636_t21 = _1636_t24(_1636_t22, _1636_t23);
    $line_idx--;
    _1636_$retval = $add_int64_t(_1636_t20, _1636_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _1636_$retval;
}

int64_t _1627_a(void* _1627_$self_ptr, int64_t _1627_x){
    int64_t _1627_$retval;
    (void)_1627_$self_ptr;
    goto BB1849;
BB1849:
    _1627_$retval = _1627_x;
    return _1627_$retval;
}

int64_t _1629_b(void* _1629_self, int64_t _1629_x){
    int64_t _1629_$retval;
    (void)_1629_self;
    goto BB1851;
BB1851:
    _1629_$retval = _1629_x;
    return _1629_$retval;
}

int64_t _1632_a(void* _1632_$self_ptr, int64_t _1632_x){
    int64_t _1633_self;
    int64_t _1632_$retval;
    _1633_self = *(int64_t*)_1632_$self_ptr;
    _1632_$retval = $add_int64_t(_1633_self, _1632_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _1632_$retval;
}

int64_t _1634_b(void* _1634_self, int64_t _1634_x){
    int64_t _1634_$retval;
    *(int64_t*)_1634_self = _1634_x;
    _1634_$retval = _1634_x;
    return _1634_$retval;
}


int main(void) {
  printf("%ld",_1636_main());
  return 0;
}
