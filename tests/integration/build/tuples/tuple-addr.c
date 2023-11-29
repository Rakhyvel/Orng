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
int64_t _1240_main(void);

/* Function definitions */
int64_t _1240_main(void) {
    int64_t _1241_x;
    int64_t _1241_y;
    int64_t* _1240_t3;
    int64_t* _1240_t4;
    struct0 _1241_z;
    int64_t _1240_$retval;
    _1241_x = 30;
    _1241_y = 29;
    _1240_t3 = &_1241_x;
    _1240_t4 = &_1241_y;
    _1241_z = (struct0) {_1240_t3, _1240_t4};
    _1240_$retval = $add_int64_t(*_1241_z._0, *_1241_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1240_$retval;
}

int main(void) {
  printf("%ld",_1240_main());
  return 0;
}
