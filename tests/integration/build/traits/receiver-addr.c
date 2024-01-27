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
    int64_t(*b)(void*, int64_t);
    void(*c)(void*, int64_t);
};

/* Function forward definitions */
int64_t _51_main(void);
void _49_c(void* _49_self, int64_t _49_x);
int64_t _47_b(void* _47_self, int64_t _47_x);

/* Trait vtable implementations */
struct vtable_My_Trait _46_$vtable = {
    .b = _47_b,
    .c = _49_c,
};


/* Function definitions */
int64_t _51_main(void){
    int64_t _51_t1;
    int64_t _51_t2;
    struct struct0 _52_my_val;
    struct struct0* _51_t5;
    int64_t _51_t6;
    struct struct0* _51_t9;
    int64_t _51_t10;
    int64_t _51_t7;
    int64_t _51_$retval;
    _51_t1 = 100;
    _51_t2 = 45;
    _52_my_val = (struct struct0) {_51_t1, _51_t2};
    _51_t5 = &_52_my_val;
    _51_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _46_$vtable.c(_51_t5, _51_t6);
    $line_idx--;
    _51_t9 = &_52_my_val;
    _51_t10 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _51_t7 = _46_$vtable.b(_51_t9, _51_t10);
    $line_idx--;
    _51_$retval = _51_t7;
    return _51_$retval;
}

void _49_c(void* _49_self, int64_t _49_x){
    (*(struct struct0*)_49_self)._0 = $mult_int64_t((*(struct struct0*)_49_self)._0, _49_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _47_b(void* _47_self, int64_t _47_x){
    int64_t _47_t0;
    int64_t _47_$retval;
    _47_t0 = $mult_int64_t((*(struct struct0*)_47_self)._1, _47_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _47_$retval = $add_int64_t((*(struct struct0*)_47_self)._0, _47_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _47_$retval;
}


int main(void) {
  printf("%ld",_51_main());
  return 0;
}
