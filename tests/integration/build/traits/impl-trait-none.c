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
int64_t _1659_main(void);
int64_t _1653_a(void* _1653_$self_ptr);
int64_t _1657_b(void* _1657_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1652_$vtable = {
    .a = _1653_a,
};

struct vtable_$trait141 _1655_$vtable = {
    .b = _1657_b,
};


/* Function definitions */
int64_t _1659_main(void){
    int64_t _1660_x;
    int64_t _1660_y;
    int64_t* _1659_t5;
    int64_t _1659_t4;
    int64_t* _1659_t8;
    int64_t _1659_t7;
    int64_t _1659_$retval;
    _1660_x = 300;
    _1660_y = 2;
    _1659_t5 = &_1660_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1659_t4 = _1652_$vtable.a(_1659_t5);
    $line_idx--;
    _1659_t8 = &_1660_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1659_t7 = _1655_$vtable.b(_1659_t8);
    $line_idx--;
    _1659_$retval = $add_int64_t(_1659_t4, _1659_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1659_$retval;
}

int64_t _1653_a(void* _1653_$self_ptr){
    int64_t _1653_$retval;
    _1653_$retval = *(int64_t*)_1653_$self_ptr;
    return _1653_$retval;
}

int64_t _1657_b(void* _1657_$self_ptr){
    int64_t _1658_self;
    int64_t _1657_t1;
    int64_t _1657_$retval;
    _1658_self = *(int64_t*)_1657_$self_ptr;
    _1657_t1 = 2;
    _1657_$retval = $mult_int64_t(_1658_self, _1657_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1657_$retval;
}


int main(void) {
  printf("%ld",_1659_main());
  return 0;
}
