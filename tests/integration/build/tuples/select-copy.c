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
    int64_t _1;
};

/* Function forward definitions */
int64_t _1611_main(void);


/* Function definitions */
int64_t _1611_main(void){
    int64_t _1611_t1;
    int64_t _1611_t2;
    struct struct0 _1612_x;
    int64_t _1611_$retval;
    _1611_t1 = 50;
    _1611_t2 = 5;
    _1612_x = (struct struct0) {_1611_t1, _1611_t2};
    _1612_x._1 = 6;
    _1611_$retval = $add_int64_t(_1612_x._0, _1612_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1611_$retval;
}


int main(void) {
  printf("%ld",_1611_main());
  return 0;
}
