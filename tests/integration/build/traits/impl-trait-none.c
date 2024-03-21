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
int64_t _1587_main(void);
int64_t _1581_a(void* _1581_$self_ptr);
int64_t _1585_b(void* _1585_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1580_$vtable = {
    .a = _1581_a,
};

struct vtable_$trait126 _1583_$vtable = {
    .b = _1585_b,
};


/* Function definitions */
int64_t _1587_main(void){
    int64_t _1588_x;
    int64_t _1588_y;
    int64_t* _1587_t5;
    int64_t _1587_t4;
    int64_t* _1587_t8;
    int64_t _1587_t7;
    int64_t _1587_$retval;
    _1588_x = 300;
    _1588_y = 2;
    _1587_t5 = &_1588_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1587_t4 = _1580_$vtable.a(_1587_t5);
    $line_idx--;
    _1587_t8 = &_1588_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1587_t7 = _1583_$vtable.b(_1587_t8);
    $line_idx--;
    _1587_$retval = $add_int64_t(_1587_t4, _1587_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1587_$retval;
}

int64_t _1581_a(void* _1581_$self_ptr){
    int64_t _1581_$retval;
    _1581_$retval = *(int64_t*)_1581_$self_ptr;
    return _1581_$retval;
}

int64_t _1585_b(void* _1585_$self_ptr){
    int64_t _1586_self;
    int64_t _1585_t1;
    int64_t _1585_$retval;
    _1586_self = *(int64_t*)_1585_$self_ptr;
    _1585_t1 = 2;
    _1585_$retval = $mult_int64_t(_1586_self, _1585_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1585_$retval;
}


int main(void) {
  printf("%ld",_1587_main());
  return 0;
}
