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
int64_t _92_main(void);
int64_t _90_d(int64_t _90_x, int64_t _90_y);

/* Trait vtable implementations */
struct vtable_My_Trait _89_$vtable = {
    .d = _90_d,
};


/* Function definitions */
int64_t _92_main(void){
    int64_t _92_t1;
    int64_t _92_t2;
    struct struct1 _93_my_val;
    struct dyn2 _92_t3;
    struct dyn2 _93_my_dyn;
    int64_t _92_t6;
    int64_t _92_t7;
    int64_t _92_t5;
    int64_t _92_$retval;
    _92_t1 = 100;
    _92_t2 = 45;
    _93_my_val = (struct struct1) {_92_t1, _92_t2};
    _92_t3 = (struct dyn2) {&_93_my_val, &_89_$vtable};
    _93_my_dyn = _92_t3;
    _92_t6 = 200;
    _92_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _92_t5 = _93_my_dyn.vtable->d(_92_t6, _92_t7);
    $line_idx--;
    _92_$retval = _92_t5;
    return _92_$retval;
}

int64_t _90_d(int64_t _90_x, int64_t _90_y){
    int64_t _90_$retval;
    _90_$retval = $add_int64_t(_90_x, _90_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _90_$retval;
}


int main(void) {
  printf("%ld",_92_main());
  return 0;
}
