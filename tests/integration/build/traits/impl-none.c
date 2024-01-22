/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Trait vtable type definitions */
struct vtable_impl {
    int64_t(*a)(void*, int64_t);
    int64_t(*c)(void*, int64_t);
    int64_t(*d)(int64_t);
};

/* Function forward definitions */
int64_t _33_main(void);
int64_t _27_a(void* _27_$self_ptr, int64_t _27_x);
int64_t _29_c(void* _29_self, int64_t _29_x);
int64_t _31_d(int64_t _31_x);

/* Trait vtable implementations */
struct vtable_impl _26_$vtable = {
    .a = _27_a,
    .c = _29_c,
    .d = _31_d,
};


/* Function definitions */
int64_t _33_main(void){
    int64_t _33_t1;
    int64_t _33_t2;
    struct struct0 _34_my_val;
    struct struct0* _33_t5;
    int64_t _33_t6;
    int64_t _33_t3;
    int64_t _33_t7;
    int64_t _33_$retval;
    _33_t1 = 200;
    _33_t2 = 45;
    _34_my_val = (struct struct0) {_33_t1, _33_t2};
    _33_t5 = &_34_my_val;
    _33_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/impl-none.orng:14:13:\n    my_val.>a(2) + 2\n           ^";
    _33_t3 = _26_$vtable.a(_33_t5, _33_t6);
    $line_idx--;
    _33_t7 = 2;
    _33_$retval = $add_int64_t(_33_t3, _33_t7, "tests/integration/traits/impl-none.orng:14:19:\n    my_val.>a(2) + 2\n                 ^");
    return _33_$retval;
}

int64_t _27_a(void* _27_$self_ptr, int64_t _27_x){
    struct struct0 _28_self;
    int64_t _27_t0;
    int64_t _27_$retval;
    _28_self = *(struct struct0*)_27_$self_ptr;
    _27_t0 = $mult_int64_t(_28_self._1, _27_x, "tests/integration/traits/impl-none.orng:5:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _27_$retval = $add_int64_t(_28_self._0, _27_t0, "tests/integration/traits/impl-none.orng:5:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _27_$retval;
}

int64_t _29_c(void* _29_self, int64_t _29_x){
    int64_t _29_t0;
    int64_t _29_$retval;
    (*(struct struct0*)_29_self)._0 = _29_x;
    _29_t0 = $mult_int64_t((*(struct struct0*)_29_self)._1, _29_x, "tests/integration/traits/impl-none.orng:7:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _29_$retval = $add_int64_t((*(struct struct0*)_29_self)._0, _29_t0, "tests/integration/traits/impl-none.orng:7:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _29_$retval;
}

int64_t _31_d(int64_t _31_x){
    int64_t _31_t0;
    int64_t _31_$retval;
    _31_t0 = 4;
    _31_$retval = $add_int64_t(_31_x, _31_t0, "tests/integration/traits/impl-none.orng:9:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _31_$retval;
}


int main(void) {
  printf("%ld",_33_main());
  return 0;
}
