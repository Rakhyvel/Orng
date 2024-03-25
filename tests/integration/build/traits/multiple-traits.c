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
int64_t _1607_main(void);
int64_t _1609_do_things(struct struct4 _1609_t);
int64_t _1602_a(void* _1602_$self_ptr);
int64_t _1605_b(void* _1605_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1601_$vtable = {
    .a = _1602_a,
};

struct vtable_Trait_B _1604_$vtable = {
    .b = _1605_b,
};


/* Function definitions */
int64_t _1607_main(void){
    int64_t _1608_x;
    int64_t _1608_y;
    struct dyn1 _1607_t4;
    struct dyn1 _1608_x_d;
    struct dyn2 _1607_t6;
    struct dyn2 _1608_y_d;
    function3 _1607_t8;
    struct struct4 _1607_t10;
    int64_t _1607_t9;
    int64_t _1607_$retval;
    _1608_x = 3;
    _1608_y = 150;
    _1607_t4 = (struct dyn1) {&_1608_x, &_1601_$vtable};
    _1608_x_d = _1607_t4;
    _1607_t6 = (struct dyn2) {&_1608_y, &_1604_$vtable};
    _1608_y_d = _1607_t6;
    _1607_t8 = (function3) _1609_do_things;
    _1607_t10 = (struct struct4) {_1608_x_d, _1608_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1607_t9 = _1607_t8(_1607_t10);
    $line_idx--;
    _1607_$retval = _1607_t9;
    return _1607_$retval;
}

int64_t _1609_do_things(struct struct4 _1609_t){
    int64_t _1609_t0;
    int64_t _1609_t1;
    int64_t _1609_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1609_t0 = _1609_t._0.vtable->a(_1609_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1609_t1 = _1609_t._1.vtable->b(_1609_t._1.data_ptr);
    $line_idx--;
    _1609_$retval = $add_int64_t(_1609_t0, _1609_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1609_$retval;
}

int64_t _1602_a(void* _1602_$self_ptr){
    int64_t _1602_$retval;
    _1602_$retval = *(int64_t*)_1602_$self_ptr;
    return _1602_$retval;
}

int64_t _1605_b(void* _1605_$self_ptr){
    int64_t _1606_self;
    int64_t _1605_t1;
    int64_t _1605_$retval;
    _1606_self = *(int64_t*)_1605_$self_ptr;
    _1605_t1 = 2;
    _1605_$retval = $mult_int64_t(_1606_self, _1605_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1605_$retval;
}


int main(void) {
  printf("%ld",_1607_main());
  return 0;
}
