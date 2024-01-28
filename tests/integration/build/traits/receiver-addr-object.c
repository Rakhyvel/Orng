/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct dyn1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct dyn1 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*b)(void*, int64_t);
    void(*c)(void*, int64_t);
};

/* Function forward definitions */
int64_t _1577_main(void);
int64_t _1573_b(void* _1573_self, int64_t _1573_x);
void _1575_c(void* _1575_self, int64_t _1575_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1571_$vtable = {
    .b = _1573_b,
    .c = _1575_c,
};


/* Function definitions */
int64_t _1577_main(void){
    int64_t _1577_t1;
    int64_t _1577_t2;
    struct struct0 _1578_my_val;
    struct dyn1 _1577_t3;
    struct dyn1 _1578_my_dyn;
    int64_t _1577_t5;
    int64_t _1577_t7;
    int64_t _1577_t6;
    int64_t _1577_$retval;
    _1577_t1 = 100;
    _1577_t2 = 45;
    _1578_my_val = (struct struct0) {_1577_t1, _1577_t2};
    _1577_t3 = (struct dyn1) {&_1578_my_val, &_1571_$vtable};
    _1578_my_dyn = _1577_t3;
    _1577_t5 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:19:13:\n    my_dyn.>c(2)\n           ^";
    (void) _1578_my_dyn.vtable->c(_1578_my_dyn.data_ptr, _1577_t5);
    $line_idx--;
    _1577_t7 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:20:13:\n    my_dyn.>b(2)\n           ^";
    _1577_t6 = _1578_my_dyn.vtable->b(_1578_my_dyn.data_ptr, _1577_t7);
    $line_idx--;
    _1577_$retval = _1577_t6;
    return _1577_$retval;
}

int64_t _1573_b(void* _1573_self, int64_t _1573_x){
    int64_t _1573_t0;
    int64_t _1573_$retval;
    _1573_t0 = $mult_int64_t((*(struct struct0*)_1573_self)._1, _1573_x, "tests/integration/traits/receiver-addr-object.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1573_$retval = $add_int64_t((*(struct struct0*)_1573_self)._0, _1573_t0, "tests/integration/traits/receiver-addr-object.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1573_$retval;
}

void _1575_c(void* _1575_self, int64_t _1575_x){
    (*(struct struct0*)_1575_self)._0 = $mult_int64_t((*(struct struct0*)_1575_self)._0, _1575_x, "tests/integration/traits/receiver-addr-object.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}


int main(void) {
  printf("%ld",_1577_main());
  return 0;
}
