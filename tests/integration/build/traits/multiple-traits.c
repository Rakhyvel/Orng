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
int64_t _1651_main(void);
int64_t _1653_do_things(struct struct4 _1653_t);
int64_t _1646_a(void* _1646_$self_ptr);
int64_t _1649_b(void* _1649_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1645_$vtable = {
    .a = _1646_a,
};

struct vtable_Trait_B _1648_$vtable = {
    .b = _1649_b,
};


/* Function definitions */
int64_t _1651_main(void){
    int64_t _1652_x;
    int64_t _1652_y;
    struct dyn1 _1651_t4;
    struct dyn1 _1652_x_d;
    struct dyn2 _1651_t6;
    struct dyn2 _1652_y_d;
    function3 _1651_t8;
    struct struct4 _1651_t10;
    int64_t _1651_t9;
    int64_t _1651_$retval;
    _1652_x = 3;
    _1652_y = 150;
    _1651_t4 = (struct dyn1) {&_1652_x, &_1645_$vtable};
    _1652_x_d = _1651_t4;
    _1651_t6 = (struct dyn2) {&_1652_y, &_1648_$vtable};
    _1652_y_d = _1651_t6;
    _1651_t8 = (function3) _1653_do_things;
    _1651_t10 = (struct struct4) {_1652_x_d, _1652_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1651_t9 = _1651_t8(_1651_t10);
    $line_idx--;
    _1651_$retval = _1651_t9;
    return _1651_$retval;
}

int64_t _1653_do_things(struct struct4 _1653_t){
    int64_t _1653_t0;
    int64_t _1653_t1;
    int64_t _1653_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1653_t0 = _1653_t._0.vtable->a(_1653_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1653_t1 = _1653_t._1.vtable->b(_1653_t._1.data_ptr);
    $line_idx--;
    _1653_$retval = $add_int64_t(_1653_t0, _1653_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1653_$retval;
}

int64_t _1646_a(void* _1646_$self_ptr){
    int64_t _1646_$retval;
    _1646_$retval = *(int64_t*)_1646_$self_ptr;
    return _1646_$retval;
}

int64_t _1649_b(void* _1649_$self_ptr){
    int64_t _1650_self;
    int64_t _1649_t1;
    int64_t _1649_$retval;
    _1650_self = *(int64_t*)_1649_$self_ptr;
    _1649_t1 = 2;
    _1649_$retval = $mult_int64_t(_1650_self, _1649_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1649_$retval;
}


int main(void) {
  printf("%ld",_1651_main());
  return 0;
}
