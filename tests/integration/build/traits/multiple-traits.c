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
int64_t _1612_main(void);
int64_t _1614_do_things(struct struct4 _1614_t);
int64_t _1607_a(void* _1607_$self_ptr);
int64_t _1610_b(void* _1610_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1606_$vtable = {
    .a = _1607_a,
};

struct vtable_Trait_B _1609_$vtable = {
    .b = _1610_b,
};


/* Function definitions */
int64_t _1612_main(void){
    int64_t _1613_x;
    int64_t _1613_y;
    struct dyn1 _1612_t4;
    struct dyn1 _1613_x_d;
    struct dyn2 _1612_t6;
    struct dyn2 _1613_y_d;
    function3 _1612_t8;
    struct struct4 _1612_t10;
    int64_t _1612_t9;
    int64_t _1612_$retval;
    _1613_x = 3;
    _1613_y = 150;
    _1612_t4 = (struct dyn1) {&_1613_x, &_1606_$vtable};
    _1613_x_d = _1612_t4;
    _1612_t6 = (struct dyn2) {&_1613_y, &_1609_$vtable};
    _1613_y_d = _1612_t6;
    _1612_t8 = (function3) _1614_do_things;
    _1612_t10 = (struct struct4) {_1613_x_d, _1613_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1612_t9 = _1612_t8(_1612_t10);
    $line_idx--;
    _1612_$retval = _1612_t9;
    return _1612_$retval;
}

int64_t _1614_do_things(struct struct4 _1614_t){
    int64_t _1614_t0;
    int64_t _1614_t1;
    int64_t _1614_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1614_t0 = _1614_t._0.vtable->a(_1614_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1614_t1 = _1614_t._1.vtable->b(_1614_t._1.data_ptr);
    $line_idx--;
    _1614_$retval = $add_int64_t(_1614_t0, _1614_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1614_$retval;
}

int64_t _1607_a(void* _1607_$self_ptr){
    int64_t _1607_$retval;
    _1607_$retval = *(int64_t*)_1607_$self_ptr;
    return _1607_$retval;
}

int64_t _1610_b(void* _1610_$self_ptr){
    int64_t _1611_self;
    int64_t _1610_t1;
    int64_t _1610_$retval;
    _1611_self = *(int64_t*)_1610_$self_ptr;
    _1610_t1 = 2;
    _1610_$retval = $mult_int64_t(_1611_self, _1610_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1610_$retval;
}


int main(void) {
  printf("%ld",_1612_main());
  return 0;
}
