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
};

/* Function forward definitions */
int64_t _67_main(void);
int64_t _65_a(void* _65_$self_ptr, int64_t _65_x);

/* Trait vtable implementations */
struct vtable_My_Trait _64_$vtable = {
    .a = _65_a,
};


/* Function definitions */
int64_t _67_main(void){
    int64_t _67_t1;
    int64_t _67_t2;
    struct struct0 _68_my_val;
    struct struct0* _67_t5;
    int64_t _67_t6;
    int64_t _67_t3;
    int64_t _67_t7;
    int64_t _67_$retval;
    _67_t1 = 200;
    _67_t2 = 45;
    _68_my_val = (struct struct0) {_67_t1, _67_t2};
    _67_t5 = &_68_my_val;
    _67_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _67_t3 = _64_$vtable.a(_67_t5, _67_t6);
    $line_idx--;
    _67_t7 = 1;
    _67_$retval = $sub_int64_t(_67_t3, _67_t7, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _67_$retval;
}

int64_t _65_a(void* _65_$self_ptr, int64_t _65_x){
    struct struct0 _66_self;
    int64_t _65_t0;
    int64_t _65_$retval;
    _66_self = *(struct struct0*)_65_$self_ptr;
    _65_t0 = $mult_int64_t(_66_self._1, _65_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _65_$retval = $add_int64_t(_66_self._0, _65_t0, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _65_$retval;
}


int main(void) {
  printf("%ld",_67_main());
  return 0;
}
