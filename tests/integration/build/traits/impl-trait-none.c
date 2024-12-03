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

struct vtable_$trait5 {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _84_main(void);
int64_t _78_a(void* _78_$self_ptr);
int64_t _82_b(void* _82_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _77_$vtable = {
    .a = _78_a,
};

struct vtable_$trait5 _80_$vtable = {
    .b = _82_b,
};


/* Function definitions */
int64_t _84_main(void){
    int64_t _85_x;
    int64_t _85_y;
    int64_t* _84_t5;
    int64_t _84_t4;
    int64_t* _84_t8;
    int64_t _84_t7;
    int64_t _84_$retval;
    _85_x = 300;
    _85_y = 2;
    _84_t5 = &_85_x;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:8:\n    x.>a() + y.>b()\n      ^";
    _84_t4 = _77_$vtable.a(_84_t5);
    $line_idx--;
    _84_t8 = &_85_y;
    $lines[$line_idx++] = "tests/integration/traits/impl-trait-none.orng:18:17:\n    x.>a() + y.>b()\n               ^";
    _84_t7 = _80_$vtable.b(_84_t8);
    $line_idx--;
    _84_$retval = $add_int64_t(_84_t4, _84_t7, "tests/integration/traits/impl-trait-none.orng:18:13:\n    x.>a() + y.>b()\n           ^");
    return _84_$retval;
}

int64_t _78_a(void* _78_$self_ptr){
    int64_t _78_$retval;
    _78_$retval = *(int64_t*)_78_$self_ptr;
    return _78_$retval;
}

int64_t _82_b(void* _82_$self_ptr){
    int64_t _83_self;
    int64_t _82_t1;
    int64_t _82_$retval;
    _83_self = *(int64_t*)_82_$self_ptr;
    _82_t1 = 2;
    _82_$retval = $mult_int64_t(_83_self, _82_t1, "tests/integration/traits/impl-trait-none.orng:12:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _82_$retval;
}


int main(void) {
  printf("%ld",_84_main());
  return 0;
}
