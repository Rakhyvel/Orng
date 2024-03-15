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
int64_t _1579_main(void);
int64_t _1581_do_things(struct struct4 _1581_t);
int64_t _1574_a(void* _1574_$self_ptr);
int64_t _1577_b(void* _1577_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1573_$vtable = {
    .a = _1574_a,
};

struct vtable_Trait_B _1576_$vtable = {
    .b = _1577_b,
};


/* Function definitions */
int64_t _1579_main(void){
    int64_t _1580_x;
    int64_t _1580_y;
    struct dyn1 _1579_t4;
    struct dyn1 _1580_x_d;
    struct dyn2 _1579_t6;
    struct dyn2 _1580_y_d;
    function3 _1579_t8;
    struct struct4 _1579_t10;
    int64_t _1579_t9;
    int64_t _1579_$retval;
    _1580_x = 3;
    _1580_y = 150;
    _1579_t4 = (struct dyn1) {&_1580_x, &_1573_$vtable};
    _1580_x_d = _1579_t4;
    _1579_t6 = (struct dyn2) {&_1580_y, &_1576_$vtable};
    _1580_y_d = _1579_t6;
    _1579_t8 = (function3) _1581_do_things;
    _1579_t10 = (struct struct4) {_1580_x_d, _1580_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1579_t9 = _1579_t8(_1579_t10);
    $line_idx--;
    _1579_$retval = _1579_t9;
    return _1579_$retval;
}

int64_t _1581_do_things(struct struct4 _1581_t){
    int64_t _1581_t0;
    int64_t _1581_t1;
    int64_t _1581_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1581_t0 = _1581_t._0.vtable->a(_1581_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1581_t1 = _1581_t._1.vtable->b(_1581_t._1.data_ptr);
    $line_idx--;
    _1581_$retval = $add_int64_t(_1581_t0, _1581_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1581_$retval;
}

int64_t _1574_a(void* _1574_$self_ptr){
    int64_t _1574_$retval;
    _1574_$retval = *(int64_t*)_1574_$self_ptr;
    return _1574_$retval;
}

int64_t _1577_b(void* _1577_$self_ptr){
    int64_t _1578_self;
    int64_t _1577_t1;
    int64_t _1577_$retval;
    _1578_self = *(int64_t*)_1577_$self_ptr;
    _1577_t1 = 2;
    _1577_$retval = $mult_int64_t(_1578_self, _1577_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1577_$retval;
}


int main(void) {
  printf("%ld",_1579_main());
  return 0;
}
