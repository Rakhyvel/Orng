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
int64_t _1662_main(void);
int64_t _1664_do_things(struct struct4 _1664_t);
int64_t _1657_a(void* _1657_$self_ptr);
int64_t _1660_b(void* _1660_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1656_$vtable = {
    .a = _1657_a,
};

struct vtable_Trait_B _1659_$vtable = {
    .b = _1660_b,
};


/* Function definitions */
int64_t _1662_main(void){
    int64_t _1663_x;
    int64_t _1663_y;
    struct dyn1 _1662_t4;
    struct dyn1 _1663_x_d;
    struct dyn2 _1662_t6;
    struct dyn2 _1663_y_d;
    function3 _1662_t8;
    struct struct4 _1662_t10;
    int64_t _1662_t9;
    int64_t _1662_$retval;
    _1663_x = 3;
    _1663_y = 150;
    _1662_t4 = (struct dyn1) {&_1663_x, &_1656_$vtable};
    _1663_x_d = _1662_t4;
    _1662_t6 = (struct dyn2) {&_1663_y, &_1659_$vtable};
    _1663_y_d = _1662_t6;
    _1662_t8 = (function3) _1664_do_things;
    _1662_t10 = (struct struct4) {_1663_x_d, _1663_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1662_t9 = _1662_t8(_1662_t10);
    $line_idx--;
    _1662_$retval = _1662_t9;
    return _1662_$retval;
}

int64_t _1664_do_things(struct struct4 _1664_t){
    int64_t _1664_t0;
    int64_t _1664_t1;
    int64_t _1664_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1664_t0 = _1664_t._0.vtable->a(_1664_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1664_t1 = _1664_t._1.vtable->b(_1664_t._1.data_ptr);
    $line_idx--;
    _1664_$retval = $add_int64_t(_1664_t0, _1664_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1664_$retval;
}

int64_t _1657_a(void* _1657_$self_ptr){
    int64_t _1657_$retval;
    _1657_$retval = *(int64_t*)_1657_$self_ptr;
    return _1657_$retval;
}

int64_t _1660_b(void* _1660_$self_ptr){
    int64_t _1661_self;
    int64_t _1660_t1;
    int64_t _1660_$retval;
    _1661_self = *(int64_t*)_1660_$self_ptr;
    _1660_t1 = 2;
    _1660_$retval = $mult_int64_t(_1661_self, _1660_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1660_$retval;
}


int main(void) {
  printf("%ld",_1662_main());
  return 0;
}
