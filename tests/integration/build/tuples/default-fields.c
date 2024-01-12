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
int64_t _1516_main(void);

/* Function definitions */
int64_t _1516_main(void){
    int64_t _1516_t1;
    int64_t _1516_t2;
    struct struct0 _1517_x;
    int64_t _1516_$retval;
    _1516_t1 = 50;
    _1516_t2 = 7;
    _1517_x = (struct struct0) {_1516_t1, _1516_t2};
    _1516_$retval = $add_int64_t(_1517_x._0, _1517_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1516_$retval;
}

int main(void) {
  printf("%ld",_1516_main());
  return 0;
}
