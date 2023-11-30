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
int64_t _23_main(void);

/* Function definitions */
int64_t _23_main(void) {
    int64_t _23_t1;
    int64_t _23_t2;
    struct0 _24_x;
    int64_t _23_$retval;
    _23_t1 = 50;
    _23_t2 = 7;
    _24_x = (struct0) {_23_t1, _23_t2};
    _23_$retval = $add_int64_t(_24_x._0, _24_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _23_$retval;
}

int main(void) {
  printf("%ld",_23_main());
  return 0;
}
