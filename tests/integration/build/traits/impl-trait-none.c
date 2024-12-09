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

struct vtable_$trait145 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1707_main(void);
int64_t _1701_a(void* _1701_$self_ptr);
int64_t _1705_b(void* _1705_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1700_$vtable = {
    .a = _1701_a,
};

struct vtable_$trait145 _1703_$vtable = {
    .b = _1705_b,
};


/* Function definitions */
int64_t _1707_main(void){
    int64_t _1708_x;
    int64_t _1708_y;
    int64_t* _1707_t5;
    int64_t _1707_t4;
    int64_t* _1707_t8;
    int64_t _1707_t7;
    int64_t _1707_$retval;
    _1708_x = 300;
    _1708_y = 2;
    _1707_t5 = &_1708_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1707_t4 = _1700_$vtable.a(_1707_t5);
    $line_idx--;
    _1707_t8 = &_1708_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1707_t7 = _1703_$vtable.b(_1707_t8);
    $line_idx--;
    _1707_$retval = $add_int64_t(_1707_t4, _1707_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1707_$retval;
}

int64_t _1701_a(void* _1701_$self_ptr){
    int64_t _1701_$retval;
    _1701_$retval = *(int64_t*)_1701_$self_ptr;
    return _1701_$retval;
}

int64_t _1705_b(void* _1705_$self_ptr){
    int64_t _1706_self;
    int64_t _1705_t1;
    int64_t _1705_$retval;
    _1706_self = *(int64_t*)_1705_$self_ptr;
    _1705_t1 = 2;
    _1705_$retval = $mult_int64_t(_1706_self, _1705_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1705_$retval;
}


int main(void) {
  printf("%ld",_1707_main());
  return 0;
}
