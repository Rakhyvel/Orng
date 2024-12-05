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
int64_t _1709_main(void);
int64_t _1711_do_things(struct struct4 _1711_t);
int64_t _1704_a(void* _1704_$self_ptr);
int64_t _1707_b(void* _1707_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1703_$vtable = {
    .a = _1704_a,
};

struct vtable_Trait_B _1706_$vtable = {
    .b = _1707_b,
};


/* Function definitions */
int64_t _1709_main(void){
    int64_t _1710_x;
    int64_t _1710_y;
    struct dyn1 _1709_t4;
    struct dyn1 _1710_x_d;
    struct dyn2 _1709_t6;
    struct dyn2 _1710_y_d;
    function3 _1709_t8;
    struct struct4 _1709_t10;
    int64_t _1709_t9;
    int64_t _1709_$retval;
    _1710_x = 3;
    _1710_y = 150;
    _1709_t4 = (struct dyn1) {&_1710_x, &_1703_$vtable};
    _1710_x_d = _1709_t4;
    _1709_t6 = (struct dyn2) {&_1710_y, &_1706_$vtable};
    _1710_y_d = _1709_t6;
    _1709_t8 = (function3) _1711_do_things;
    _1709_t10 = (struct struct4) {_1710_x_d, _1710_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1709_t9 = _1709_t8(_1709_t10);
    $line_idx--;
    _1709_$retval = _1709_t9;
    return _1709_$retval;
}

int64_t _1711_do_things(struct struct4 _1711_t){
    int64_t _1711_t0;
    int64_t _1711_t1;
    int64_t _1711_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1711_t0 = _1711_t._0.vtable->a(_1711_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1711_t1 = _1711_t._1.vtable->b(_1711_t._1.data_ptr);
    $line_idx--;
    _1711_$retval = $add_int64_t(_1711_t0, _1711_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1711_$retval;
}

int64_t _1704_a(void* _1704_$self_ptr){
    int64_t _1704_$retval;
    _1704_$retval = *(int64_t*)_1704_$self_ptr;
    return _1704_$retval;
}

int64_t _1707_b(void* _1707_$self_ptr){
    int64_t _1708_self;
    int64_t _1707_t1;
    int64_t _1707_$retval;
    _1708_self = *(int64_t*)_1707_$self_ptr;
    _1707_t1 = 2;
    _1707_$retval = $mult_int64_t(_1708_self, _1707_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1707_$retval;
}


int main(void) {
  printf("%ld",_1709_main());
  return 0;
}
