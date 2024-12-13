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
int64_t _11_main(void);


/* Function definitions */
int64_t _11_main(void){
    int64_t _11_t1;
    struct struct0 _12_x;
    int64_t _11_t3;
    int64_t _11_t4;
    int64_t _11_$retval;
    _11_t1 = 120;
    _12_x = (struct struct0) {_11_t1};
    _11_t3 = 0;
    _11_t4 = 1;
    $bounds_check(_11_t3, _11_t4, "tests/integration/arrays/1-array.orng:2:8:\nfn main() -> Int {\n      ^");
    _11_$retval = *((int64_t*)&_12_x + _11_t3);
    return _11_$retval;
}


int main(void) {
  printf("%ld",_11_main());
  return 0;
}
