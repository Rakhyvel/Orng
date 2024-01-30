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
int64_t _83_main(void);
int64_t _81_d(int64_t _81_x, int64_t _81_y);

/* Trait vtable implementations */
struct vtable_My_Trait _80_$vtable = {
    .d = _81_d,
};


/* Function definitions */
int64_t _83_main(void){
    int64_t _83_t1;
    int64_t _83_t2;
    struct struct1 _84_my_val;
    struct dyn2 _83_t3;
    struct dyn2 _84_my_dyn;
    int64_t _83_t6;
    int64_t _83_t7;
    int64_t _83_t5;
    int64_t _83_$retval;
    _83_t1 = 100;
    _83_t2 = 45;
    _84_my_val = (struct struct1) {_83_t1, _83_t2};
    _83_t3 = (struct dyn2) {&_84_my_val, &_80_$vtable};
    _84_my_dyn = _83_t3;
    _83_t6 = 200;
    _83_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _83_t5 = _84_my_dyn.vtable->d(_83_t6, _83_t7);
    $line_idx--;
    _83_$retval = _83_t5;
    return _83_$retval;
}

int64_t _81_d(int64_t _81_x, int64_t _81_y){
    int64_t _81_$retval;
    _81_$retval = $add_int64_t(_81_x, _81_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _81_$retval;
}


int main(void) {
  printf("%ld",_83_main());
  return 0;
}
