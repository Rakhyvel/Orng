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
int64_t _1688_main(void);
int64_t _1690_do_things(struct struct4 _1690_t);
int64_t _1683_a(void* _1683_$self_ptr);
int64_t _1686_b(void* _1686_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1682_$vtable = {
    .a = _1683_a,
};

struct vtable_Trait_B _1685_$vtable = {
    .b = _1686_b,
};


/* Function definitions */
int64_t _1688_main(void){
    int64_t _1689_x;
    int64_t _1689_y;
    struct dyn1 _1688_t4;
    struct dyn1 _1689_x_d;
    struct dyn2 _1688_t6;
    struct dyn2 _1689_y_d;
    function3 _1688_t8;
    struct struct4 _1688_t10;
    int64_t _1688_t9;
    int64_t _1688_$retval;
    _1689_x = 3;
    _1689_y = 150;
    _1688_t4 = (struct dyn1) {&_1689_x, &_1682_$vtable};
    _1689_x_d = _1688_t4;
    _1688_t6 = (struct dyn2) {&_1689_y, &_1685_$vtable};
    _1689_y_d = _1688_t6;
    _1688_t8 = (function3) _1690_do_things;
    _1688_t10 = (struct struct4) {_1689_x_d, _1689_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1688_t9 = _1688_t8(_1688_t10);
    $line_idx--;
    _1688_$retval = _1688_t9;
    return _1688_$retval;
}

int64_t _1690_do_things(struct struct4 _1690_t){
    int64_t _1690_t0;
    int64_t _1690_t1;
    int64_t _1690_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1690_t0 = _1690_t._0.vtable->a(_1690_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1690_t1 = _1690_t._1.vtable->b(_1690_t._1.data_ptr);
    $line_idx--;
    _1690_$retval = $add_int64_t(_1690_t0, _1690_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1690_$retval;
}

int64_t _1683_a(void* _1683_$self_ptr){
    int64_t _1683_$retval;
    _1683_$retval = *(int64_t*)_1683_$self_ptr;
    return _1683_$retval;
}

int64_t _1686_b(void* _1686_$self_ptr){
    int64_t _1687_self;
    int64_t _1686_t1;
    int64_t _1686_$retval;
    _1687_self = *(int64_t*)_1686_$self_ptr;
    _1686_t1 = 2;
    _1686_$retval = $mult_int64_t(_1687_self, _1686_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1686_$retval;
}


int main(void) {
  printf("%ld",_1688_main());
  return 0;
}
