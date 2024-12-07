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
int64_t _1723_main(void);
int64_t _1725_do_things(struct struct4 _1725_t);
int64_t _1718_a(void* _1718_$self_ptr);
int64_t _1721_b(void* _1721_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1717_$vtable = {
    .a = _1718_a,
};

struct vtable_Trait_B _1720_$vtable = {
    .b = _1721_b,
};


/* Function definitions */
int64_t _1723_main(void){
    int64_t _1724_x;
    int64_t _1724_y;
    struct dyn1 _1723_t4;
    struct dyn1 _1724_x_d;
    struct dyn2 _1723_t6;
    struct dyn2 _1724_y_d;
    function3 _1723_t8;
    struct struct4 _1723_t10;
    int64_t _1723_t9;
    int64_t _1723_$retval;
    _1724_x = 3;
    _1724_y = 150;
    _1723_t4 = (struct dyn1) {&_1724_x, &_1717_$vtable};
    _1724_x_d = _1723_t4;
    _1723_t6 = (struct dyn2) {&_1724_y, &_1720_$vtable};
    _1724_y_d = _1723_t6;
    _1723_t8 = (function3) _1725_do_things;
    _1723_t10 = (struct struct4) {_1724_x_d, _1724_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1723_t9 = _1723_t8(_1723_t10);
    $line_idx--;
    _1723_$retval = _1723_t9;
    return _1723_$retval;
}

int64_t _1725_do_things(struct struct4 _1725_t){
    int64_t _1725_t0;
    int64_t _1725_t1;
    int64_t _1725_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1725_t0 = _1725_t._0.vtable->a(_1725_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1725_t1 = _1725_t._1.vtable->b(_1725_t._1.data_ptr);
    $line_idx--;
    _1725_$retval = $add_int64_t(_1725_t0, _1725_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1725_$retval;
}

int64_t _1718_a(void* _1718_$self_ptr){
    int64_t _1718_$retval;
    _1718_$retval = *(int64_t*)_1718_$self_ptr;
    return _1718_$retval;
}

int64_t _1721_b(void* _1721_$self_ptr){
    int64_t _1722_self;
    int64_t _1721_t1;
    int64_t _1721_$retval;
    _1722_self = *(int64_t*)_1721_$self_ptr;
    _1721_t1 = 2;
    _1721_$retval = $mult_int64_t(_1722_self, _1721_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1721_$retval;
}


int main(void) {
  printf("%ld",_1723_main());
  return 0;
}
