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
int64_t _168_main(void);
int64_t _166_d(int64_t _166_x, int64_t _166_y);

/* Trait vtable implementations */
struct vtable_My_Trait _165_$vtable = {
    .d = _166_d,
};


/* Function definitions */
int64_t _168_main(void){
    int64_t _168_t1;
    int64_t _168_t2;
    struct struct1 _169_my_val;
    struct dyn2 _168_t4;
    struct dyn2 _169_my_dyn;
    int64_t _168_t8;
    int64_t _168_t9;
    int64_t _168_t7;
    int64_t _168_$retval;
    _168_t1 = 100;
    _168_t2 = 45;
    _169_my_val = (struct struct1) {_168_t1, _168_t2};
    _168_t4 = (struct dyn2) {&_169_my_val, &_165_$vtable};
    _169_my_dyn = _168_t4;
    _168_t8 = 200;
    _168_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _168_t7 = _169_my_dyn.vtable->d(_168_t8, _168_t9);
    $line_idx--;
    _168_$retval = _168_t7;
    return _168_$retval;
}

int64_t _166_d(int64_t _166_x, int64_t _166_y){
    int64_t _166_$retval;
    _166_$retval = $add_int64_t(_166_x, _166_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _166_$retval;
}


int main(void) {
  printf("%ld",_168_main());
  return 0;
}
