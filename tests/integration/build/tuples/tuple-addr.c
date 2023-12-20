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
int64_t _1516_main(void);

/* Function definitions */
int64_t _1516_main(void){
    int64_t _1517_x;
    int64_t _1517_y;
    int64_t* _1516_t3;
    int64_t* _1516_t4;
    struct0 _1517_z;
    int64_t _1516_$retval;
    _1517_x = 30;
    _1517_y = 29;
    _1516_t3 = &_1517_x;
    _1516_t4 = &_1517_y;
    _1517_z = (struct0) {_1516_t3, _1516_t4};
    _1516_$retval = $add_int64_t(*_1517_z._0, *_1517_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1516_$retval;
}

int main(void) {
  printf("%ld",_1516_main());
  return 0;
}
