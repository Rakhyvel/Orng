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
int64_t _105_main(void);
int64_t _107_do_things(struct struct4 _107_t);
int64_t _100_a(void* _100_$self_ptr);
int64_t _103_b(void* _103_$self_ptr);

/* Trait vtable implementations */
struct vtable_Trait_A _99_$vtable = {
    .a = _100_a,
};

struct vtable_Trait_B _102_$vtable = {
    .b = _103_b,
};


/* Function definitions */
int64_t _105_main(void){
    int64_t _106_x;
    int64_t _106_y;
    struct dyn1 _105_t4;
    struct dyn1 _106_x_d;
    struct dyn2 _105_t6;
    struct dyn2 _106_y_d;
    function3 _105_t8;
    struct struct4 _105_t10;
    int64_t _105_t9;
    int64_t _105_$retval;
    _106_x = 3;
    _106_y = 150;
    _105_t4 = (struct dyn1) {&_106_x, &_99_$vtable};
    _106_x_d = _105_t4;
    _105_t6 = (struct dyn2) {&_106_y, &_102_$vtable};
    _106_y_d = _105_t6;
    _105_t8 = (function3) _107_do_things;
    _105_t10 = (struct struct4) {_106_x_d, _106_y_d};
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:24:15:\n    do_things((x_d, y_d))\n             ^";
    _105_t9 = _105_t8(_105_t10);
    $line_idx--;
    _105_$retval = _105_t9;
    return _105_$retval;
}

int64_t _107_do_things(struct struct4 _107_t){
    int64_t _107_t0;
    int64_t _107_t1;
    int64_t _107_$retval;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:10:\n    t.a.>a() + t.b.>b()\n        ^";
    _107_t0 = _107_t._0.vtable->a(_107_t._0.data_ptr);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/traits/multiple-traits.orng:28:21:\n    t.a.>a() + t.b.>b()\n                   ^";
    _107_t1 = _107_t._1.vtable->b(_107_t._1.data_ptr);
    $line_idx--;
    _107_$retval = $add_int64_t(_107_t0, _107_t1, "tests/integration/traits/multiple-traits.orng:28:15:\n    t.a.>a() + t.b.>b()\n             ^");
    return _107_$retval;
}

int64_t _100_a(void* _100_$self_ptr){
    int64_t _100_$retval;
    _100_$retval = *(int64_t*)_100_$self_ptr;
    return _100_$retval;
}

int64_t _103_b(void* _103_$self_ptr){
    int64_t _104_self;
    int64_t _103_t1;
    int64_t _103_$retval;
    _104_self = *(int64_t*)_103_$self_ptr;
    _103_t1 = 2;
    _103_$retval = $mult_int64_t(_104_self, _103_t1, "tests/integration/traits/multiple-traits.orng:16:39:\n    virtual fn b(self) -> Int { self * 2 }\n                                     ^");
    return _103_$retval;
}


int main(void) {
  printf("%ld",_105_main());
  return 0;
}
