/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1529_main(void);

/* Function definitions */
int64_t _1529_main(void){
    int64_t _1529_t1;
    int64_t _1529_t2;
    struct0 _1530_x;
    int64_t _1529_$retval;
    _1529_t1 = 50;
    _1529_t2 = 5;
    _1530_x = (struct0) {_1529_t1, _1529_t2};
    _1529_$retval = $add_int64_t(_1530_x._0, _1530_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1529_$retval;
}

int main(void) {
  printf("%ld",_1529_main());
  return 0;
}
