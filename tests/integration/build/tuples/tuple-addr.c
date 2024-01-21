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
int64_t _1582_main(void);

/* Function definitions */
int64_t _1582_main(void){
    int64_t _1583_x;
    int64_t _1583_y;
    int64_t* _1582_t3;
    int64_t* _1582_t4;
    struct struct0 _1583_z;
    int64_t _1582_$retval;
    _1583_x = 30;
    _1583_y = 29;
    _1582_t3 = &_1583_x;
    _1582_t4 = &_1583_y;
    _1583_z = (struct struct0) {_1582_t3, _1582_t4};
    _1582_$retval = $add_int64_t(*_1583_z._0, *_1583_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1582_$retval;
}

int main(void) {
  printf("%ld",_1582_main());
  return 0;
}
