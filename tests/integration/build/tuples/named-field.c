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
int64_t _1525_main(void);

/* Function definitions */
int64_t _1525_main(void) {
    int64_t _1525_t1;
    int64_t _1525_t2;
    struct0 _1526_x;
    int64_t _1525_$retval;
    _1525_t1 = 20;
    _1525_t2 = 3;
    _1526_x = (struct0) {_1525_t1, _1525_t2};
    _1525_$retval = $mult_int64_t(_1526_x._0, _1526_x._1, "tests/integration/tuples/named-field.orng:4:10:\n    x.a * x.b\n        ^");
    return _1525_$retval;
}

int main(void) {
  printf("%ld",_1525_main());
  return 0;
}
