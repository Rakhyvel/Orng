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
int64_t _1048_main(void);

/* Function definitions */
int64_t _1048_main(void) {
    int64_t _1048_t1;
    int64_t _1048_t2;
    struct0 _1049_x;
    int64_t _1048_$retval;
    _1048_t1 = 50;
    _1048_t2 = 7;
    _1049_x = (struct0) {_1048_t1, _1048_t2};
    _1048_$retval = $add_int64_t(_1049_x._0, _1049_x._1, "tests/integration/tuples/default-fields.orng:4:10:\n    x.a + x.b\n        ^");
    return _1048_$retval;
}

int main(void) {
  printf("%ld",_1048_main());
  return 0;
}
