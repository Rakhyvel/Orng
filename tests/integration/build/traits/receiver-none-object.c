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
int64_t _128_main(void);
int64_t _126_d(int64_t _126_x, int64_t _126_y);

/* Trait vtable implementations */
struct vtable_My_Trait _125_$vtable = {
    .d = _126_d,
};


/* Function definitions */
int64_t _128_main(void){
    int64_t _128_t1;
    int64_t _128_t2;
    struct struct1 _129_my_val;
    struct dyn2 _128_t4;
    struct dyn2 _129_my_dyn;
    int64_t _128_t8;
    int64_t _128_t9;
    int64_t _128_t7;
    int64_t _128_$retval;
    _128_t1 = 100;
    _128_t2 = 45;
    _129_my_val = (struct struct1) {_128_t1, _128_t2};
    _128_t4 = (struct dyn2) {&_129_my_val, &_125_$vtable};
    _129_my_dyn = _128_t4;
    _128_t8 = 200;
    _128_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _128_t7 = _129_my_dyn.vtable->d(_128_t8, _128_t9);
    $line_idx--;
    _128_$retval = _128_t7;
    return _128_$retval;
}

int64_t _126_d(int64_t _126_x, int64_t _126_y){
    int64_t _126_$retval;
    _126_$retval = $add_int64_t(_126_x, _126_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _126_$retval;
}


int main(void) {
  printf("%ld",_128_main());
  return 0;
}
