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
int64_t _1875_main(void);


/* Function definitions */
int64_t _1875_main(void){
    int64_t _1875_t1;
    int64_t _1875_t2;
    struct struct0 _1876_x;
    int64_t _1875_$retval;
    _1875_t1 = 50;
    _1875_t2 = 7;
    _1876_x = (struct struct0) {_1875_t1, _1875_t2};
    _1875_$retval = $add_int64_t(_1876_x._0, _1876_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1875_$retval;
}


int main(void) {
  printf("%ld",_1875_main());
  return 0;
}
