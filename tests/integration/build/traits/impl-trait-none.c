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
int64_t _1568_main(void);
int64_t _1562_a(void* _1562_$self_ptr);
int64_t _1566_b(void* _1566_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1561_$vtable = {
    .a = _1562_a,
};

struct vtable_$trait126 _1564_$vtable = {
    .b = _1566_b,
};


/* Function definitions */
int64_t _1568_main(void){
    int64_t _1569_x;
    int64_t _1569_y;
    int64_t* _1568_t5;
    int64_t _1568_t4;
    int64_t* _1568_t8;
    int64_t _1568_t7;
    int64_t _1568_$retval;
    _1569_x = 300;
    _1569_y = 2;
    _1568_t5 = &_1569_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1568_t4 = _1561_$vtable.a(_1568_t5);
    $line_idx--;
    _1568_t8 = &_1569_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1568_t7 = _1564_$vtable.b(_1568_t8);
    $line_idx--;
    _1568_$retval = $add_int64_t(_1568_t4, _1568_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1568_$retval;
}

int64_t _1562_a(void* _1562_$self_ptr){
    int64_t _1562_$retval;
    _1562_$retval = *(int64_t*)_1562_$self_ptr;
    return _1562_$retval;
}

int64_t _1566_b(void* _1566_$self_ptr){
    int64_t _1567_self;
    int64_t _1566_t1;
    int64_t _1566_$retval;
    _1567_self = *(int64_t*)_1566_$self_ptr;
    _1566_t1 = 2;
    _1566_$retval = $mult_int64_t(_1567_self, _1566_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1566_$retval;
}


int main(void) {
  printf("%ld",_1568_main());
  return 0;
}
