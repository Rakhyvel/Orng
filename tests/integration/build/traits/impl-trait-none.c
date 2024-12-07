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

struct vtable_$trait143 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _1702_main(void);
int64_t _1696_a(void* _1696_$self_ptr);
int64_t _1700_b(void* _1700_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1695_$vtable = {
    .a = _1696_a,
};

struct vtable_$trait143 _1698_$vtable = {
    .b = _1700_b,
};


/* Function definitions */
int64_t _1702_main(void){
    int64_t _1703_x;
    int64_t _1703_y;
    int64_t* _1702_t5;
    int64_t _1702_t4;
    int64_t* _1702_t8;
    int64_t _1702_t7;
    int64_t _1702_$retval;
    _1703_x = 300;
    _1703_y = 2;
    _1702_t5 = &_1703_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _1702_t4 = _1695_$vtable.a(_1702_t5);
    $line_idx--;
    _1702_t8 = &_1703_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _1702_t7 = _1698_$vtable.b(_1702_t8);
    $line_idx--;
    _1702_$retval = $add_int64_t(_1702_t4, _1702_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _1702_$retval;
}

int64_t _1696_a(void* _1696_$self_ptr){
    int64_t _1696_$retval;
    _1696_$retval = *(int64_t*)_1696_$self_ptr;
    return _1696_$retval;
}

int64_t _1700_b(void* _1700_$self_ptr){
    int64_t _1701_self;
    int64_t _1700_t1;
    int64_t _1700_$retval;
    _1701_self = *(int64_t*)_1700_$self_ptr;
    _1700_t1 = 2;
    _1700_$retval = $mult_int64_t(_1701_self, _1700_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1700_$retval;
}


int main(void) {
  printf("%ld",_1702_main());
  return 0;
}
