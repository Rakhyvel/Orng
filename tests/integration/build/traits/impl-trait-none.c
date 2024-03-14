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

struct vtable_$trait126 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1602_main(void);
int64_t _1596_a(void* _1596_$self_ptr);
int64_t _1600_b(void* _1600_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1595_$vtable = {
    .a = _1596_a,
};

struct vtable_$trait126 _1598_$vtable = {
    .b = _1600_b,
};


/* Function definitions */
int64_t _1602_main(void){
    int64_t _1603_x;
    int64_t _1603_y;
    int64_t* _1602_t5;
    int64_t _1602_t4;
    int64_t* _1602_t8;
    int64_t _1602_t7;
    int64_t _1602_$retval;
    _1603_x = 300;
    _1603_y = 2;
    _1602_t5 = &_1603_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1602_t4 = _1595_$vtable.a(_1602_t5);
    $line_idx--;
    _1602_t8 = &_1603_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1602_t7 = _1598_$vtable.b(_1602_t8);
    $line_idx--;
    _1602_$retval = $add_int64_t(_1602_t4, _1602_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1602_$retval;
}

int64_t _1596_a(void* _1596_$self_ptr){
    int64_t _1596_$retval;
    _1596_$retval = *(int64_t*)_1596_$self_ptr;
    return _1596_$retval;
}

int64_t _1600_b(void* _1600_$self_ptr){
    int64_t _1601_self;
    int64_t _1600_t1;
    int64_t _1600_$retval;
    _1601_self = *(int64_t*)_1600_$self_ptr;
    _1600_t1 = 2;
    _1600_$retval = $mult_int64_t(_1601_self, _1600_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1600_$retval;
}


int main(void) {
  printf("%ld",_1602_main());
  return 0;
}
