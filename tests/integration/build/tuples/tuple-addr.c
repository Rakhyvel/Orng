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
int64_t _121_main(void);

/* Function definitions */
int64_t _121_main(void) {
    int64_t _122_x;
    int64_t _122_y;
    int64_t* _121_t3;
    int64_t* _121_t4;
    struct0 _122_z;
    int64_t _121_$retval;
    _122_x = 30;
    _122_y = 29;
    _121_t3 = &_122_x;
    _121_t4 = &_122_y;
    _122_z = (struct0) {_121_t3, _121_t4};
    _121_$retval = $add_int64_t(*_122_z._0, *_122_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _121_$retval;
}

int main(void) {
  printf("%ld",_121_main());
  return 0;
}
