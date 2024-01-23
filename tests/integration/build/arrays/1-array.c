/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
};

/* Function forward definitions */
int64_t _2_main(void);


/* Function definitions */
int64_t _2_main(void){
    int64_t _2_t1;
    struct struct0 _3_x;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_$retval;
    _2_t1 = 120;
    _3_x = (struct struct0) {_2_t1};
    _2_t2 = 0;
    _2_t3 = 1;
    $bounds_check(_2_t2, _2_t3, "tests/integration/arrays/1-array.orng:2:3:\nfn main() -> Int {\n ^");
    _2_$retval = *((int64_t*)&_3_x + _2_t2);
    return _2_$retval;
}


int main(void) {
  printf("%ld",_2_main());
  return 0;
}
