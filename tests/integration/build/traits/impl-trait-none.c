/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void*);

typedef int64_t(*function1)(int64_t*);

/* Trait vtable type definitions */
struct vtable_Trait_A {
    int64_t(*a)(void*);
};

struct vtable_$trait5 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _62_main(void);
int64_t _56_a(void* _56_$self_ptr);
int64_t _60_b(void* _60_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _55_$vtable = {
    .a = _56_a,
};

struct vtable_$trait5 _58_$vtable = {
    .b = _60_b,
};


/* Function definitions */
int64_t _62_main(void){
    int64_t _63_x;
    int64_t _63_y;
    int64_t* _62_t5;
    int64_t _62_t4;
    int64_t* _62_t8;
    int64_t _62_t7;
    int64_t _62_$retval;
    _63_x = 300;
    _63_y = 2;
    _62_t5 = &_63_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _62_t4 = _55_$vtable.a(_62_t5);
    $line_idx--;
    _62_t8 = &_63_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _62_t7 = _58_$vtable.b(_62_t8);
    $line_idx--;
    _62_$retval = $add_int64_t(_62_t4, _62_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _62_$retval;
}

int64_t _56_a(void* _56_$self_ptr){
    int64_t _56_$retval;
    _56_$retval = *(int64_t*)_56_$self_ptr;
    return _56_$retval;
}

int64_t _60_b(void* _60_$self_ptr){
    int64_t _61_self;
    int64_t _60_t1;
    int64_t _60_$retval;
    _61_self = *(int64_t*)_60_$self_ptr;
    _60_t1 = 2;
    _60_$retval = $mult_int64_t(_61_self, _60_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _60_$retval;
}


int main(void) {
  printf("%ld",_62_main());
  return 0;
}
