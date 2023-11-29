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
int64_t _1225_main(void);

/* Function definitions */
int64_t _1225_main(void) {
    int64_t _1225_t1;
    int64_t _1225_t2;
    struct0 _1226_x;
    int64_t _1225_$retval;
    _1225_t1 = 50;
    _1225_t2 = 5;
    _1226_x = (struct0) {_1225_t1, _1225_t2};
    _1226_x._1 = 6;
    _1225_$retval = $add_int64_t(_1226_x._0, _1226_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1225_$retval;
}

int main(void) {
  printf("%ld",_1225_main());
  return 0;
}
