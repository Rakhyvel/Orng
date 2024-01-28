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
int64_t _1613_main(void);
int64_t _1611_d(int64_t _1611_x, int64_t _1611_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1609_$vtable = {
    .d = _1611_d,
};


/* Function definitions */
int64_t _1613_main(void){
    int64_t _1613_t1;
    int64_t _1613_t2;
    struct struct0 _1614_my_val;
    struct dyn1 _1613_t3;
    struct dyn1 _1614_my_dyn;
    int64_t _1613_t6;
    int64_t _1613_t7;
    int64_t _1613_t5;
    int64_t _1613_$retval;
    _1613_t1 = 100;
    _1613_t2 = 45;
    _1614_my_val = (struct struct0) {_1613_t1, _1613_t2};
    _1613_t3 = (struct dyn1) {&_1614_my_val, &_1609_$vtable};
    _1614_my_dyn = _1613_t3;
    _1613_t6 = 200;
    _1613_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _1613_t5 = _1614_my_dyn.vtable->d(_1613_t6, _1613_t7);
    $line_idx--;
    _1613_$retval = _1613_t5;
    return _1613_$retval;
}

int64_t _1611_d(int64_t _1611_x, int64_t _1611_y){
    int64_t _1611_$retval;
    _1611_$retval = $add_int64_t(_1611_x, _1611_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _1611_$retval;
}


int main(void) {
  printf("%ld",_1613_main());
  return 0;
}
