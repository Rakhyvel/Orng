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
int64_t _45_main(void);

/* Function definitions */
int64_t _45_main(void) {
    int64_t _45_t1;
    int64_t _45_t2;
    struct0 _46_x;
    int64_t _45_$retval;
    _45_t1 = 50;
    _45_t2 = 5;
    _46_x = (struct0) {_45_t1, _45_t2};
    _45_$retval = $add_int64_t(_46_x._0, _46_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _45_$retval;
}

int main(void) {
  printf("%ld",_45_main());
  return 0;
}
