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
int64_t _1605_main(void);
int64_t _1603_a(void* _1603_$self_ptr, int64_t _1603_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1601_$vtable = {
    .a = _1603_a,
};


/* Function definitions */
int64_t _1605_main(void){
    int64_t _1605_t1;
    int64_t _1605_t2;
    struct struct0 _1606_my_val;
    struct struct0* _1605_t5;
    int64_t _1605_t6;
    int64_t _1605_t3;
    int64_t _1605_t7;
    int64_t _1605_$retval;
    _1605_t1 = 200;
    _1605_t2 = 45;
    _1606_my_val = (struct struct0) {_1605_t1, _1605_t2};
    _1605_t5 = &_1606_my_val;
    _1605_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-basic.orng:14:13:\n    my_val.>a(2) - 1\n           ^";
    _1605_t3 = _1601_$vtable.a(_1605_t5, _1605_t6);
    $line_idx--;
    _1605_t7 = 1;
    _1605_$retval = $sub_int64_t(_1605_t3, _1605_t7, "tests/integration/traits/receiver-basic.orng:14:19:\n    my_val.>a(2) - 1\n                 ^");
    return _1605_$retval;
}

int64_t _1603_a(void* _1603_$self_ptr, int64_t _1603_x){
    struct struct0 _1604_self;
    int64_t _1603_t0;
    int64_t _1603_$retval;
    _1604_self = *(struct struct0*)_1603_$self_ptr;
    _1603_t0 = $mult_int64_t(_1604_self._1, _1603_x, "tests/integration/traits/receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1603_$retval = $add_int64_t(_1604_self._0, _1603_t0, "tests/integration/traits/receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1603_$retval;
}


int main(void) {
  printf("%ld",_1605_main());
  return 0;
}
