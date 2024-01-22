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
struct vtable_My_Trait {
    int64_t(*a)(void*, int64_t);
    int64_t(*b)(void*, int64_t);
    int64_t(*c)(void*, int64_t);
    int64_t(*d)(int64_t);
};

/* Function forward definitions */
int64_t _12_main(void);
int64_t _4_a(void* _4_$self_ptr, int64_t _4_x);
int64_t _6_b(void* _6_self, int64_t _6_x);
int64_t _8_c(void* _8_self, int64_t _8_x);
int64_t _10_d(int64_t _10_x);

/* Trait vtable implementations */
struct vtable_My_Trait _3_$vtable = {
    .a = _4_a,
    .b = _6_b,
    .c = _8_c,
    .d = _10_d,
};


/* Function definitions */
int64_t _12_main(void){
    int64_t _12_t1;
    int64_t _12_t2;
    struct struct0 _13_my_val;
    struct struct0* _12_t5;
    int64_t _12_t6;
    int64_t _12_t3;
    int64_t _12_t7;
    int64_t _12_$retval;
    _12_t1 = 200;
    _12_t2 = 45;
    _13_my_val = (struct struct0) {_12_t1, _12_t2};
    _12_t5 = &_13_my_val;
    _12_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/basic-trait-impl.orng:30:13:\n    my_val.>a(2) - 1\n           ^";
    _12_t3 = _3_$vtable.a(_12_t5, _12_t6);
    $line_idx--;
    _12_t7 = 1;
    _12_$retval = $sub_int64_t(_12_t3, _12_t7, "tests/integration/traits/basic-trait-impl.orng:30:19:\n    my_val.>a(2) - 1\n                 ^");
    return _12_$retval;
}

int64_t _4_a(void* _4_$self_ptr, int64_t _4_x){
    struct struct0 _5_self;
    int64_t _4_t0;
    int64_t _4_$retval;
    _5_self = *(struct struct0*)_4_$self_ptr;
    _4_t0 = $mult_int64_t(_5_self._1, _4_x, "tests/integration/traits/basic-trait-impl.orng:19:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _4_$retval = $add_int64_t(_5_self._0, _4_t0, "tests/integration/traits/basic-trait-impl.orng:19:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _4_$retval;
}

int64_t _6_b(void* _6_self, int64_t _6_x){
    int64_t _6_t0;
    int64_t _6_$retval;
    _6_t0 = $mult_int64_t((*(struct struct0*)_6_self)._1, _6_x, "tests/integration/traits/basic-trait-impl.orng:21:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _6_$retval = $add_int64_t((*(struct struct0*)_6_self)._0, _6_t0, "tests/integration/traits/basic-trait-impl.orng:21:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _6_$retval;
}

int64_t _8_c(void* _8_self, int64_t _8_x){
    int64_t _8_t0;
    int64_t _8_$retval;
    (*(struct struct0*)_8_self)._0 = _8_x;
    _8_t0 = $mult_int64_t((*(struct struct0*)_8_self)._1, _8_x, "tests/integration/traits/basic-trait-impl.orng:23:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _8_$retval = $add_int64_t((*(struct struct0*)_8_self)._0, _8_t0, "tests/integration/traits/basic-trait-impl.orng:23:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _8_$retval;
}

int64_t _10_d(int64_t _10_x){
    int64_t _10_t0;
    int64_t _10_$retval;
    _10_t0 = 4;
    _10_$retval = $add_int64_t(_10_x, _10_t0, "tests/integration/traits/basic-trait-impl.orng:25:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _10_$retval;
}


int main(void) {
  printf("%ld",_12_main());
  return 0;
}
