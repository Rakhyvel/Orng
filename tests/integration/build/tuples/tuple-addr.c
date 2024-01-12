/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t* _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1564_main(void);

/* Function definitions */
int64_t _1564_main(void){
    int64_t _1565_x;
    int64_t _1565_y;
    int64_t* _1564_t3;
    int64_t* _1564_t4;
    struct struct0 _1565_z;
    int64_t _1564_$retval;
    _1565_x = 30;
    _1565_y = 29;
    _1564_t3 = &_1565_x;
    _1564_t4 = &_1565_y;
    _1565_z = (struct struct0) {_1564_t3, _1564_t4};
    _1564_$retval = $add_int64_t(*_1565_z._0, *_1565_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1564_$retval;
}

int main(void) {
  printf("%ld",_1564_main());
  return 0;
}
