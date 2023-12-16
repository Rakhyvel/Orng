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
int64_t _1534_main(void);

/* Function definitions */
int64_t _1534_main(void) {
    int64_t _1535_x;
    int64_t _1535_y;
    int64_t* _1534_t3;
    int64_t* _1534_t4;
    struct0 _1535_z;
    int64_t _1534_$retval;
    _1535_x = 30;
    _1535_y = 29;
    _1534_t3 = &_1535_x;
    _1534_t4 = &_1535_y;
    _1535_z = (struct0) {_1534_t3, _1534_t4};
    _1534_$retval = $add_int64_t(*_1535_z._0, *_1535_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1534_$retval;
}

int main(void) {
  printf("%ld",_1534_main());
  return 0;
}
