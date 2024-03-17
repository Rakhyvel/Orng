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
int64_t _1584_main(void);
int64_t _1586_do_things(struct struct4 _1586_t);
int64_t _1579_a(void* _1579_$self_ptr);
int64_t _1582_b(void* _1582_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1578_$vtable = {
    .a = _1579_a,
};

struct vtable_Trait_B _1581_$vtable = {
    .b = _1582_b,
};


/* Function definitions */
int64_t _1584_main(void){
    int64_t _1585_x;
    int64_t _1585_y;
    struct dyn1 _1584_t4;
    struct dyn1 _1585_x_d;
    struct dyn2 _1584_t6;
    struct dyn2 _1585_y_d;
    function3 _1584_t8;
    struct struct4 _1584_t10;
    int64_t _1584_t9;
    int64_t _1584_$retval;
    _1585_x = 3;
    _1585_y = 150;
    _1584_t4 = (struct dyn1) {&_1585_x, &_1578_$vtable};
    _1585_x_d = _1584_t4;
    _1584_t6 = (struct dyn2) {&_1585_y, &_1581_$vtable};
    _1585_y_d = _1584_t6;
    _1584_t8 = (function3) _1586_do_things;
    _1584_t10 = (struct struct4) {_1585_x_d, _1585_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1584_t9 = _1584_t8(_1584_t10);
    $line_idx--;
    _1584_$retval = _1584_t9;
    return _1584_$retval;
}

int64_t _1586_do_things(struct struct4 _1586_t){
    int64_t _1586_t0;
    int64_t _1586_t1;
    int64_t _1586_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1586_t0 = _1586_t._0.vtable->a(_1586_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1586_t1 = _1586_t._1.vtable->b(_1586_t._1.data_ptr);
    $line_idx--;
    _1586_$retval = $add_int64_t(_1586_t0, _1586_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1586_$retval;
}

int64_t _1579_a(void* _1579_$self_ptr){
    int64_t _1579_$retval;
    _1579_$retval = *(int64_t*)_1579_$self_ptr;
    return _1579_$retval;
}

int64_t _1582_b(void* _1582_$self_ptr){
    int64_t _1583_self;
    int64_t _1582_t1;
    int64_t _1582_$retval;
    _1583_self = *(int64_t*)_1582_$self_ptr;
    _1582_t1 = 2;
    _1582_$retval = $mult_int64_t(_1583_self, _1582_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1582_$retval;
}


int main(void) {
  printf("%ld",_1584_main());
  return 0;
}
