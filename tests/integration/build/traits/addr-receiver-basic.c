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
int64_t _1547_main(void);
int64_t _1545_a(void* _1545_$self_ptr, int64_t _1545_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1543_$vtable = {
    .a = _1545_a,
};


/* Function definitions */
int64_t _1547_main(void){
    int64_t _1547_t1;
    int64_t _1547_t2;
    struct struct0 _1548_my_val;
    struct struct0* _1548_my_val_ptr;
    int64_t _1547_t6;
    int64_t _1547_t4;
    int64_t _1547_t7;
    int64_t _1547_$retval;
    _1547_t1 = 200;
    _1547_t2 = 45;
    _1548_my_val = (struct struct0) {_1547_t1, _1547_t2};
    _1548_my_val_ptr = &_1548_my_val;
    _1547_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-basic.orng:15:17:\n    my_val_ptr.>a(2) + 3\n               ^";
    _1547_t4 = _1543_$vtable.a(_1548_my_val_ptr, _1547_t6);
    $line_idx--;
    _1547_t7 = 3;
    _1547_$retval = $add_int64_t(_1547_t4, _1547_t7, "tests/integration/traits/addr-receiver-basic.orng:15:23:\n    my_val_ptr.>a(2) + 3\n                     ^");
    return _1547_$retval;
}

int64_t _1545_a(void* _1545_$self_ptr, int64_t _1545_x){
    struct struct0 _1546_self;
    int64_t _1545_t0;
    int64_t _1545_$retval;
    _1546_self = *(struct struct0*)_1545_$self_ptr;
    _1545_t0 = $mult_int64_t(_1546_self._1, _1545_x, "tests/integration/traits/addr-receiver-basic.orng:9:50:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    _1545_$retval = $add_int64_t(_1546_self._0, _1545_t0, "tests/integration/traits/addr-receiver-basic.orng:9:41:\n    fn a(self, x: Int) -> Int { self.x + self.y * x }\n                                       ^");
    return _1545_$retval;
}


int main(void) {
  printf("%ld",_1547_main());
  return 0;
}
