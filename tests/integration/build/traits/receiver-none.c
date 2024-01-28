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
int64_t _1621_main(void);
int64_t _1619_d(int64_t _1619_x, int64_t _1619_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1617_$vtable = {
    .d = _1619_d,
};


/* Function definitions */
int64_t _1621_main(void){
    int64_t _1621_t6;
    int64_t _1621_t7;
    int64_t _1621_t4;
    int64_t _1621_$retval;
    _1621_t6 = 200;
    _1621_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _1621_t4 = _1617_$vtable.d(_1621_t6, _1621_t7);
    $line_idx--;
    _1621_$retval = _1621_t4;
    return _1621_$retval;
}

int64_t _1619_d(int64_t _1619_x, int64_t _1619_y){
    int64_t _1619_$retval;
    _1619_$retval = $add_int64_t(_1619_x, _1619_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1619_$retval;
}


int main(void) {
  printf("%ld",_1621_main());
  return 0;
}
