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
int64_t _1698_main(void);
int64_t _1700_do_things(struct struct4 _1700_t);
int64_t _1693_a(void* _1693_$self_ptr);
int64_t _1696_b(void* _1696_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1692_$vtable = {
    .a = _1693_a,
};

struct vtable_Trait_B _1695_$vtable = {
    .b = _1696_b,
};


/* Function definitions */
int64_t _1698_main(void){
    int64_t _1699_x;
    int64_t _1699_y;
    struct dyn1 _1698_t4;
    struct dyn1 _1699_x_d;
    struct dyn2 _1698_t6;
    struct dyn2 _1699_y_d;
    function3 _1698_t8;
    struct struct4 _1698_t10;
    int64_t _1698_t9;
    int64_t _1698_$retval;
    _1699_x = 3;
    _1699_y = 150;
    _1698_t4 = (struct dyn1) {&_1699_x, &_1692_$vtable};
    _1699_x_d = _1698_t4;
    _1698_t6 = (struct dyn2) {&_1699_y, &_1695_$vtable};
    _1699_y_d = _1698_t6;
    _1698_t8 = (function3) _1700_do_things;
    _1698_t10 = (struct struct4) {_1699_x_d, _1699_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1698_t9 = _1698_t8(_1698_t10);
    $line_idx--;
    _1698_$retval = _1698_t9;
    return _1698_$retval;
}

int64_t _1700_do_things(struct struct4 _1700_t){
    int64_t _1700_t0;
    int64_t _1700_t1;
    int64_t _1700_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1700_t0 = _1700_t._0.vtable->a(_1700_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1700_t1 = _1700_t._1.vtable->b(_1700_t._1.data_ptr);
    $line_idx--;
    _1700_$retval = $add_int64_t(_1700_t0, _1700_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1700_$retval;
}

int64_t _1693_a(void* _1693_$self_ptr){
    int64_t _1693_$retval;
    _1693_$retval = *(int64_t*)_1693_$self_ptr;
    return _1693_$retval;
}

int64_t _1696_b(void* _1696_$self_ptr){
    int64_t _1697_self;
    int64_t _1696_t1;
    int64_t _1696_$retval;
    _1697_self = *(int64_t*)_1696_$self_ptr;
    _1696_t1 = 2;
    _1696_$retval = $mult_int64_t(_1697_self, _1696_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1696_$retval;
}


int main(void) {
  printf("%ld",_1698_main());
  return 0;
}
