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

struct vtable_$trait141 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1672_main(void);
int64_t _1666_a(void* _1666_$self_ptr);
int64_t _1670_b(void* _1670_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1665_$vtable = {
    .a = _1666_a,
};

struct vtable_$trait141 _1668_$vtable = {
    .b = _1670_b,
};


/* Function definitions */
int64_t _1672_main(void){
    int64_t _1673_x;
    int64_t _1673_y;
    int64_t* _1672_t5;
    int64_t _1672_t4;
    int64_t* _1672_t8;
    int64_t _1672_t7;
    int64_t _1672_$retval;
    _1673_x = 300;
    _1673_y = 2;
    _1672_t5 = &_1673_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1672_t4 = _1665_$vtable.a(_1672_t5);
    $line_idx--;
    _1672_t8 = &_1673_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1672_t7 = _1668_$vtable.b(_1672_t8);
    $line_idx--;
    _1672_$retval = $add_int64_t(_1672_t4, _1672_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1672_$retval;
}

int64_t _1666_a(void* _1666_$self_ptr){
    int64_t _1666_$retval;
    _1666_$retval = *(int64_t*)_1666_$self_ptr;
    return _1666_$retval;
}

int64_t _1670_b(void* _1670_$self_ptr){
    int64_t _1671_self;
    int64_t _1670_t1;
    int64_t _1670_$retval;
    _1671_self = *(int64_t*)_1670_$self_ptr;
    _1670_t1 = 2;
    _1670_$retval = $mult_int64_t(_1671_self, _1670_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1670_$retval;
}


int main(void) {
  printf("%ld",_1672_main());
  return 0;
}
