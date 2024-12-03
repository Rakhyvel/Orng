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
int64_t _127_main(void);
int64_t _123_b(void* _123_self, int64_t _123_x);
void _125_c(void* _125_self, int64_t _125_x);

/* Trait vtable implementations */
struct vtable_My_Trait _122_$vtable = {
    .b = _123_b,
    .c = _125_c,
};


/* Function definitions */
int64_t _127_main(void){
    int64_t _127_t1;
    int64_t _127_t2;
    struct struct3 _128_my_val;
    struct dyn4 _127_t4;
    struct dyn4 _128_my_dyn;
    int64_t _127_t7;
    int64_t _127_t9;
    int64_t _127_t8;
    int64_t _127_$retval;
    _127_t1 = 100;
    _127_t2 = 45;
    _128_my_val = (struct struct3) {_127_t1, _127_t2};
    _127_t4 = (struct dyn4) {&_128_my_val, &_122_$vtable};
    _128_my_dyn = _127_t4;
    _127_t7 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:19:13:\n    my_dyn.>c(2)\n           ^";
    (void) _128_my_dyn.vtable->c(_128_my_dyn.data_ptr, _127_t7);
    $line_idx--;
    _127_t9 = 2;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr-object.orng:20:13:\n    my_dyn.>b(2)\n           ^";
    _127_t8 = _128_my_dyn.vtable->b(_128_my_dyn.data_ptr, _127_t9);
    $line_idx--;
    _127_$retval = _127_t8;
    return _127_$retval;
}

int64_t _123_b(void* _123_self, int64_t _123_x){
    int64_t _123_t0;
    int64_t _123_$retval;
    _123_t0 = $mult_int64_t((*(struct struct3*)_123_self)._1, _123_x, "tests/integration/traits/receiver-addr-object.orng:11:59:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                         ^");
    _123_$retval = $add_int64_t((*(struct struct3*)_123_self)._0, _123_t0, "tests/integration/traits/receiver-addr-object.orng:11:50:\n    virtual fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                ^");
    return _123_$retval;
}

void _125_c(void* _125_self, int64_t _125_x){
    (*(struct struct3*)_125_self)._0 = $mult_int64_t((*(struct struct3*)_125_self)._0, _125_x, "tests/integration/traits/receiver-addr-object.orng:13:54:\n    virtual fn c(&mut self, x: Int) -> () { self.x *= x }\n                                                    ^");
    return;
}


int main(void) {
  printf("%ld",_127_main());
  return 0;
}
