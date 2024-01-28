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
int64_t _1539_main(void);
void _1537_c(void* _1537_self, int64_t _1537_x);
int64_t _1535_b(void* _1535_self, int64_t _1535_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1533_$vtable = {
    .b = _1535_b,
    .c = _1537_c,
};


/* Function definitions */
int64_t _1539_main(void){
    int64_t _1539_t1;
    int64_t _1539_t2;
    struct struct0 _1540_my_val;
    struct struct0* _1540_my_val_ptr;
    int64_t _1539_t6;
    int64_t _1539_t9;
    int64_t _1539_t7;
    int64_t _1539_t10;
    int64_t _1539_$retval;
    _1539_t1 = 100;
    _1539_t2 = 45;
    _1540_my_val = (struct struct0) {_1539_t1, _1539_t2};
    _1540_my_val_ptr = &_1540_my_val;
    _1539_t6 = 2;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:19:17:\n    my_val_ptr.>c(2)\n               ^";
    (void) _1533_$vtable.c(_1540_my_val_ptr, _1539_t6);
    $line_idx--;
    _1539_t9 = 2;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-addr.orng:20:17:\n    my_val_ptr.>b(2) + 4\n               ^";
    _1539_t7 = _1533_$vtable.b(_1540_my_val_ptr, _1539_t9);
    $line_idx--;
    _1539_t10 = 4;
    _1539_$retval = $add_int64_t(_1539_t7, _1539_t10, "tests/integration/traits/addr-receiver-addr.orng:20:23:\n    my_val_ptr.>b(2) + 4\n                     ^");
    return _1539_$retval;
}

void _1537_c(void* _1537_self, int64_t _1537_x){
    (*(struct struct0*)_1537_self)._0 = $mult_int64_t((*(struct struct0*)_1537_self)._0, _1537_x, "tests/integration/traits/addr-receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _1535_b(void* _1535_self, int64_t _1535_x){
    int64_t _1535_t0;
    int64_t _1535_$retval;
    _1535_t0 = $mult_int64_t((*(struct struct0*)_1535_self)._1, _1535_x, "tests/integration/traits/addr-receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _1535_$retval = $add_int64_t((*(struct struct0*)_1535_self)._0, _1535_t0, "tests/integration/traits/addr-receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _1535_$retval;
}


int main(void) {
  printf("%ld",_1539_main());
  return 0;
}
