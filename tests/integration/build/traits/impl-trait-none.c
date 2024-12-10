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

struct vtable_$trait148 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1722_main(void);
int64_t _1716_a(void* _1716_$self_ptr);
int64_t _1720_b(void* _1720_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1715_$vtable = {
    .a = _1716_a,
};

struct vtable_$trait148 _1718_$vtable = {
    .b = _1720_b,
};


/* Function definitions */
int64_t _1722_main(void){
    int64_t _1723_x;
    int64_t _1723_y;
    int64_t* _1722_t5;
    int64_t _1722_t4;
    int64_t* _1722_t8;
    int64_t _1722_t7;
    int64_t _1722_$retval;
    _1723_x = 300;
    _1723_y = 2;
    _1722_t5 = &_1723_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1722_t4 = _1715_$vtable.a(_1722_t5);
    $line_idx--;
    _1722_t8 = &_1723_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1722_t7 = _1718_$vtable.b(_1722_t8);
    $line_idx--;
    _1722_$retval = $add_int64_t(_1722_t4, _1722_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1722_$retval;
}

int64_t _1716_a(void* _1716_$self_ptr){
    int64_t _1716_$retval;
    _1716_$retval = *(int64_t*)_1716_$self_ptr;
    return _1716_$retval;
}

int64_t _1720_b(void* _1720_$self_ptr){
    int64_t _1721_self;
    int64_t _1720_t1;
    int64_t _1720_$retval;
    _1721_self = *(int64_t*)_1720_$self_ptr;
    _1720_t1 = 2;
    _1720_$retval = $mult_int64_t(_1721_self, _1720_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1720_$retval;
}


int main(void) {
  printf("%ld",_1722_main());
  return 0;
}
