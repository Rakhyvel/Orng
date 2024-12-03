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
int64_t _1703_main(void);
int64_t _1705_do_things(struct struct4 _1705_t);
int64_t _1698_a(void* _1698_$self_ptr);
int64_t _1701_b(void* _1701_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1697_$vtable = {
    .a = _1698_a,
};

struct vtable_Trait_B _1700_$vtable = {
    .b = _1701_b,
};


/* Function definitions */
int64_t _1703_main(void){
    int64_t _1704_x;
    int64_t _1704_y;
    struct dyn1 _1703_t4;
    struct dyn1 _1704_x_d;
    struct dyn2 _1703_t6;
    struct dyn2 _1704_y_d;
    function3 _1703_t8;
    struct struct4 _1703_t10;
    int64_t _1703_t9;
    int64_t _1703_$retval;
    _1704_x = 3;
    _1704_y = 150;
    _1703_t4 = (struct dyn1) {&_1704_x, &_1697_$vtable};
    _1704_x_d = _1703_t4;
    _1703_t6 = (struct dyn2) {&_1704_y, &_1700_$vtable};
    _1704_y_d = _1703_t6;
    _1703_t8 = (function3) _1705_do_things;
    _1703_t10 = (struct struct4) {_1704_x_d, _1704_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1703_t9 = _1703_t8(_1703_t10);
    $line_idx--;
    _1703_$retval = _1703_t9;
    return _1703_$retval;
}

int64_t _1705_do_things(struct struct4 _1705_t){
    int64_t _1705_t0;
    int64_t _1705_t1;
    int64_t _1705_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1705_t0 = _1705_t._0.vtable->a(_1705_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1705_t1 = _1705_t._1.vtable->b(_1705_t._1.data_ptr);
    $line_idx--;
    _1705_$retval = $add_int64_t(_1705_t0, _1705_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1705_$retval;
}

int64_t _1698_a(void* _1698_$self_ptr){
    int64_t _1698_$retval;
    _1698_$retval = *(int64_t*)_1698_$self_ptr;
    return _1698_$retval;
}

int64_t _1701_b(void* _1701_$self_ptr){
    int64_t _1702_self;
    int64_t _1701_t1;
    int64_t _1701_$retval;
    _1702_self = *(int64_t*)_1701_$self_ptr;
    _1701_t1 = 2;
    _1701_$retval = $mult_int64_t(_1702_self, _1701_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1701_$retval;
}


int main(void) {
  printf("%ld",_1703_main());
  return 0;
}
