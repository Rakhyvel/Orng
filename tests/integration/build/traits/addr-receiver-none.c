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
int64_t _1552_main(void);
int64_t _1550_d(int64_t _1550_x, int64_t _1550_y);

/* Trait vtable implementations */
struct vtable_My_Trait _1549_$vtable = {
    .d = _1550_d,
};


/* Function definitions */
int64_t _1552_main(void){
    int64_t _1552_t7;
    int64_t _1552_t8;
    int64_t _1552_t5;
    int64_t _1552_$retval;
    _1552_t7 = 200;
    _1552_t8 = 95;
    $lines[$line_idx++] = "tests/integration/traits/addr-receiver-none.orng:18:17:\n    my_val_ptr.>d(200, 95)\n               ^";
    _1552_t5 = _1549_$vtable.d(_1552_t7, _1552_t8);
    $line_idx--;
    _1552_$retval = _1552_t5;
    return _1552_$retval;
}

int64_t _1550_d(int64_t _1550_x, int64_t _1550_y){
    int64_t _1550_$retval;
    _1550_$retval = $add_int64_t(_1550_x, _1550_y, "tests/integration/traits/addr-receiver-none.orng:10:12:\n        x + y\n          ^");
    return _1550_$retval;
}


int main(void) {
  printf("%ld",_1552_main());
  return 0;
}
