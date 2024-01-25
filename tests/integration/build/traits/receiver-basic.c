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
int64_t _1579_main(void);
int64_t _1577_a(void* _1577_$self_ptr, int64_t _1577_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1576_$vtable = {
    .a = _1577_a,
};


/* Function definitions */
int64_t _1579_main(void){
    int64_t _1579_t1;
    int64_t _1579_t2;
    struct struct0 _1580_my_val;
    struct struct0* _1579_t5;
    int64_t _1579_t6;
    int64_t _1579_t3;
    int64_t _1579_t7;
    int64_t _1579_$retval;
    _1579_t1 = 200;
    _1579_t2 = 45;
    _1580_my_val = (struct struct0) {_1579_t1, _1579_t2};
    _1579_t5 = &_1580_my_val;
    _1579_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _1579_t3 = _1576_$vtable.a(_1579_t5, _1579_t6);
    $line_idx--;
    _1579_t7 = 1;
    _1579_$retval = $sub_int64_t(_1579_t3, _1579_t7, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _1579_$retval;
}

int64_t _1577_a(void* _1577_$self_ptr, int64_t _1577_x){
    struct struct0 _1578_self;
    int64_t _1577_t0;
    int64_t _1577_$retval;
    _1578_self = *(struct struct0*)_1577_$self_ptr;
    _1577_t0 = $mult_int64_t(_1578_self._1, _1577_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1577_$retval = $add_int64_t(_1578_self._0, _1577_t0, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1577_$retval;
}


int main(void) {
  printf("%ld",_1579_main());
  return 0;
}
