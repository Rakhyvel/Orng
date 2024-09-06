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
int64_t _1667_main(void);
int64_t _1661_a(void* _1661_$self_ptr);
int64_t _1665_b(void* _1665_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1660_$vtable = {
    .a = _1661_a,
};

struct vtable_$trait141 _1663_$vtable = {
    .b = _1665_b,
};


/* Function definitions */
int64_t _1667_main(void){
    int64_t _1668_x;
    int64_t _1668_y;
    int64_t* _1667_t5;
    int64_t _1667_t4;
    int64_t* _1667_t8;
    int64_t _1667_t7;
    int64_t _1667_$retval;
    _1668_x = 300;
    _1668_y = 2;
    _1667_t5 = &_1668_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1667_t4 = _1660_$vtable.a(_1667_t5);
    $line_idx--;
    _1667_t8 = &_1668_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1667_t7 = _1663_$vtable.b(_1667_t8);
    $line_idx--;
    _1667_$retval = $add_int64_t(_1667_t4, _1667_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1667_$retval;
}

int64_t _1661_a(void* _1661_$self_ptr){
    int64_t _1661_$retval;
    _1661_$retval = *(int64_t*)_1661_$self_ptr;
    return _1661_$retval;
}

int64_t _1665_b(void* _1665_$self_ptr){
    int64_t _1666_self;
    int64_t _1665_t1;
    int64_t _1665_$retval;
    _1666_self = *(int64_t*)_1665_$self_ptr;
    _1665_t1 = 2;
    _1665_$retval = $mult_int64_t(_1666_self, _1665_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1665_$retval;
}


int main(void) {
  printf("%ld",_1667_main());
  return 0;
}
