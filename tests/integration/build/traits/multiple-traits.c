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
int64_t _1598_main(void);
int64_t _1600_do_things(struct struct4 _1600_t);
int64_t _1593_a(void* _1593_$self_ptr);
int64_t _1596_b(void* _1596_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1592_$vtable = {
    .a = _1593_a,
};

struct vtable_Trait_B _1595_$vtable = {
    .b = _1596_b,
};


/* Function definitions */
int64_t _1598_main(void){
    int64_t _1599_x;
    int64_t _1599_y;
    struct dyn1 _1598_t4;
    struct dyn1 _1599_x_d;
    struct dyn2 _1598_t6;
    struct dyn2 _1599_y_d;
    function3 _1598_t8;
    struct struct4 _1598_t10;
    int64_t _1598_t9;
    int64_t _1598_$retval;
    _1599_x = 3;
    _1599_y = 150;
    _1598_t4 = (struct dyn1) {&_1599_x, &_1592_$vtable};
    _1599_x_d = _1598_t4;
    _1598_t6 = (struct dyn2) {&_1599_y, &_1595_$vtable};
    _1599_y_d = _1598_t6;
    _1598_t8 = (function3) _1600_do_things;
    _1598_t10 = (struct struct4) {_1599_x_d, _1599_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1598_t9 = _1598_t8(_1598_t10);
    $line_idx--;
    _1598_$retval = _1598_t9;
    return _1598_$retval;
}

int64_t _1600_do_things(struct struct4 _1600_t){
    int64_t _1600_t0;
    int64_t _1600_t1;
    int64_t _1600_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1600_t0 = _1600_t._0.vtable->a(_1600_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1600_t1 = _1600_t._1.vtable->b(_1600_t._1.data_ptr);
    $line_idx--;
    _1600_$retval = $add_int64_t(_1600_t0, _1600_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1600_$retval;
}

int64_t _1593_a(void* _1593_$self_ptr){
    int64_t _1593_$retval;
    _1593_$retval = *(int64_t*)_1593_$self_ptr;
    return _1593_$retval;
}

int64_t _1596_b(void* _1596_$self_ptr){
    int64_t _1597_self;
    int64_t _1596_t1;
    int64_t _1596_$retval;
    _1597_self = *(int64_t*)_1596_$self_ptr;
    _1596_t1 = 2;
    _1596_$retval = $mult_int64_t(_1597_self, _1596_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1596_$retval;
}


int main(void) {
  printf("%ld",_1598_main());
  return 0;
}
