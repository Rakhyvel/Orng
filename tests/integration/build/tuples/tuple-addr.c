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
int64_t _1553_main(void);

/* Function definitions */
int64_t _1553_main(void){
    int64_t _1554_x;
    int64_t _1554_y;
    int64_t* _1553_t3;
    int64_t* _1553_t4;
    struct0 _1554_z;
    int64_t _1553_$retval;
    _1554_x = 30;
    _1554_y = 29;
    _1553_t3 = &_1554_x;
    _1553_t4 = &_1554_y;
    _1554_z = (struct0) {_1553_t3, _1553_t4};
    _1553_$retval = $add_int64_t(*_1554_z._0, *_1554_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1553_$retval;
}

int main(void) {
  printf("%ld",_1553_main());
  return 0;
}
