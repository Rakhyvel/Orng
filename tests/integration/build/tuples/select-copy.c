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
int64_t _1073_main(void);

/* Function definitions */
int64_t _1073_main(void) {
    int64_t _1073_t1;
    int64_t _1073_t2;
    struct0 _1074_x;
    int64_t _1073_$retval;
    _1073_t1 = 50;
    _1073_t2 = 5;
    _1074_x = (struct0) {_1073_t1, _1073_t2};
    _1074_x._1 = 6;
    _1073_$retval = $add_int64_t(_1074_x._0, _1074_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1073_$retval;
}

int main(void) {
  printf("%ld",_1073_main());
  return 0;
}
