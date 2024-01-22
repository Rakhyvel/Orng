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
int64_t _56_main(void);
int64_t _54_d(int64_t _54_x, int64_t _54_y);

/* Trait vtable implementations */
struct vtable_My_Trait _53_$vtable = {
    .d = _54_d,
};


/* Function definitions */
int64_t _56_main(void){
    int64_t _56_t6;
    int64_t _56_t7;
    int64_t _56_t4;
    int64_t _56_$retval;
    _56_t6 = 200;
    _56_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _56_t4 = _53_$vtable.d(_56_t6, _56_t7);
    $line_idx--;
    _56_$retval = _56_t4;
    return _56_$retval;
}

int64_t _54_d(int64_t _54_x, int64_t _54_y){
    int64_t _54_$retval;
    _54_$retval = $add_int64_t(_54_x, _54_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _54_$retval;
}


int main(void) {
  printf("%ld",_56_main());
  return 0;
}
