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
int64_t _1745_main(void);
int64_t _1747_do_things(struct struct4 _1747_t);
int64_t _1740_a(void* _1740_$self_ptr);
int64_t _1743_b(void* _1743_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _1739_$vtable = {
    .a = _1740_a,
};

struct vtable_Trait_B _1742_$vtable = {
    .b = _1743_b,
};


/* Function definitions */
int64_t _1745_main(void){
    int64_t _1746_x;
    int64_t _1746_y;
    struct dyn1 _1745_t4;
    struct dyn1 _1746_x_d;
    struct dyn2 _1745_t6;
    struct dyn2 _1746_y_d;
    function3 _1745_t8;
    struct struct4 _1745_t10;
    int64_t _1745_t9;
    int64_t _1745_$retval;
    _1746_x = 3;
    _1746_y = 150;
    _1745_t4 = (struct dyn1) {&_1746_x, &_1739_$vtable};
    _1746_x_d = _1745_t4;
    _1745_t6 = (struct dyn2) {&_1746_y, &_1742_$vtable};
    _1746_y_d = _1745_t6;
    _1745_t8 = (function3) _1747_do_things;
    _1745_t10 = (struct struct4) {_1746_x_d, _1746_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _1745_t9 = _1745_t8(_1745_t10);
    $line_idx--;
    _1745_$retval = _1745_t9;
    return _1745_$retval;
}

int64_t _1747_do_things(struct struct4 _1747_t){
    int64_t _1747_t0;
    int64_t _1747_t1;
    int64_t _1747_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _1747_t0 = _1747_t._0.vtable->a(_1747_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _1747_t1 = _1747_t._1.vtable->b(_1747_t._1.data_ptr);
    $line_idx--;
    _1747_$retval = $add_int64_t(_1747_t0, _1747_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _1747_$retval;
}

int64_t _1740_a(void* _1740_$self_ptr){
    int64_t _1740_$retval;
    _1740_$retval = *(int64_t*)_1740_$self_ptr;
    return _1740_$retval;
}

int64_t _1743_b(void* _1743_$self_ptr){
    int64_t _1744_self;
    int64_t _1743_t1;
    int64_t _1743_$retval;
    _1744_self = *(int64_t*)_1743_$self_ptr;
    _1743_t1 = 2;
    _1743_$retval = $mult_int64_t(_1744_self, _1743_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _1743_$retval;
}


int main(void) {
  printf("%ld",_1745_main());
  return 0;
}
