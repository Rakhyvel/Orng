/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Trait vtable type definitions */
struct vtable_My_Trait {
    int64_t(*d)(int64_t, int64_t);
};

/* Function forward definitions */
int64_t _22_main(void);
int64_t _20_d(int64_t _20_x, int64_t _20_y);

/* Trait vtable implementations */
struct vtable_My_Trait _19_$vtable = {
    .d = _20_d,
};


/* Function definitions */
int64_t _22_main(void){
    int64_t _22_t7;
    int64_t _22_t8;
    int64_t _22_t5;
    int64_t _22_$retval;
    _22_t7 = 200;
    _22_t8 = 95;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _22_t5 = _19_$vtable.d(_22_t7, _22_t8);
    $line_idx--;
    _22_$retval = _22_t5;
    return _22_$retval;
}

int64_t _20_d(int64_t _20_x, int64_t _20_y){
    int64_t _20_$retval;
    _20_$retval = $add_int64_t(_20_x, _20_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _20_$retval;
}


int main(void) {
  printf("%ld",_22_main());
  return 0;
}
