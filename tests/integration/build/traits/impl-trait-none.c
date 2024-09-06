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
int64_t _1677_main(void);
int64_t _1671_a(void* _1671_$self_ptr);
int64_t _1675_b(void* _1675_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1670_$vtable = {
    .a = _1671_a,
};

struct vtable_$trait141 _1673_$vtable = {
    .b = _1675_b,
};


/* Function definitions */
int64_t _1677_main(void){
    int64_t _1678_x;
    int64_t _1678_y;
    int64_t* _1677_t5;
    int64_t _1677_t4;
    int64_t* _1677_t8;
    int64_t _1677_t7;
    int64_t _1677_$retval;
    _1678_x = 300;
    _1678_y = 2;
    _1677_t5 = &_1678_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1677_t4 = _1670_$vtable.a(_1677_t5);
    $line_idx--;
    _1677_t8 = &_1678_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1677_t7 = _1673_$vtable.b(_1677_t8);
    $line_idx--;
    _1677_$retval = $add_int64_t(_1677_t4, _1677_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1677_$retval;
}

int64_t _1671_a(void* _1671_$self_ptr){
    int64_t _1671_$retval;
    _1671_$retval = *(int64_t*)_1671_$self_ptr;
    return _1671_$retval;
}

int64_t _1675_b(void* _1675_$self_ptr){
    int64_t _1676_self;
    int64_t _1675_t1;
    int64_t _1675_$retval;
    _1676_self = *(int64_t*)_1675_$self_ptr;
    _1675_t1 = 2;
    _1675_$retval = $mult_int64_t(_1676_self, _1675_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1675_$retval;
}


int main(void) {
  printf("%ld",_1677_main());
  return 0;
}
