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
    int64_t(*c)(void*, int64_t);
    int64_t(*d)(int64_t);
};

/* Function forward definitions */
int64_t _19_main(void);
int64_t _13_a(void* _13_$self_ptr, int64_t _13_x);
int64_t _15_c(void* _15_self, int64_t _15_x);
int64_t _17_d(int64_t _17_x);

/* Trait vtable implementations */
struct vtable_My_Trait _12_$vtable = {
    .a = _13_a,
    .c = _15_c,
    .d = _17_d,
};


/* Function definitions */
int64_t _19_main(void){
    int64_t _19_t1;
    int64_t _19_t2;
    struct struct0 _20_my_val;
    struct struct0* _19_t5;
    int64_t _19_t6;
    int64_t _19_t3;
    int64_t _19_t7;
    int64_t _19_$retval;
    _19_t1 = 200;
    _19_t2 = 45;
    _20_my_val = (struct struct0) {_19_t1, _19_t2};
    _19_t5 = &_20_my_val;
    _19_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:24:13:\n    my_val.>a(2) - 1\n           ^";
    _19_t3 = _12_$vtable.a(_19_t5, _19_t6);
    $line_idx--;
    _19_t7 = 1;
    _19_$retval = $sub_int64_t(_19_t3, _19_t7, "tests/integration/traits/receiver-basic.orng:24:19:\n    my_val.>a(2) - 1\n                 ^");
    return _19_$retval;
}

int64_t _13_a(void* _13_$self_ptr, int64_t _13_x){
    struct struct0 _14_self;
    int64_t _13_t0;
    int64_t _13_$retval;
    _14_self = *(struct struct0*)_13_$self_ptr;
    _13_t0 = $mult_int64_t(_14_self._1, _13_x, "tests/integration/traits/receiver-basic.orng:15:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _13_$retval = $add_int64_t(_14_self._0, _13_t0, "tests/integration/traits/receiver-basic.orng:15:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _13_$retval;
}

int64_t _15_c(void* _15_self, int64_t _15_x){
    int64_t _15_t0;
    int64_t _15_$retval;
    (*(struct struct0*)_15_self)._0 = _15_x;
    _15_t0 = $mult_int64_t((*(struct struct0*)_15_self)._1, _15_x, "tests/integration/traits/receiver-basic.orng:17:67:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                                 ^");
    _15_$retval = $add_int64_t((*(struct struct0*)_15_self)._0, _15_t0, "tests/integration/traits/receiver-basic.orng:17:58:\n    fn c(&mut self, x: Int) -> Int { self.x = x; self.x + self.y * x }\n                                                        ^");
    return _15_$retval;
}

int64_t _17_d(int64_t _17_x){
    int64_t _17_t0;
    int64_t _17_$retval;
    _17_t0 = 4;
    _17_$retval = $add_int64_t(_17_x, _17_t0, "tests/integration/traits/receiver-basic.orng:19:30:\n    fn d(x: Int) -> Int { x + 4 }\n                            ^");
    return _17_$retval;
}


int main(void) {
  printf("%ld",_19_main());
  return 0;
}
