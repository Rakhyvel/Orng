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
int64_t _1728_main(void);
int64_t _1730_do_things(struct struct4 _1730_t);
int64_t _1723_a(void* _1723_$self_ptr);
int64_t _1726_b(void* _1726_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1722_$vtable = {
    .a = _1723_a,
};

struct vtable_Trait_B _1725_$vtable = {
    .b = _1726_b,
};


/* Function definitions */
int64_t _1728_main(void){
    int64_t _1729_x;
    int64_t _1729_y;
    struct dyn1 _1728_t4;
    struct dyn1 _1729_x_d;
    struct dyn2 _1728_t6;
    struct dyn2 _1729_y_d;
    function3 _1728_t8;
    struct struct4 _1728_t10;
    int64_t _1728_t9;
    int64_t _1728_$retval;
    _1729_x = 3;
    _1729_y = 150;
    _1728_t4 = (struct dyn1) {&_1729_x, &_1722_$vtable};
    _1729_x_d = _1728_t4;
    _1728_t6 = (struct dyn2) {&_1729_y, &_1725_$vtable};
    _1729_y_d = _1728_t6;
    _1728_t8 = (function3) _1730_do_things;
    _1728_t10 = (struct struct4) {_1729_x_d, _1729_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1728_t9 = _1728_t8(_1728_t10);
    $line_idx--;
    _1728_$retval = _1728_t9;
    return _1728_$retval;
}

int64_t _1730_do_things(struct struct4 _1730_t){
    int64_t _1730_t0;
    int64_t _1730_t1;
    int64_t _1730_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1730_t0 = _1730_t._0.vtable->a(_1730_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1730_t1 = _1730_t._1.vtable->b(_1730_t._1.data_ptr);
    $line_idx--;
    _1730_$retval = $add_int64_t(_1730_t0, _1730_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1730_$retval;
}

int64_t _1723_a(void* _1723_$self_ptr){
    int64_t _1723_$retval;
    _1723_$retval = *(int64_t*)_1723_$self_ptr;
    return _1723_$retval;
}

int64_t _1726_b(void* _1726_$self_ptr){
    int64_t _1727_self;
    int64_t _1726_t1;
    int64_t _1726_$retval;
    _1727_self = *(int64_t*)_1726_$self_ptr;
    _1726_t1 = 2;
    _1726_$retval = $mult_int64_t(_1727_self, _1726_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1726_$retval;
}


int main(void) {
  printf("%ld",_1728_main());
  return 0;
}
