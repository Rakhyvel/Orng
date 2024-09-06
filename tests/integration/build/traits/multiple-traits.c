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
int64_t _1677_main(void);
int64_t _1679_do_things(struct struct4 _1679_t);
int64_t _1672_a(void* _1672_$self_ptr);
int64_t _1675_b(void* _1675_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1671_$vtable = {
    .a = _1672_a,
};

struct vtable_Trait_B _1674_$vtable = {
    .b = _1675_b,
};


/* Function definitions */
int64_t _1677_main(void){
    int64_t _1678_x;
    int64_t _1678_y;
    struct dyn1 _1677_t4;
    struct dyn1 _1678_x_d;
    struct dyn2 _1677_t6;
    struct dyn2 _1678_y_d;
    function3 _1677_t8;
    struct struct4 _1677_t10;
    int64_t _1677_t9;
    int64_t _1677_$retval;
    _1678_x = 3;
    _1678_y = 150;
    _1677_t4 = (struct dyn1) {&_1678_x, &_1671_$vtable};
    _1678_x_d = _1677_t4;
    _1677_t6 = (struct dyn2) {&_1678_y, &_1674_$vtable};
    _1678_y_d = _1677_t6;
    _1677_t8 = (function3) _1679_do_things;
    _1677_t10 = (struct struct4) {_1678_x_d, _1678_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1677_t9 = _1677_t8(_1677_t10);
    $line_idx--;
    _1677_$retval = _1677_t9;
    return _1677_$retval;
}

int64_t _1679_do_things(struct struct4 _1679_t){
    int64_t _1679_t0;
    int64_t _1679_t1;
    int64_t _1679_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1679_t0 = _1679_t._0.vtable->a(_1679_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1679_t1 = _1679_t._1.vtable->b(_1679_t._1.data_ptr);
    $line_idx--;
    _1679_$retval = $add_int64_t(_1679_t0, _1679_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1679_$retval;
}

int64_t _1672_a(void* _1672_$self_ptr){
    int64_t _1672_$retval;
    _1672_$retval = *(int64_t*)_1672_$self_ptr;
    return _1672_$retval;
}

int64_t _1675_b(void* _1675_$self_ptr){
    int64_t _1676_self;
    int64_t _1675_t1;
    int64_t _1675_$retval;
    _1676_self = *(int64_t*)_1675_$self_ptr;
    _1675_t1 = 2;
    _1675_$retval = $mult_int64_t(_1676_self, _1675_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1675_$retval;
}


int main(void) {
  printf("%ld",_1677_main());
  return 0;
}
