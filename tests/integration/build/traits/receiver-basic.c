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
int64_t _49_main(void);
int64_t _47_a(void* _47_$self_ptr, int64_t _47_x);

/* Trait vtable implementations */
struct vtable_My_Trait _46_$vtable = {
    .a = _47_a,
};


/* Function definitions */
int64_t _49_main(void){
    int64_t _49_t1;
    int64_t _49_t2;
    struct struct0 _50_my_val;
    struct struct0* _49_t5;
    int64_t _49_t6;
    int64_t _49_t3;
    int64_t _49_t7;
    int64_t _49_$retval;
    _49_t1 = 200;
    _49_t2 = 45;
    _50_my_val = (struct struct0) {_49_t1, _49_t2};
    _49_t5 = &_50_my_val;
    _49_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _49_t3 = _46_$vtable.a(_49_t5, _49_t6);
    $line_idx--;
    _49_t7 = 1;
    _49_$retval = $sub_int64_t(_49_t3, _49_t7, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _49_$retval;
}

int64_t _47_a(void* _47_$self_ptr, int64_t _47_x){
    struct struct0 _48_self;
    int64_t _47_t0;
    int64_t _47_$retval;
    _48_self = *(struct struct0*)_47_$self_ptr;
    _47_t0 = $mult_int64_t(_48_self._1, _47_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _47_$retval = $add_int64_t(_48_self._0, _47_t0, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _47_$retval;
}


int main(void) {
  printf("%ld",_49_main());
  return 0;
}
