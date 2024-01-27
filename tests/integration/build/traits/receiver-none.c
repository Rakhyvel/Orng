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
int64_t _81_main(void);
int64_t _79_d(int64_t _79_x, int64_t _79_y);

/* Trait vtable implementations */
struct vtable_My_Trait _78_$vtable = {
    .d = _79_d,
};


/* Function definitions */
int64_t _81_main(void){
    int64_t _81_t6;
    int64_t _81_t7;
    int64_t _81_t4;
    int64_t _81_$retval;
    _81_t6 = 200;
    _81_t7 = 91;
    $lines[$line_idx++] = "tests/integration/traits/receiver-none.orng:17:13:\n    my_val.>d(200, 91)\n           ^";
    _81_t4 = _78_$vtable.d(_81_t6, _81_t7);
    $line_idx--;
    _81_$retval = _81_t4;
    return _81_$retval;
}

int64_t _79_d(int64_t _79_x, int64_t _79_y){
    int64_t _79_$retval;
    _79_$retval = $add_int64_t(_79_x, _79_y, "tests/integration/traits/receiver-none.orng:10:12:\n        x + y\n          ^");
    return _79_$retval;
}


int main(void) {
  printf("%ld",_81_main());
  return 0;
}
