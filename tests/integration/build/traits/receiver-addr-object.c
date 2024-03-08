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
int64_t _56_main(void);
int64_t _52_b(void* _52_self, int64_t _52_x);
void _54_c(void* _54_self, int64_t _54_x);

/* Trait vtable implementations */
struct vtable_My_Trait _51_$vtable = {
    .b = _52_b,
    .c = _54_c,
};


/* Function definitions */
int64_t _56_main(void){
    int64_t _56_t1;
    int64_t _56_t2;
    struct struct3 _57_my_val;
    struct dyn4 _56_t3;
    struct dyn4 _57_my_dyn;
    int64_t _56_t5;
    int64_t _56_t7;
    int64_t _56_t6;
    int64_t _56_$retval;
    _56_t1 = 100;
    _56_t2 = 45;
    _57_my_val = (struct struct3) {_56_t1, _56_t2};
    _56_t3 = (struct dyn4) {&_57_my_val, &_51_$vtable};
    _57_my_dyn = _56_t3;
    _56_t5 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:19:13:\n    my_dyn.>c(2)\n           ^";
    (void) _57_my_dyn.vtable->c(_57_my_dyn.data_ptr, _56_t5);
    $line_idx--;
    _56_t7 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:20:13:\n    my_dyn.>b(2)\n           ^";
    _56_t6 = _57_my_dyn.vtable->b(_57_my_dyn.data_ptr, _56_t7);
    $line_idx--;
    _56_$retval = _56_t6;
    return _56_$retval;
}

int64_t _52_b(void* _52_self, int64_t _52_x){
    int64_t _52_t0;
    int64_t _52_$retval;
    _52_t0 = $mult_int64_t((*(struct struct3*)_52_self)._1, _52_x, "tests/integration/traits/receiver-addr-object.orng:11:59:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                         ^");
    _52_$retval = $add_int64_t((*(struct struct3*)_52_self)._0, _52_t0, "tests/integration/traits/receiver-addr-object.orng:11:50:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    return _52_$retval;
}

void _54_c(void* _54_self, int64_t _54_x){
    (*(struct struct3*)_54_self)._0 = $mult_int64_t((*(struct struct3*)_54_self)._0, _54_x, "tests/integration/traits/receiver-addr-object.orng:13:54:\n    virtual fn c(&mut self, x: Int) -> () { self.x *= x }\n                                                    ^");
    return;
}


int main(void) {
  printf("%ld",_56_main());
  return 0;
}
