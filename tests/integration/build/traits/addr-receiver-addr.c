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
int64_t _8_main(void);
void _6_c(void* _6_self, int64_t _6_x);
int64_t _4_b(void* _4_self, int64_t _4_x);

/* Trait vtable implementations */
struct vtable_My_Trait _3_$vtable = {
    .b = _4_b,
    .c = _6_c,
};


/* Function definitions */
int64_t _8_main(void){
    int64_t _8_t1;
    int64_t _8_t2;
    struct struct0 _9_my_val;
    struct struct0* _9_my_val_ptr;
    int64_t _8_t6;
    int64_t _8_t9;
    int64_t _8_t7;
    int64_t _8_t10;
    int64_t _8_$retval;
    _8_t1 = 100;
    _8_t2 = 45;
    _9_my_val = (struct struct0) {_8_t1, _8_t2};
    _9_my_val_ptr = &_9_my_val;
    _8_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _3_$vtable.c(_9_my_val_ptr, _8_t6);
    $line_idx--;
    _8_t9 = 2;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _8_t7 = _3_$vtable.b(_9_my_val_ptr, _8_t9);
    $line_idx--;
    _8_t10 = 4;
    _8_$retval = $add_int64_t(_8_t7, _8_t10, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _8_$retval;
}

void _6_c(void* _6_self, int64_t _6_x){
    (*(struct struct0*)_6_self)._0 = $mult_int64_t((*(struct struct0*)_6_self)._0, _6_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _4_b(void* _4_self, int64_t _4_x){
    int64_t _4_t0;
    int64_t _4_$retval;
    _4_t0 = $mult_int64_t((*(struct struct0*)_4_self)._1, _4_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _4_$retval = $add_int64_t((*(struct struct0*)_4_self)._0, _4_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _4_$retval;
}


int main(void) {
  printf("%ld",_8_main());
  return 0;
}
