/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct dyn1;
struct dyn2;
struct struct4;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void*);

struct dyn1 {
    void* data_ptr;
    struct vtable_Trait_A* vtable;
};

struct dyn2 {
    void* data_ptr;
    struct vtable_Trait_B* vtable;
};

struct struct4 {
    struct dyn1 _0;
    struct dyn2 _1;
};

typedef int64_t(*function3)(struct struct4);

/* Trait vtable type definitions */
struct vtable_Trait_A {
    int64_t(*a)(void*);
};

struct vtable_Trait_B {
    int64_t(*b)(void*);
};

/* Function forward definitions */
int64_t _73_main(void);
int64_t _75_do_things(struct struct4 _75_t);
int64_t _68_a(void* _68_$self_ptr);
int64_t _71_b(void* _71_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _67_$vtable = {
    .a = _68_a,
};

struct vtable_Trait_B _70_$vtable = {
    .b = _71_b,
};


/* Function definitions */
int64_t _73_main(void){
    int64_t _74_x;
    int64_t _74_y;
    struct dyn1 _73_t4;
    struct dyn1 _74_x_d;
    struct dyn2 _73_t6;
    struct dyn2 _74_y_d;
    function3 _73_t8;
    struct struct4 _73_t10;
    int64_t _73_t9;
    int64_t _73_$retval;
    _74_x = 3;
    _74_y = 150;
    _73_t4 = (struct dyn1) {&_74_x, &_67_$vtable};
    _74_x_d = _73_t4;
    _73_t6 = (struct dyn2) {&_74_y, &_70_$vtable};
    _74_y_d = _73_t6;
    _73_t8 = (function3) _75_do_things;
    _73_t10 = (struct struct4) {_74_x_d, _74_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _73_t9 = _73_t8(_73_t10);
    $line_idx--;
    _73_$retval = _73_t9;
    return _73_$retval;
}

int64_t _75_do_things(struct struct4 _75_t){
    int64_t _75_t0;
    int64_t _75_t1;
    int64_t _75_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _75_t0 = _75_t._0.vtable->a(_75_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _75_t1 = _75_t._1.vtable->b(_75_t._1.data_ptr);
    $line_idx--;
    _75_$retval = $add_int64_t(_75_t0, _75_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _75_$retval;
}

int64_t _68_a(void* _68_$self_ptr){
    int64_t _68_$retval;
    _68_$retval = *(int64_t*)_68_$self_ptr;
    return _68_$retval;
}

int64_t _71_b(void* _71_$self_ptr){
    int64_t _72_self;
    int64_t _71_t1;
    int64_t _71_$retval;
    _72_self = *(int64_t*)_71_$self_ptr;
    _71_t1 = 2;
    _71_$retval = $mult_int64_t(_72_self, _71_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _71_$retval;
}


int main(void) {
  printf("%ld",_73_main());
  return 0;
}
