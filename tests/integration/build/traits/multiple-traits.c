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
int64_t _1695_main(void);
int64_t _1697_do_things(struct struct4 _1697_t);
int64_t _1690_a(void* _1690_$self_ptr);
int64_t _1693_b(void* _1693_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1689_$vtable = {
    .a = _1690_a,
};

struct vtable_Trait_B _1692_$vtable = {
    .b = _1693_b,
};


/* Function definitions */
int64_t _1695_main(void){
    int64_t _1696_x;
    int64_t _1696_y;
    struct dyn1 _1695_t4;
    struct dyn1 _1696_x_d;
    struct dyn2 _1695_t6;
    struct dyn2 _1696_y_d;
    function3 _1695_t8;
    struct struct4 _1695_t10;
    int64_t _1695_t9;
    int64_t _1695_$retval;
    _1696_x = 3;
    _1696_y = 150;
    _1695_t4 = (struct dyn1) {&_1696_x, &_1689_$vtable};
    _1696_x_d = _1695_t4;
    _1695_t6 = (struct dyn2) {&_1696_y, &_1692_$vtable};
    _1696_y_d = _1695_t6;
    _1695_t8 = (function3) _1697_do_things;
    _1695_t10 = (struct struct4) {_1696_x_d, _1696_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1695_t9 = _1695_t8(_1695_t10);
    $line_idx--;
    _1695_$retval = _1695_t9;
    return _1695_$retval;
}

int64_t _1697_do_things(struct struct4 _1697_t){
    int64_t _1697_t0;
    int64_t _1697_t1;
    int64_t _1697_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1697_t0 = _1697_t._0.vtable->a(_1697_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1697_t1 = _1697_t._1.vtable->b(_1697_t._1.data_ptr);
    $line_idx--;
    _1697_$retval = $add_int64_t(_1697_t0, _1697_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1697_$retval;
}

int64_t _1690_a(void* _1690_$self_ptr){
    int64_t _1690_$retval;
    _1690_$retval = *(int64_t*)_1690_$self_ptr;
    return _1690_$retval;
}

int64_t _1693_b(void* _1693_$self_ptr){
    int64_t _1694_self;
    int64_t _1693_t1;
    int64_t _1693_$retval;
    _1694_self = *(int64_t*)_1693_$self_ptr;
    _1693_t1 = 2;
    _1693_$retval = $mult_int64_t(_1694_self, _1693_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1693_$retval;
}


int main(void) {
  printf("%ld",_1695_main());
  return 0;
}
