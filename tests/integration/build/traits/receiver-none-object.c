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
int64_t _1786_main(void);
int64_t _1784_d(int64_t _1784_x, int64_t _1784_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1783_$vtable = {
    .d = _1784_d,
};


/* Function definitions */
int64_t _1786_main(void){
    int64_t _1786_t1;
    int64_t _1786_t2;
    struct struct1 _1787_my_val;
    struct dyn2 _1786_t4;
    struct dyn2 _1787_my_dyn;
    int64_t _1786_t8;
    int64_t _1786_t9;
    int64_t _1786_t7;
    int64_t _1786_$retval;
    _1786_t1 = 100;
    _1786_t2 = 45;
    _1787_my_val = (struct struct1) {_1786_t1, _1786_t2};
    _1786_t4 = (struct dyn2) {&_1787_my_val, &_1783_$vtable};
    _1787_my_dyn = _1786_t4;
    _1786_t8 = 200;
    _1786_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _1786_t7 = _1787_my_dyn.vtable->d(_1786_t8, _1786_t9);
    $line_idx--;
    _1786_$retval = _1786_t7;
    return _1786_$retval;
}

int64_t _1784_d(int64_t _1784_x, int64_t _1784_y){
    int64_t _1784_$retval;
    _1784_$retval = $add_int64_t(_1784_x, _1784_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _1784_$retval;
}


int main(void) {
  printf("%ld",_1786_main());
  return 0;
}
