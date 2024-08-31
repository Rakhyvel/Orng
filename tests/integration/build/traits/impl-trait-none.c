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

struct vtable_$trait129 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1601_main(void);
int64_t _1595_a(void* _1595_$self_ptr);
int64_t _1599_b(void* _1599_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1594_$vtable = {
    .a = _1595_a,
};

struct vtable_$trait129 _1597_$vtable = {
    .b = _1599_b,
};


/* Function definitions */
int64_t _1601_main(void){
    int64_t _1602_x;
    int64_t _1602_y;
    int64_t* _1601_t5;
    int64_t _1601_t4;
    int64_t* _1601_t8;
    int64_t _1601_t7;
    int64_t _1601_$retval;
    _1602_x = 300;
    _1602_y = 2;
    _1601_t5 = &_1602_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1601_t4 = _1594_$vtable.a(_1601_t5);
    $line_idx--;
    _1601_t8 = &_1602_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1601_t7 = _1597_$vtable.b(_1601_t8);
    $line_idx--;
    _1601_$retval = $add_int64_t(_1601_t4, _1601_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1601_$retval;
}

int64_t _1595_a(void* _1595_$self_ptr){
    int64_t _1595_$retval;
    _1595_$retval = *(int64_t*)_1595_$self_ptr;
    return _1595_$retval;
}

int64_t _1599_b(void* _1599_$self_ptr){
    int64_t _1600_self;
    int64_t _1599_t1;
    int64_t _1599_$retval;
    _1600_self = *(int64_t*)_1599_$self_ptr;
    _1599_t1 = 2;
    _1599_$retval = $mult_int64_t(_1600_self, _1599_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1599_$retval;
}


int main(void) {
  printf("%ld",_1601_main());
  return 0;
}
