/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct dyn1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct dyn1 {
    void* data_ptr;
    struct vtable_My_Trait* vtable;
};

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*d)(int64_t, int64_t);
};

/* Function forward definitions */
int64_t _74_main(void);
int64_t _72_d(int64_t _72_x, int64_t _72_y);

/* Trait vtable implementations */
struct vtable_My_Trait _71_$vtable = {
    .d = _72_d,
};


/* Function definitions */
int64_t _74_main(void){
    int64_t _74_t1;
    int64_t _74_t2;
    struct struct0 _75_my_val;
    struct dyn1 _74_t3;
    struct dyn1 _75_my_dyn;
    int64_t _74_t6;
    int64_t _74_t7;
    int64_t _74_t5;
    int64_t _74_$retval;
    _74_t1 = 100;
    _74_t2 = 45;
    _75_my_val = (struct struct0) {_74_t1, _74_t2};
    _74_t3 = (struct dyn1) {&_75_my_val, &_71_$vtable};
    _75_my_dyn = _74_t3;
    _74_t6 = 200;
    _74_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _74_t5 = _75_my_dyn.vtable->d(_74_t6, _74_t7);
    $line_idx--;
    _74_$retval = _74_t5;
    return _74_$retval;
}

int64_t _72_d(int64_t _72_x, int64_t _72_y){
    int64_t _72_$retval;
    _72_$retval = $add_int64_t(_72_x, _72_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _72_$retval;
}


int main(void) {
  printf("%ld",_74_main());
  return 0;
}
