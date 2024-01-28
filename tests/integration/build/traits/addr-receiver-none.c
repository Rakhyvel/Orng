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
int64_t _1555_main(void);
int64_t _1553_d(int64_t _1553_x, int64_t _1553_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1551_$vtable = {
    .d = _1553_d,
};


/* Function definitions */
int64_t _1555_main(void){
    int64_t _1555_t7;
    int64_t _1555_t8;
    int64_t _1555_t5;
    int64_t _1555_$retval;
    _1555_t7 = 200;
    _1555_t8 = 95;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _1555_t5 = _1551_$vtable.d(_1555_t7, _1555_t8);
    $line_idx--;
    _1555_$retval = _1555_t5;
    return _1555_$retval;
}

int64_t _1553_d(int64_t _1553_x, int64_t _1553_y){
    int64_t _1553_$retval;
    _1553_$retval = $add_int64_t(_1553_x, _1553_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1553_$retval;
}


int main(void) {
  printf("%ld",_1555_main());
  return 0;
}
