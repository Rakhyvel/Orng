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
int64_t _1561_main(void);

/* Function definitions */
int64_t _1561_main(void) {
    int64_t _1561_t1;
    int64_t _1561_t2;
    struct0 _1562_x;
    int64_t _1561_$retval;
    _1561_t1 = 50;
    _1561_t2 = 5;
    _1562_x = (struct0) {_1561_t1, _1561_t2};
    _1561_$retval = $add_int64_t(_1562_x._0, _1562_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1561_$retval;
}

int main(void) {
  printf("%ld",_1561_main());
  return 0;
}
