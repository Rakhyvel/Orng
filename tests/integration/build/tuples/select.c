/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1556_main(void);

/* Function definitions */
int64_t _1556_main(void){
    int64_t _1556_t1;
    int64_t _1556_t2;
    struct struct0 _1557_x;
    int64_t _1556_$retval;
    _1556_t1 = 50;
    _1556_t2 = 5;
    _1557_x = (struct struct0) {_1556_t1, _1556_t2};
    _1556_$retval = $add_int64_t(_1557_x._0, _1557_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1556_$retval;
}

int main(void) {
  printf("%ld",_1556_main());
  return 0;
}
