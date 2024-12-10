/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t* _0;
    int64_t* _1;
};

/* Function forward definitions */
int64_t _1938_main(void);


/* Function definitions */
int64_t _1938_main(void){
    int64_t _1939_x;
    int64_t _1939_y;
    int64_t* _1938_t5;
    int64_t* _1938_t6;
    struct struct0 _1939_z;
    int64_t _1938_$retval;
    _1939_x = 30;
    _1939_y = 29;
    _1938_t5 = &_1939_x;
    _1938_t6 = &_1939_y;
    _1939_z = (struct struct0) {_1938_t5, _1938_t6};
    _1938_$retval = $add_int64_t(*_1939_z._0, *_1939_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1938_$retval;
}


int main(void) {
  printf("%ld",_1938_main());
  return 0;
}
