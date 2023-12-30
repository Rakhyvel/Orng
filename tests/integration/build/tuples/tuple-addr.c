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
int64_t _1541_main(void);

/* Function definitions */
int64_t _1541_main(void){
    int64_t _1542_x;
    int64_t _1542_y;
    int64_t* _1541_t3;
    int64_t* _1541_t4;
    struct0 _1542_z;
    int64_t _1541_$retval;
    _1542_x = 30;
    _1542_y = 29;
    _1541_t3 = &_1542_x;
    _1541_t4 = &_1542_y;
    _1542_z = (struct0) {_1541_t3, _1541_t4};
    _1541_$retval = $add_int64_t(*_1542_z._0, *_1542_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1541_$retval;
}

int main(void) {
  printf("%ld",_1541_main());
  return 0;
}
