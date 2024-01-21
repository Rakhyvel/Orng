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
int64_t _1534_main(void);

/* Function definitions */
int64_t _1534_main(void){
    int64_t _1534_t1;
    int64_t _1534_t2;
    struct struct0 _1535_x;
    int64_t _1534_$retval;
    _1534_t1 = 50;
    _1534_t2 = 7;
    _1535_x = (struct struct0) {_1534_t1, _1534_t2};
    _1534_$retval = $add_int64_t(_1535_x._0, _1535_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1534_$retval;
}

int main(void) {
  printf("%ld",_1534_main());
  return 0;
}
