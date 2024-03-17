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
int64_t _1573_main(void);
int64_t _1567_a(void* _1567_$self_ptr);
int64_t _1571_b(void* _1571_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1566_$vtable = {
    .a = _1567_a,
};

struct vtable_$trait126 _1569_$vtable = {
    .b = _1571_b,
};


/* Function definitions */
int64_t _1573_main(void){
    int64_t _1574_x;
    int64_t _1574_y;
    int64_t* _1573_t5;
    int64_t _1573_t4;
    int64_t* _1573_t8;
    int64_t _1573_t7;
    int64_t _1573_$retval;
    _1574_x = 300;
    _1574_y = 2;
    _1573_t5 = &_1574_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1573_t4 = _1566_$vtable.a(_1573_t5);
    $line_idx--;
    _1573_t8 = &_1574_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1573_t7 = _1569_$vtable.b(_1573_t8);
    $line_idx--;
    _1573_$retval = $add_int64_t(_1573_t4, _1573_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1573_$retval;
}

int64_t _1567_a(void* _1567_$self_ptr){
    int64_t _1567_$retval;
    _1567_$retval = *(int64_t*)_1567_$self_ptr;
    return _1567_$retval;
}

int64_t _1571_b(void* _1571_$self_ptr){
    int64_t _1572_self;
    int64_t _1571_t1;
    int64_t _1571_$retval;
    _1572_self = *(int64_t*)_1571_$self_ptr;
    _1571_t1 = 2;
    _1571_$retval = $mult_int64_t(_1572_self, _1571_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1571_$retval;
}


int main(void) {
  printf("%ld",_1573_main());
  return 0;
}
