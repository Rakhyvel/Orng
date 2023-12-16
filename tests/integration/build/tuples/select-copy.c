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
int64_t _1510_main(void);

/* Function definitions */
int64_t _1510_main(void) {
    int64_t _1510_t1;
    int64_t _1510_t2;
    struct0 _1511_x;
    int64_t _1510_$retval;
    _1510_t1 = 50;
    _1510_t2 = 5;
    _1511_x = (struct0) {_1510_t1, _1510_t2};
    _1511_x._1 = 6;
    _1510_$retval = $add_int64_t(_1511_x._0, _1511_x._1, "tests/integration/tuples/select-copy.orng:5:10:\n    x.a + x.b\n        ^");
    return _1510_$retval;
}

int main(void) {
  printf("%ld",_1510_main());
  return 0;
}
