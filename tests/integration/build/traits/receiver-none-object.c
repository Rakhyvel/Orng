/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct dyn2;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

struct dyn2 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*d)(int64_t, int64_t);
};

/* Function forward definitions */
int64_t _1732_main(void);
int64_t _1730_d(int64_t _1730_x, int64_t _1730_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1729_$vtable = {
    .d = _1730_d,
};


/* Function definitions */
int64_t _1732_main(void){
    int64_t _1732_t1;
    int64_t _1732_t2;
    struct struct1 _1733_my_val;
    struct dyn2 _1732_t4;
    struct dyn2 _1733_my_dyn;
    int64_t _1732_t8;
    int64_t _1732_t9;
    int64_t _1732_t7;
    int64_t _1732_$retval;
    _1732_t1 = 100;
    _1732_t2 = 45;
    _1733_my_val = (struct struct1) {_1732_t1, _1732_t2};
    _1732_t4 = (struct dyn2) {&_1733_my_val, &_1729_$vtable};
    _1733_my_dyn = _1732_t4;
    _1732_t8 = 200;
    _1732_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _1732_t7 = _1733_my_dyn.vtable->d(_1732_t8, _1732_t9);
    $line_idx--;
    _1732_$retval = _1732_t7;
    return _1732_$retval;
}

int64_t _1730_d(int64_t _1730_x, int64_t _1730_y){
    int64_t _1730_$retval;
    _1730_$retval = $add_int64_t(_1730_x, _1730_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _1730_$retval;
}


int main(void) {
  printf("%ld",_1732_main());
  return 0;
}
