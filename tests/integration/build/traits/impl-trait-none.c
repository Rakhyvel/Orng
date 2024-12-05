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

struct vtable_$trait143 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1688_main(void);
int64_t _1682_a(void* _1682_$self_ptr);
int64_t _1686_b(void* _1686_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1681_$vtable = {
    .a = _1682_a,
};

struct vtable_$trait143 _1684_$vtable = {
    .b = _1686_b,
};


/* Function definitions */
int64_t _1688_main(void){
    int64_t _1689_x;
    int64_t _1689_y;
    int64_t* _1688_t5;
    int64_t _1688_t4;
    int64_t* _1688_t8;
    int64_t _1688_t7;
    int64_t _1688_$retval;
    _1689_x = 300;
    _1689_y = 2;
    _1688_t5 = &_1689_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1688_t4 = _1681_$vtable.a(_1688_t5);
    $line_idx--;
    _1688_t8 = &_1689_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1688_t7 = _1684_$vtable.b(_1688_t8);
    $line_idx--;
    _1688_$retval = $add_int64_t(_1688_t4, _1688_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1688_$retval;
}

int64_t _1682_a(void* _1682_$self_ptr){
    int64_t _1682_$retval;
    _1682_$retval = *(int64_t*)_1682_$self_ptr;
    return _1682_$retval;
}

int64_t _1686_b(void* _1686_$self_ptr){
    int64_t _1687_self;
    int64_t _1686_t1;
    int64_t _1686_$retval;
    _1687_self = *(int64_t*)_1686_$self_ptr;
    _1686_t1 = 2;
    _1686_$retval = $mult_int64_t(_1687_self, _1686_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1686_$retval;
}


int main(void) {
  printf("%ld",_1688_main());
  return 0;
}
