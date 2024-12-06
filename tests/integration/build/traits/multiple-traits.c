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
int64_t _1715_main(void);
int64_t _1717_do_things(struct struct4 _1717_t);
int64_t _1710_a(void* _1710_$self_ptr);
int64_t _1713_b(void* _1713_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1709_$vtable = {
    .a = _1710_a,
};

struct vtable_Trait_B _1712_$vtable = {
    .b = _1713_b,
};


/* Function definitions */
int64_t _1715_main(void){
    int64_t _1716_x;
    int64_t _1716_y;
    struct dyn1 _1715_t4;
    struct dyn1 _1716_x_d;
    struct dyn2 _1715_t6;
    struct dyn2 _1716_y_d;
    function3 _1715_t8;
    struct struct4 _1715_t10;
    int64_t _1715_t9;
    int64_t _1715_$retval;
    _1716_x = 3;
    _1716_y = 150;
    _1715_t4 = (struct dyn1) {&_1716_x, &_1709_$vtable};
    _1716_x_d = _1715_t4;
    _1715_t6 = (struct dyn2) {&_1716_y, &_1712_$vtable};
    _1716_y_d = _1715_t6;
    _1715_t8 = (function3) _1717_do_things;
    _1715_t10 = (struct struct4) {_1716_x_d, _1716_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1715_t9 = _1715_t8(_1715_t10);
    $line_idx--;
    _1715_$retval = _1715_t9;
    return _1715_$retval;
}

int64_t _1717_do_things(struct struct4 _1717_t){
    int64_t _1717_t0;
    int64_t _1717_t1;
    int64_t _1717_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1717_t0 = _1717_t._0.vtable->a(_1717_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1717_t1 = _1717_t._1.vtable->b(_1717_t._1.data_ptr);
    $line_idx--;
    _1717_$retval = $add_int64_t(_1717_t0, _1717_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1717_$retval;
}

int64_t _1710_a(void* _1710_$self_ptr){
    int64_t _1710_$retval;
    _1710_$retval = *(int64_t*)_1710_$self_ptr;
    return _1710_$retval;
}

int64_t _1713_b(void* _1713_$self_ptr){
    int64_t _1714_self;
    int64_t _1713_t1;
    int64_t _1713_$retval;
    _1714_self = *(int64_t*)_1713_$self_ptr;
    _1713_t1 = 2;
    _1713_$retval = $mult_int64_t(_1714_self, _1713_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1713_$retval;
}


int main(void) {
  printf("%ld",_1715_main());
  return 0;
}
