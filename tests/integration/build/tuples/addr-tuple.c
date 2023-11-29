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
int64_t _10_main(void);

/* Function definitions */
int64_t _10_main(void) {
    int64_t _10_t1;
    int64_t _10_t4;
    struct0 _11_x;
    struct0* _11_y;
    int64_t _10_$retval;
    _10_t1 = 19;
    _10_t4 = 39;
    _11_x = (struct0) {_10_t1, _10_t4};
    _11_y = &_11_x;
    _10_$retval = $add_int64_t((*_11_y)._0, (*_11_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _10_$retval;
}

int main(void) {
  printf("%ld",_10_main());
  return 0;
}
