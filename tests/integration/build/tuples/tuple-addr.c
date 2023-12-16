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
int64_t _1613_main(void);

/* Function definitions */
int64_t _1613_main(void){
    int64_t _1614_x;
    int64_t _1614_y;
    int64_t* _1613_t3;
    int64_t* _1613_t4;
    struct0 _1614_z;
    int64_t _1613_$retval;
    _1614_x = 30;
    _1614_y = 29;
    _1613_t3 = &_1614_x;
    _1613_t4 = &_1614_y;
    _1614_z = (struct0) {_1613_t3, _1613_t4};
    _1613_$retval = $add_int64_t(*_1614_z._0, *_1614_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1613_$retval;
}

int main(void) {
  printf("%ld",_1613_main());
  return 0;
}
