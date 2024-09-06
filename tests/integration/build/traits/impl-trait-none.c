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
int64_t _1674_main(void);
int64_t _1668_a(void* _1668_$self_ptr);
int64_t _1672_b(void* _1672_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1667_$vtable = {
    .a = _1668_a,
};

struct vtable_$trait141 _1670_$vtable = {
    .b = _1672_b,
};


/* Function definitions */
int64_t _1674_main(void){
    int64_t _1675_x;
    int64_t _1675_y;
    int64_t* _1674_t5;
    int64_t _1674_t4;
    int64_t* _1674_t8;
    int64_t _1674_t7;
    int64_t _1674_$retval;
    _1675_x = 300;
    _1675_y = 2;
    _1674_t5 = &_1675_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1674_t4 = _1667_$vtable.a(_1674_t5);
    $line_idx--;
    _1674_t8 = &_1675_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1674_t7 = _1670_$vtable.b(_1674_t8);
    $line_idx--;
    _1674_$retval = $add_int64_t(_1674_t4, _1674_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1674_$retval;
}

int64_t _1668_a(void* _1668_$self_ptr){
    int64_t _1668_$retval;
    _1668_$retval = *(int64_t*)_1668_$self_ptr;
    return _1668_$retval;
}

int64_t _1672_b(void* _1672_$self_ptr){
    int64_t _1673_self;
    int64_t _1672_t1;
    int64_t _1672_$retval;
    _1673_self = *(int64_t*)_1672_$self_ptr;
    _1672_t1 = 2;
    _1672_$retval = $mult_int64_t(_1673_self, _1672_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1672_$retval;
}


int main(void) {
  printf("%ld",_1674_main());
  return 0;
}
