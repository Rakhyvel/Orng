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
int64_t _1232_main(void);

/* Function definitions */
int64_t _1232_main(void) {
    int64_t _1232_t1;
    int64_t _1232_t2;
    struct0 _1233_x;
    int64_t _1232_$retval;
    _1232_t1 = 50;
    _1232_t2 = 5;
    _1233_x = (struct0) {_1232_t1, _1232_t2};
    _1232_$retval = $add_int64_t(_1233_x._0, _1233_x._1, "tests/integration/tuples/select.orng:4:10:\n    x.a + x.b\n        ^");
    return _1232_$retval;
}

int main(void) {
  printf("%ld",_1232_main());
  return 0;
}
