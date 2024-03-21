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
int64_t _1779_main(void);


/* Function definitions */
int64_t _1779_main(void){
    int64_t _1780_x;
    int64_t _1780_y;
    int64_t* _1779_t5;
    int64_t* _1779_t6;
    struct struct0 _1780_z;
    int64_t _1779_$retval;
    _1780_x = 30;
    _1780_y = 29;
    _1779_t5 = &_1780_x;
    _1779_t6 = &_1780_y;
    _1780_z = (struct struct0) {_1779_t5, _1779_t6};
    _1779_$retval = $add_int64_t(*_1780_z._0, *_1780_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1779_$retval;
}


int main(void) {
  printf("%ld",_1779_main());
  return 0;
}
