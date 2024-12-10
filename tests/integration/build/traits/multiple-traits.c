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
int64_t _1743_main(void);
int64_t _1745_do_things(struct struct4 _1745_t);
int64_t _1738_a(void* _1738_$self_ptr);
int64_t _1741_b(void* _1741_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1737_$vtable = {
    .a = _1738_a,
};

struct vtable_Trait_B _1740_$vtable = {
    .b = _1741_b,
};


/* Function definitions */
int64_t _1743_main(void){
    int64_t _1744_x;
    int64_t _1744_y;
    struct dyn1 _1743_t4;
    struct dyn1 _1744_x_d;
    struct dyn2 _1743_t6;
    struct dyn2 _1744_y_d;
    function3 _1743_t8;
    struct struct4 _1743_t10;
    int64_t _1743_t9;
    int64_t _1743_$retval;
    _1744_x = 3;
    _1744_y = 150;
    _1743_t4 = (struct dyn1) {&_1744_x, &_1737_$vtable};
    _1744_x_d = _1743_t4;
    _1743_t6 = (struct dyn2) {&_1744_y, &_1740_$vtable};
    _1744_y_d = _1743_t6;
    _1743_t8 = (function3) _1745_do_things;
    _1743_t10 = (struct struct4) {_1744_x_d, _1744_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1743_t9 = _1743_t8(_1743_t10);
    $line_idx--;
    _1743_$retval = _1743_t9;
    return _1743_$retval;
}

int64_t _1745_do_things(struct struct4 _1745_t){
    int64_t _1745_t0;
    int64_t _1745_t1;
    int64_t _1745_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1745_t0 = _1745_t._0.vtable->a(_1745_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1745_t1 = _1745_t._1.vtable->b(_1745_t._1.data_ptr);
    $line_idx--;
    _1745_$retval = $add_int64_t(_1745_t0, _1745_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1745_$retval;
}

int64_t _1738_a(void* _1738_$self_ptr){
    int64_t _1738_$retval;
    _1738_$retval = *(int64_t*)_1738_$self_ptr;
    return _1738_$retval;
}

int64_t _1741_b(void* _1741_$self_ptr){
    int64_t _1742_self;
    int64_t _1741_t1;
    int64_t _1741_$retval;
    _1742_self = *(int64_t*)_1741_$self_ptr;
    _1741_t1 = 2;
    _1741_$retval = $mult_int64_t(_1742_self, _1741_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1741_$retval;
}


int main(void) {
  printf("%ld",_1743_main());
  return 0;
}
