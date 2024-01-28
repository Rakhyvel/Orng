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
int64_t _1587_main(void);
void _1585_c(void* _1585_self, int64_t _1585_x);
int64_t _1583_b(void* _1583_self, int64_t _1583_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1581_$vtable = {
    .b = _1583_b,
    .c = _1585_c,
};


/* Function definitions */
int64_t _1587_main(void){
    int64_t _1587_t1;
    int64_t _1587_t2;
    struct struct0 _1588_my_val;
    struct struct0* _1587_t5;
    int64_t _1587_t6;
    struct struct0* _1587_t9;
    int64_t _1587_t10;
    int64_t _1587_t7;
    int64_t _1587_$retval;
    _1587_t1 = 100;
    _1587_t2 = 45;
    _1588_my_val = (struct struct0) {_1587_t1, _1587_t2};
    _1587_t5 = &_1588_my_val;
    _1587_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _1581_$vtable.c(_1587_t5, _1587_t6);
    $line_idx--;
    _1587_t9 = &_1588_my_val;
    _1587_t10 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _1587_t7 = _1581_$vtable.b(_1587_t9, _1587_t10);
    $line_idx--;
    _1587_$retval = _1587_t7;
    return _1587_$retval;
}

void _1585_c(void* _1585_self, int64_t _1585_x){
    (*(struct struct0*)_1585_self)._0 = $mult_int64_t((*(struct struct0*)_1585_self)._0, _1585_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1583_b(void* _1583_self, int64_t _1583_x){
    int64_t _1583_t0;
    int64_t _1583_$retval;
    _1583_t0 = $mult_int64_t((*(struct struct0*)_1583_self)._1, _1583_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1583_$retval = $add_int64_t((*(struct struct0*)_1583_self)._0, _1583_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1583_$retval;
}


int main(void) {
  printf("%ld",_1587_main());
  return 0;
}
