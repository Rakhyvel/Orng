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

struct vtable_$trait139 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1651_main(void);
int64_t _1645_a(void* _1645_$self_ptr);
int64_t _1649_b(void* _1649_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1644_$vtable = {
    .a = _1645_a,
};

struct vtable_$trait139 _1647_$vtable = {
    .b = _1649_b,
};


/* Function definitions */
int64_t _1651_main(void){
    int64_t _1652_x;
    int64_t _1652_y;
    int64_t* _1651_t5;
    int64_t _1651_t4;
    int64_t* _1651_t8;
    int64_t _1651_t7;
    int64_t _1651_$retval;
    _1652_x = 300;
    _1652_y = 2;
    _1651_t5 = &_1652_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1651_t4 = _1644_$vtable.a(_1651_t5);
    $line_idx--;
    _1651_t8 = &_1652_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1651_t7 = _1647_$vtable.b(_1651_t8);
    $line_idx--;
    _1651_$retval = $add_int64_t(_1651_t4, _1651_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1651_$retval;
}

int64_t _1645_a(void* _1645_$self_ptr){
    int64_t _1645_$retval;
    _1645_$retval = *(int64_t*)_1645_$self_ptr;
    return _1645_$retval;
}

int64_t _1649_b(void* _1649_$self_ptr){
    int64_t _1650_self;
    int64_t _1649_t1;
    int64_t _1649_$retval;
    _1650_self = *(int64_t*)_1649_$self_ptr;
    _1649_t1 = 2;
    _1649_$retval = $mult_int64_t(_1650_self, _1649_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1649_$retval;
}


int main(void) {
  printf("%ld",_1651_main());
  return 0;
}
