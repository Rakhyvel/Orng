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
int64_t _47_main(void);
int64_t _43_b(void* _43_self, int64_t _43_x);
void _45_c(void* _45_self, int64_t _45_x);

/* Trait vtable implementations */
struct vtable_My_Trait _42_$vtable = {
    .b = _43_b,
    .c = _45_c,
};


/* Function definitions */
int64_t _47_main(void){
    int64_t _47_t1;
    int64_t _47_t2;
    struct struct3 _48_my_val;
    struct dyn4 _47_t3;
    struct dyn4 _48_my_dyn;
    int64_t _47_t5;
    int64_t _47_t7;
    int64_t _47_t6;
    int64_t _47_$retval;
    _47_t1 = 100;
    _47_t2 = 45;
    _48_my_val = (struct struct3) {_47_t1, _47_t2};
    _47_t3 = (struct dyn4) {&_48_my_val, &_42_$vtable};
    _48_my_dyn = _47_t3;
    _47_t5 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:19:13:\n    my_dyn.>c(2)\n           ^";
    (void) _48_my_dyn.vtable->c(_48_my_dyn.data_ptr, _47_t5);
    $line_idx--;
    _47_t7 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:20:13:\n    my_dyn.>b(2)\n           ^";
    _47_t6 = _48_my_dyn.vtable->b(_48_my_dyn.data_ptr, _47_t7);
    $line_idx--;
    _47_$retval = _47_t6;
    return _47_$retval;
}

int64_t _43_b(void* _43_self, int64_t _43_x){
    int64_t _43_t0;
    int64_t _43_$retval;
    _43_t0 = $mult_int64_t((*(struct struct3*)_43_self)._1, _43_x, "tests/integration/traits/receiver-addr-object.orng:11:59:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                         ^");
    _43_$retval = $add_int64_t((*(struct struct3*)_43_self)._0, _43_t0, "tests/integration/traits/receiver-addr-object.orng:11:50:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    return _43_$retval;
}

void _45_c(void* _45_self, int64_t _45_x){
    (*(struct struct3*)_45_self)._0 = $mult_int64_t((*(struct struct3*)_45_self)._0, _45_x, "tests/integration/traits/receiver-addr-object.orng:13:54:\n    virtual fn c(&mut self, x: Int) -> () { self.x *= x }\n                                                    ^");
    return;
}


int main(void) {
  printf("%ld",_47_main());
  return 0;
}
