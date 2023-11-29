/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
} struct0;

/* Function forward definitions */
int64_t _1596_main(void);

/* Function definitions */
int64_t _1596_main(void) {
    int64_t _1597_x;
    int64_t _1597_y;
    int64_t* _1596_t3;
    int64_t* _1596_t4;
    struct0 _1597_z;
    int64_t _1596_$retval;
    _1597_x = 30;
    _1597_y = 29;
    _1596_t3 = &_1597_x;
    _1596_t4 = &_1597_y;
    _1597_z = (struct0) {_1596_t3, _1596_t4};
    _1596_$retval = $add_int64_t(*_1597_z._0, *_1597_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1596_$retval;
}

int main(void) {
  printf("%ld",_1596_main());
  return 0;
}
