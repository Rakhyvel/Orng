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
int64_t _48_main(void);

/* Function definitions */
int64_t _48_main(void) {
    int64_t _48_t1;
    int64_t _48_t2;
    struct0 _49_x;
    int64_t _48_$retval;
    _48_t1 = 50;
    _48_t2 = 5;
    _49_x = (struct0) {_48_t1, _48_t2};
    _48_$retval = $add_int64_t(_49_x._0, _49_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _48_$retval;
}

int main(void) {
  printf("%ld",_48_main());
  return 0;
}
