/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;
struct dyn4;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

typedef void(*function2)(void*, int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

struct dyn4 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*b)(void*, int64_t);
    void(*c)(void*, int64_t);
};

/* Function forward definitions */
int64_t _1625_main(void);
int64_t _1621_b(void* _1621_self, int64_t _1621_x);
void _1623_c(void* _1623_self, int64_t _1623_x);

/* Trait vtable implementations */
struct vtable_My_Trait _1620_$vtable = {
    .b = _1621_b,
    .c = _1623_c,
};


/* Function definitions */
int64_t _1625_main(void){
    int64_t _1625_t1;
    int64_t _1625_t2;
    struct struct3 _1626_my_val;
    struct dyn4 _1625_t4;
    struct dyn4 _1626_my_dyn;
    int64_t _1625_t7;
    int64_t _1625_t9;
    int64_t _1625_t8;
    int64_t _1625_$retval;
    _1625_t1 = 100;
    _1625_t2 = 45;
    _1626_my_val = (struct struct3) {_1625_t1, _1625_t2};
    _1625_t4 = (struct dyn4) {&_1626_my_val, &_1620_$vtable};
    _1626_my_dyn = _1625_t4;
    _1625_t7 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:19:13:\n    my_dyn.>c(2)\n           ^";
    (void) _1626_my_dyn.vtable->c(_1626_my_dyn.data_ptr, _1625_t7);
    $line_idx--;
    _1625_t9 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:20:13:\n    my_dyn.>b(2)\n           ^";
    _1625_t8 = _1626_my_dyn.vtable->b(_1626_my_dyn.data_ptr, _1625_t9);
    $line_idx--;
    _1625_$retval = _1625_t8;
    return _1625_$retval;
}

int64_t _1621_b(void* _1621_self, int64_t _1621_x){
    int64_t _1621_t0;
    int64_t _1621_$retval;
    _1621_t0 = $mult_int64_t((*(struct struct3*)_1621_self)._1, _1621_x, "tests/integration/traits/receiver-addr-object.orng:11:59:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                         ^");
    _1621_$retval = $add_int64_t((*(struct struct3*)_1621_self)._0, _1621_t0, "tests/integration/traits/receiver-addr-object.orng:11:50:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    return _1621_$retval;
}

void _1623_c(void* _1623_self, int64_t _1623_x){
    (*(struct struct3*)_1623_self)._0 = $mult_int64_t((*(struct struct3*)_1623_self)._0, _1623_x, "tests/integration/traits/receiver-addr-object.orng:13:54:\n    virtual fn c(&mut self, x: Int) -> () { self.x *= x }\n                                                    ^");
    return;
}


int main(void) {
  printf("%ld",_1625_main());
  return 0;
}
