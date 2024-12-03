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

struct vtable_$trait142 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1682_main(void);
int64_t _1676_a(void* _1676_$self_ptr);
int64_t _1680_b(void* _1680_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1675_$vtable = {
    .a = _1676_a,
};

struct vtable_$trait142 _1678_$vtable = {
    .b = _1680_b,
};


/* Function definitions */
int64_t _1682_main(void){
    int64_t _1683_x;
    int64_t _1683_y;
    int64_t* _1682_t5;
    int64_t _1682_t4;
    int64_t* _1682_t8;
    int64_t _1682_t7;
    int64_t _1682_$retval;
    _1683_x = 300;
    _1683_y = 2;
    _1682_t5 = &_1683_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1682_t4 = _1675_$vtable.a(_1682_t5);
    $line_idx--;
    _1682_t8 = &_1683_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1682_t7 = _1678_$vtable.b(_1682_t8);
    $line_idx--;
    _1682_$retval = $add_int64_t(_1682_t4, _1682_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1682_$retval;
}

int64_t _1676_a(void* _1676_$self_ptr){
    int64_t _1676_$retval;
    _1676_$retval = *(int64_t*)_1676_$self_ptr;
    return _1676_$retval;
}

int64_t _1680_b(void* _1680_$self_ptr){
    int64_t _1681_self;
    int64_t _1680_t1;
    int64_t _1680_$retval;
    _1681_self = *(int64_t*)_1680_$self_ptr;
    _1680_t1 = 2;
    _1680_$retval = $mult_int64_t(_1681_self, _1680_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1680_$retval;
}


int main(void) {
  printf("%ld",_1682_main());
  return 0;
}
