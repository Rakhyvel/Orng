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
int64_t _1766_main(void);
int64_t _1764_d(int64_t _1764_x, int64_t _1764_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1763_$vtable = {
    .d = _1764_d,
};


/* Function definitions */
int64_t _1766_main(void){
    int64_t _1766_t1;
    int64_t _1766_t2;
    struct struct1 _1767_my_val;
    struct dyn2 _1766_t4;
    struct dyn2 _1767_my_dyn;
    int64_t _1766_t8;
    int64_t _1766_t9;
    int64_t _1766_t7;
    int64_t _1766_$retval;
    _1766_t1 = 100;
    _1766_t2 = 45;
    _1767_my_val = (struct struct1) {_1766_t1, _1766_t2};
    _1766_t4 = (struct dyn2) {&_1767_my_val, &_1763_$vtable};
    _1767_my_dyn = _1766_t4;
    _1766_t8 = 200;
    _1766_t9 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none-object.orng:18:13:\n    my_dyn.>d(200, 91)\n           ^";
    _1766_t7 = _1767_my_dyn.vtable->d(_1766_t8, _1766_t9);
    $line_idx--;
    _1766_$retval = _1766_t7;
    return _1766_$retval;
}

int64_t _1764_d(int64_t _1764_x, int64_t _1764_y){
    int64_t _1764_$retval;
    _1764_$retval = $add_int64_t(_1764_x, _1764_y, "tests/integration/traits/receiver-none-object.orng:10:12:\n        x + y\n          ^");
    return _1764_$retval;
}


int main(void) {
  printf("%ld",_1766_main());
  return 0;
}
