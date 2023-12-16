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
int64_t _1542_main(void);

/* Function definitions */
int64_t _1542_main(void){
    int64_t _1543_x;
    int64_t _1543_y;
    int64_t* _1542_t3;
    int64_t* _1542_t4;
    struct0 _1543_z;
    int64_t _1542_$retval;
    _1543_x = 30;
    _1543_y = 29;
    _1542_t3 = &_1543_x;
    _1542_t4 = &_1543_y;
    _1543_z = (struct0) {_1542_t3, _1542_t4};
    _1542_$retval = $add_int64_t(*_1543_z._0, *_1543_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1542_$retval;
}

int main(void) {
  printf("%ld",_1542_main());
  return 0;
}
