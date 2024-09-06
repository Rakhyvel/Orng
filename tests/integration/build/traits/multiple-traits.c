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
int64_t _1670_main(void);
int64_t _1672_do_things(struct struct4 _1672_t);
int64_t _1665_a(void* _1665_$self_ptr);
int64_t _1668_b(void* _1668_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1664_$vtable = {
    .a = _1665_a,
};

struct vtable_Trait_B _1667_$vtable = {
    .b = _1668_b,
};


/* Function definitions */
int64_t _1670_main(void){
    int64_t _1671_x;
    int64_t _1671_y;
    struct dyn1 _1670_t4;
    struct dyn1 _1671_x_d;
    struct dyn2 _1670_t6;
    struct dyn2 _1671_y_d;
    function3 _1670_t8;
    struct struct4 _1670_t10;
    int64_t _1670_t9;
    int64_t _1670_$retval;
    _1671_x = 3;
    _1671_y = 150;
    _1670_t4 = (struct dyn1) {&_1671_x, &_1664_$vtable};
    _1671_x_d = _1670_t4;
    _1670_t6 = (struct dyn2) {&_1671_y, &_1667_$vtable};
    _1671_y_d = _1670_t6;
    _1670_t8 = (function3) _1672_do_things;
    _1670_t10 = (struct struct4) {_1671_x_d, _1671_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1670_t9 = _1670_t8(_1670_t10);
    $line_idx--;
    _1670_$retval = _1670_t9;
    return _1670_$retval;
}

int64_t _1672_do_things(struct struct4 _1672_t){
    int64_t _1672_t0;
    int64_t _1672_t1;
    int64_t _1672_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1672_t0 = _1672_t._0.vtable->a(_1672_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1672_t1 = _1672_t._1.vtable->b(_1672_t._1.data_ptr);
    $line_idx--;
    _1672_$retval = $add_int64_t(_1672_t0, _1672_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1672_$retval;
}

int64_t _1665_a(void* _1665_$self_ptr){
    int64_t _1665_$retval;
    _1665_$retval = *(int64_t*)_1665_$self_ptr;
    return _1665_$retval;
}

int64_t _1668_b(void* _1668_$self_ptr){
    int64_t _1669_self;
    int64_t _1668_t1;
    int64_t _1668_$retval;
    _1669_self = *(int64_t*)_1668_$self_ptr;
    _1668_t1 = 2;
    _1668_$retval = $mult_int64_t(_1669_self, _1668_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1668_$retval;
}


int main(void) {
  printf("%ld",_1670_main());
  return 0;
}
