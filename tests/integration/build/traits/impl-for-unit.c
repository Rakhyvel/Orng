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
int64_t _60_main(void);
int64_t _51_a(void* _51_$self_ptr, int64_t _51_x);
int64_t _53_b(void* _53_self, int64_t _53_x);
int64_t _56_a(void* _56_$self_ptr, int64_t _56_x);
int64_t _58_b(void* _58_self, int64_t _58_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _60_main(void){
    int64_t _61_y;
    void* _60_t8;
    int64_t _60_t9;
    function2 _60_t10;
    int64_t _60_t7;
    void* _60_t12;
    int64_t _60_t13;
    function2 _60_t14;
    int64_t _60_t11;
    int64_t _60_t15;
    int64_t* _60_t17;
    int64_t _60_t18;
    function4 _60_t19;
    int64_t _60_t16;
    int64_t _60_t20;
    int64_t* _60_t22;
    int64_t _60_t23;
    function4 _60_t24;
    int64_t _60_t21;
    int64_t _60_$retval;
    _61_y = 0;
    _60_t8 = (void*) 0xAAAAAAAA;
    _60_t9 = 100;
    _60_t10 = (function2) _51_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:8:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n      ^";
    _60_t7 = _60_t10(_60_t8, _60_t9);
    $line_idx--;
    _60_t12 = (void*) 0xAAAAAAAA;
    _60_t13 = 100;
    _60_t14 = (function2) _53_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:20:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                  ^";
    _60_t11 = _60_t14(_60_t12, _60_t13);
    $line_idx--;
    _60_t15 = $add_int64_t(_60_t7, _60_t11, "tests/integration/traits/impl-for-unit.orng:39:16:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n              ^");
    _60_t17 = &_61_y;
    _60_t18 = 12;
    _60_t19 = (function4) _56_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:32:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                              ^";
    _60_t16 = _60_t19(_60_t17, _60_t18);
    $line_idx--;
    _60_t20 = $add_int64_t(_60_t15, _60_t16, "tests/integration/traits/impl-for-unit.orng:39:28:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                          ^");
    _60_t22 = &_61_y;
    _60_t23 = 100;
    _60_t24 = (function4) _58_b;
    $lines[$line_idx++] = "tests/integration/traits/impl-for-unit.orng:39:43:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                         ^";
    _60_t21 = _60_t24(_60_t22, _60_t23);
    $line_idx--;
    _60_$retval = $add_int64_t(_60_t20, _60_t21, "tests/integration/traits/impl-for-unit.orng:39:39:\n    x.>a(100) + x.>b(100) + y.>a(12) + y.>b(100)\n                                     ^");
    return _60_$retval;
}

int64_t _51_a(void* _51_$self_ptr, int64_t _51_x){
    int64_t _51_$retval;
    (void)_51_$self_ptr;
    goto BB26;
BB26:
    _51_$retval = _51_x;
    return _51_$retval;
}

int64_t _53_b(void* _53_self, int64_t _53_x){
    int64_t _53_$retval;
    (void)_53_self;
    goto BB28;
BB28:
    _53_$retval = _53_x;
    return _53_$retval;
}

int64_t _56_a(void* _56_$self_ptr, int64_t _56_x){
    int64_t _57_self;
    int64_t _56_$retval;
    _57_self = *(int64_t*)_56_$self_ptr;
    _56_$retval = $add_int64_t(_57_self, _56_x, "tests/integration/traits/impl-for-unit.orng:23:15:\n        self + x\n             ^");
    return _56_$retval;
}

int64_t _58_b(void* _58_self, int64_t _58_x){
    int64_t _58_$retval;
    *(int64_t*)_58_self = _58_x;
    _58_$retval = _58_x;
    return _58_$retval;
}


int main(void) {
  printf("%ld",_60_main());
  return 0;
}
