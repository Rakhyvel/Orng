/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;

/* Struct, union, and function definitions */
struct struct1 {
    struct struct3* _0;
    int64_t _1;
};

typedef int64_t(*function0)(struct struct3*, int64_t);

typedef int64_t(*function2)(int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _37_main(void);
int64_t _31_a(void* _31_$self_ptr, int64_t _31_x);
int64_t _33_c(void* _33_self, int64_t _33_x);
int64_t _35_d(int64_t _35_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _37_main(void){
    int64_t _37_t1;
    int64_t _37_t2;
    struct struct3 _38_my_val;
    struct struct3* _37_t4;
    int64_t _37_t5;
    function0 _37_t6;
    int64_t _37_t3;
    int64_t _37_t7;
    int64_t _37_$retval;
    _37_t1 = 200;
    _37_t2 = 45;
    _38_my_val = (struct struct3) {_37_t1, _37_t2};
    _37_t4 = &_38_my_val;
    _37_t5 = 2;
    _37_t6 = (function0) _31_a;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _37_t3 = _37_t6(_37_t4, _37_t5);
    $line_idx--;
    _37_t7 = 2;
    _37_$retval = $add_int64_t(_37_t3, _37_t7, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _37_$retval;
}

int64_t _31_a(void* _31_$self_ptr, int64_t _31_x){
    struct struct3 _32_self;
    int64_t _31_t0;
    int64_t _31_$retval;
    _32_self = *(struct struct3*)_31_$self_ptr;
    _31_t0 = $mult_int64_t(_32_self._1, _31_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _31_$retval = $add_int64_t(_32_self._0, _31_t0, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _31_$retval;
}

int64_t _33_c(void* _33_self, int64_t _33_x){
    int64_t _33_t0;
    int64_t _33_$retval;
    (*(struct struct3*)_33_self)._0 = _33_x;
    _33_t0 = $mult_int64_t((*(struct struct3*)_33_self)._1, _33_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _33_$retval = $add_int64_t((*(struct struct3*)_33_self)._0, _33_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _33_$retval;
}

int64_t _35_d(int64_t _35_x){
    int64_t _35_t0;
    int64_t _35_$retval;
    _35_t0 = 4;
    _35_$retval = $add_int64_t(_35_x, _35_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _35_$retval;
}


int main(void) {
  printf("%ld",_37_main());
  return 0;
}
