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
int64_t _26_main(void);
int64_t _24_d(int64_t _24_x, int64_t _24_y);

/* Trait vtable implementations */
struct vtable_My_Trait _23_$vtable = {
    .d = _24_d,
};


/* Function definitions */
int64_t _26_main(void){
    int64_t _26_t6;
    int64_t _26_t7;
    int64_t _26_t4;
    int64_t _26_$retval;
    _26_t6 = 200;
    _26_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _26_t4 = _23_$vtable.d(_26_t6, _26_t7);
    $line_idx--;
    _26_$retval = _26_t4;
    return _26_$retval;
}

int64_t _24_d(int64_t _24_x, int64_t _24_y){
    int64_t _24_$retval;
    _24_$retval = $add_int64_t(_24_x, _24_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _24_$retval;
}


int main(void) {
  printf("%ld",_26_main());
  return 0;
}
