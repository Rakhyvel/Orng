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
int64_t _1586_main(void);
int64_t _1584_d(int64_t _1584_x, int64_t _1584_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1583_$vtable = {
    .d = _1584_d,
};


/* Function definitions */
int64_t _1586_main(void){
    int64_t _1586_t6;
    int64_t _1586_t7;
    int64_t _1586_t4;
    int64_t _1586_$retval;
    _1586_t6 = 200;
    _1586_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _1586_t4 = _1583_$vtable.d(_1586_t6, _1586_t7);
    $line_idx--;
    _1586_$retval = _1586_t4;
    return _1586_$retval;
}

int64_t _1584_d(int64_t _1584_x, int64_t _1584_y){
    int64_t _1584_$retval;
    _1584_$retval = $add_int64_t(_1584_x, _1584_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1584_$retval;
}


int main(void) {
  printf("%ld",_1586_main());
  return 0;
}
