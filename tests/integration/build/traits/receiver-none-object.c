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
int64_t _1751_main(void);
int64_t _1749_d(int64_t _1749_x, int64_t _1749_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1748_$vtable = {
    .d = _1749_d,
};


/* Function definitions */
int64_t _1751_main(void){
    int64_t _1751_t1;
    int64_t _1751_t2;
    struct struct1 _1752_my_val;
    struct dyn2 _1751_t4;
    struct dyn2 _1752_my_dyn;
    int64_t _1751_t8;
    int64_t _1751_t9;
    int64_t _1751_t7;
    int64_t _1751_$retval;
    _1751_t1 = 100;
    _1751_t2 = 45;
    _1752_my_val = (struct struct1) {_1751_t1, _1751_t2};
    _1751_t4 = (struct dyn2) {&_1752_my_val, &_1748_$vtable};
    _1752_my_dyn = _1751_t4;
    _1751_t8 = 200;
    _1751_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _1751_t7 = _1752_my_dyn.vtable->d(_1751_t8, _1751_t9);
    $line_idx--;
    _1751_$retval = _1751_t7;
    return _1751_$retval;
}

int64_t _1749_d(int64_t _1749_x, int64_t _1749_y){
    int64_t _1749_$retval;
    _1749_$retval = $add_int64_t(_1749_x, _1749_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _1749_$retval;
}


int main(void) {
  printf("%ld",_1751_main());
  return 0;
}
