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
int64_t _15_main(void);
int64_t _13_a(void* _13_$self_ptr, int64_t _13_x);

/* Trait vtable implementations */
struct vtable_My_Trait _12_$vtable = {
    .a = _13_a,
};


/* Function definitions */
int64_t _15_main(void){
    int64_t _15_t1;
    int64_t _15_t2;
    struct struct0 _16_my_val;
    struct struct0* _16_my_val_ptr;
    int64_t _15_t6;
    int64_t _15_t4;
    int64_t _15_t7;
    int64_t _15_$retval;
    _15_t1 = 200;
    _15_t2 = 45;
    _16_my_val = (struct struct0) {_15_t1, _15_t2};
    _16_my_val_ptr = &_16_my_val;
    _15_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-basic.orng:15:17:\n    my_val_ptr.>a(2) + 3\n               ^";
    _15_t4 = _12_$vtable.a(_16_my_val_ptr, _15_t6);
    $line_idx--;
    _15_t7 = 3;
    _15_$retval = $add_int64_t(_15_t4, _15_t7, "tests/integration/traits/addr-receiver-basic.orng:15:23:\n    my_val_ptr.>a(2) + 3\n                     ^");
    return _15_$retval;
}

int64_t _13_a(void* _13_$self_ptr, int64_t _13_x){
    struct struct0 _14_self;
    int64_t _13_t0;
    int64_t _13_$retval;
    _14_self = *(struct struct0*)_13_$self_ptr;
    _13_t0 = $mult_int64_t(_14_self._1, _13_x, "tests/integration/traits/addr-receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _13_$retval = $add_int64_t(_14_self._0, _13_t0, "tests/integration/traits/addr-receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _13_$retval;
}


int main(void) {
  printf("%ld",_15_main());
  return 0;
}
