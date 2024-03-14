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
int64_t _1613_main(void);
int64_t _1615_do_things(struct struct4 _1615_t);
int64_t _1608_a(void* _1608_$self_ptr);
int64_t _1611_b(void* _1611_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1607_$vtable = {
    .a = _1608_a,
};

struct vtable_Trait_B _1610_$vtable = {
    .b = _1611_b,
};


/* Function definitions */
int64_t _1613_main(void){
    int64_t _1614_x;
    int64_t _1614_y;
    struct dyn1 _1613_t4;
    struct dyn1 _1614_x_d;
    struct dyn2 _1613_t6;
    struct dyn2 _1614_y_d;
    function3 _1613_t8;
    struct struct4 _1613_t10;
    int64_t _1613_t9;
    int64_t _1613_$retval;
    _1614_x = 3;
    _1614_y = 150;
    _1613_t4 = (struct dyn1) {&_1614_x, &_1607_$vtable};
    _1614_x_d = _1613_t4;
    _1613_t6 = (struct dyn2) {&_1614_y, &_1610_$vtable};
    _1614_y_d = _1613_t6;
    _1613_t8 = (function3) _1615_do_things;
    _1613_t10 = (struct struct4) {_1614_x_d, _1614_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1613_t9 = _1613_t8(_1613_t10);
    $line_idx--;
    _1613_$retval = _1613_t9;
    return _1613_$retval;
}

int64_t _1615_do_things(struct struct4 _1615_t){
    int64_t _1615_t0;
    int64_t _1615_t1;
    int64_t _1615_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1615_t0 = _1615_t._0.vtable->a(_1615_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1615_t1 = _1615_t._1.vtable->b(_1615_t._1.data_ptr);
    $line_idx--;
    _1615_$retval = $add_int64_t(_1615_t0, _1615_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1615_$retval;
}

int64_t _1608_a(void* _1608_$self_ptr){
    int64_t _1608_$retval;
    _1608_$retval = *(int64_t*)_1608_$self_ptr;
    return _1608_$retval;
}

int64_t _1611_b(void* _1611_$self_ptr){
    int64_t _1612_self;
    int64_t _1611_t1;
    int64_t _1611_$retval;
    _1612_self = *(int64_t*)_1611_$self_ptr;
    _1611_t1 = 2;
    _1611_$retval = $mult_int64_t(_1612_self, _1611_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1611_$retval;
}


int main(void) {
  printf("%ld",_1613_main());
  return 0;
}
