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
int64_t _9_main(void);


/* Function definitions */
int64_t _9_main(void){
    int64_t _9_t1;
    struct struct0 _10_x;
    int64_t _9_t3;
    int64_t _9_t4;
    int64_t _9_$retval;
    _9_t1 = 120;
    _10_x = (struct struct0) {_9_t1};
    _9_t3 = 0;
    _9_t4 = 1;
    $bounds_check(_9_t3, _9_t4, "tests/integration/arrays/1-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _9_$retval = *((int64_t*)&_10_x + _9_t3);
    return _9_$retval;
}


int main(void) {
  printf("%ld",_9_main());
  return 0;
}
