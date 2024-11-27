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
int64_t _1693_main(void);
int64_t _1695_do_things(struct struct4 _1695_t);
int64_t _1688_a(void* _1688_$self_ptr);
int64_t _1691_b(void* _1691_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1687_$vtable = {
    .a = _1688_a,
};

struct vtable_Trait_B _1690_$vtable = {
    .b = _1691_b,
};


/* Function definitions */
int64_t _1693_main(void){
    int64_t _1694_x;
    int64_t _1694_y;
    struct dyn1 _1693_t4;
    struct dyn1 _1694_x_d;
    struct dyn2 _1693_t6;
    struct dyn2 _1694_y_d;
    function3 _1693_t8;
    struct struct4 _1693_t10;
    int64_t _1693_t9;
    int64_t _1693_$retval;
    _1694_x = 3;
    _1694_y = 150;
    _1693_t4 = (struct dyn1) {&_1694_x, &_1687_$vtable};
    _1694_x_d = _1693_t4;
    _1693_t6 = (struct dyn2) {&_1694_y, &_1690_$vtable};
    _1694_y_d = _1693_t6;
    _1693_t8 = (function3) _1695_do_things;
    _1693_t10 = (struct struct4) {_1694_x_d, _1694_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1693_t9 = _1693_t8(_1693_t10);
    $line_idx--;
    _1693_$retval = _1693_t9;
    return _1693_$retval;
}

int64_t _1695_do_things(struct struct4 _1695_t){
    int64_t _1695_t0;
    int64_t _1695_t1;
    int64_t _1695_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1695_t0 = _1695_t._0.vtable->a(_1695_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1695_t1 = _1695_t._1.vtable->b(_1695_t._1.data_ptr);
    $line_idx--;
    _1695_$retval = $add_int64_t(_1695_t0, _1695_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1695_$retval;
}

int64_t _1688_a(void* _1688_$self_ptr){
    int64_t _1688_$retval;
    _1688_$retval = *(int64_t*)_1688_$self_ptr;
    return _1688_$retval;
}

int64_t _1691_b(void* _1691_$self_ptr){
    int64_t _1692_self;
    int64_t _1691_t1;
    int64_t _1691_$retval;
    _1692_self = *(int64_t*)_1691_$self_ptr;
    _1691_t1 = 2;
    _1691_$retval = $mult_int64_t(_1692_self, _1691_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1691_$retval;
}


int main(void) {
  printf("%ld",_1693_main());
  return 0;
}
