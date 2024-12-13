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
int64_t _1724_main(void);
int64_t _1718_a(void* _1718_$self_ptr);
int64_t _1722_b(void* _1722_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1717_$vtable = {
    .a = _1718_a,
};

struct vtable_$trait148 _1720_$vtable = {
    .b = _1722_b,
};


/* Function definitions */
int64_t _1724_main(void){
    int64_t _1725_x;
    int64_t _1725_y;
    int64_t* _1724_t5;
    int64_t _1724_t4;
    int64_t* _1724_t8;
    int64_t _1724_t7;
    int64_t _1724_$retval;
    _1725_x = 300;
    _1725_y = 2;
    _1724_t5 = &_1725_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1724_t4 = _1717_$vtable.a(_1724_t5);
    $line_idx--;
    _1724_t8 = &_1725_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1724_t7 = _1720_$vtable.b(_1724_t8);
    $line_idx--;
    _1724_$retval = $add_int64_t(_1724_t4, _1724_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1724_$retval;
}

int64_t _1718_a(void* _1718_$self_ptr){
    int64_t _1718_$retval;
    _1718_$retval = *(int64_t*)_1718_$self_ptr;
    return _1718_$retval;
}

int64_t _1722_b(void* _1722_$self_ptr){
    int64_t _1723_self;
    int64_t _1722_t1;
    int64_t _1722_$retval;
    _1723_self = *(int64_t*)_1722_$self_ptr;
    _1722_t1 = 2;
    _1722_$retval = $mult_int64_t(_1723_self, _1722_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1722_$retval;
}


int main(void) {
  printf("%ld",_1724_main());
  return 0;
}
