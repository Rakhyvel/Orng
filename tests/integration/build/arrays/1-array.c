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
int64_t _7_main(void);


/* Function definitions */
int64_t _7_main(void){
    int64_t _7_t1;
    struct struct0 _8_x;
    int64_t _7_t3;
    int64_t _7_t4;
    int64_t _7_$retval;
    _7_t1 = 120;
    _8_x = (struct struct0) {_7_t1};
    _7_t3 = 0;
    _7_t4 = 1;
    $bounds_check(_7_t3, _7_t4, "tests/integration/arrays/1-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _7_$retval = *((int64_t*)&_8_x + _7_t3);
    return _7_$retval;
}


int main(void) {
  printf("%ld",_7_main());
  return 0;
}
