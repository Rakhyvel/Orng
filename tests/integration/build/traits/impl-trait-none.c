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
int64_t _1694_main(void);
int64_t _1688_a(void* _1688_$self_ptr);
int64_t _1692_b(void* _1692_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1687_$vtable = {
    .a = _1688_a,
};

struct vtable_$trait143 _1690_$vtable = {
    .b = _1692_b,
};


/* Function definitions */
int64_t _1694_main(void){
    int64_t _1695_x;
    int64_t _1695_y;
    int64_t* _1694_t5;
    int64_t _1694_t4;
    int64_t* _1694_t8;
    int64_t _1694_t7;
    int64_t _1694_$retval;
    _1695_x = 300;
    _1695_y = 2;
    _1694_t5 = &_1695_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1694_t4 = _1687_$vtable.a(_1694_t5);
    $line_idx--;
    _1694_t8 = &_1695_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1694_t7 = _1690_$vtable.b(_1694_t8);
    $line_idx--;
    _1694_$retval = $add_int64_t(_1694_t4, _1694_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1694_$retval;
}

int64_t _1688_a(void* _1688_$self_ptr){
    int64_t _1688_$retval;
    _1688_$retval = *(int64_t*)_1688_$self_ptr;
    return _1688_$retval;
}

int64_t _1692_b(void* _1692_$self_ptr){
    int64_t _1693_self;
    int64_t _1692_t1;
    int64_t _1692_$retval;
    _1693_self = *(int64_t*)_1692_$self_ptr;
    _1692_t1 = 2;
    _1692_$retval = $mult_int64_t(_1693_self, _1692_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1692_$retval;
}


int main(void) {
  printf("%ld",_1694_main());
  return 0;
}
