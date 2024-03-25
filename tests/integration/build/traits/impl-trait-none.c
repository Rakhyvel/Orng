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

struct vtable_$trait128 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1596_main(void);
int64_t _1590_a(void* _1590_$self_ptr);
int64_t _1594_b(void* _1594_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1589_$vtable = {
    .a = _1590_a,
};

struct vtable_$trait128 _1592_$vtable = {
    .b = _1594_b,
};


/* Function definitions */
int64_t _1596_main(void){
    int64_t _1597_x;
    int64_t _1597_y;
    int64_t* _1596_t5;
    int64_t _1596_t4;
    int64_t* _1596_t8;
    int64_t _1596_t7;
    int64_t _1596_$retval;
    _1597_x = 300;
    _1597_y = 2;
    _1596_t5 = &_1597_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1596_t4 = _1589_$vtable.a(_1596_t5);
    $line_idx--;
    _1596_t8 = &_1597_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1596_t7 = _1592_$vtable.b(_1596_t8);
    $line_idx--;
    _1596_$retval = $add_int64_t(_1596_t4, _1596_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1596_$retval;
}

int64_t _1590_a(void* _1590_$self_ptr){
    int64_t _1590_$retval;
    _1590_$retval = *(int64_t*)_1590_$self_ptr;
    return _1590_$retval;
}

int64_t _1594_b(void* _1594_$self_ptr){
    int64_t _1595_self;
    int64_t _1594_t1;
    int64_t _1594_$retval;
    _1595_self = *(int64_t*)_1594_$self_ptr;
    _1594_t1 = 2;
    _1594_$retval = $mult_int64_t(_1595_self, _1594_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1594_$retval;
}


int main(void) {
  printf("%ld",_1596_main());
  return 0;
}
