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

struct vtable_$trait135 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1640_main(void);
int64_t _1634_a(void* _1634_$self_ptr);
int64_t _1638_b(void* _1638_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1633_$vtable = {
    .a = _1634_a,
};

struct vtable_$trait135 _1636_$vtable = {
    .b = _1638_b,
};


/* Function definitions */
int64_t _1640_main(void){
    int64_t _1641_x;
    int64_t _1641_y;
    int64_t* _1640_t5;
    int64_t _1640_t4;
    int64_t* _1640_t8;
    int64_t _1640_t7;
    int64_t _1640_$retval;
    _1641_x = 300;
    _1641_y = 2;
    _1640_t5 = &_1641_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1640_t4 = _1633_$vtable.a(_1640_t5);
    $line_idx--;
    _1640_t8 = &_1641_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1640_t7 = _1636_$vtable.b(_1640_t8);
    $line_idx--;
    _1640_$retval = $add_int64_t(_1640_t4, _1640_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1640_$retval;
}

int64_t _1634_a(void* _1634_$self_ptr){
    int64_t _1634_$retval;
    _1634_$retval = *(int64_t*)_1634_$self_ptr;
    return _1634_$retval;
}

int64_t _1638_b(void* _1638_$self_ptr){
    int64_t _1639_self;
    int64_t _1638_t1;
    int64_t _1638_$retval;
    _1639_self = *(int64_t*)_1638_$self_ptr;
    _1638_t1 = 2;
    _1638_$retval = $mult_int64_t(_1639_self, _1638_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1638_$retval;
}


int main(void) {
  printf("%ld",_1640_main());
  return 0;
}
