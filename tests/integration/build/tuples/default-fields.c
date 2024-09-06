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
int64_t _1845_main(void);


/* Function definitions */
int64_t _1845_main(void){
    int64_t _1845_t1;
    int64_t _1845_t2;
    struct struct0 _1846_x;
    int64_t _1845_$retval;
    _1845_t1 = 50;
    _1845_t2 = 7;
    _1846_x = (struct struct0) {_1845_t1, _1845_t2};
    _1845_$retval = $add_int64_t(_1846_x._0, _1846_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1845_$retval;
}


int main(void) {
  printf("%ld",_1845_main());
  return 0;
}
