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
int64_t _1755_main(void);


/* Function definitions */
int64_t _1755_main(void){
    int64_t _1756_x;
    int64_t _1756_y;
    int64_t* _1755_t5;
    int64_t* _1755_t6;
    struct struct0 _1756_z;
    int64_t _1755_$retval;
    _1756_x = 30;
    _1756_y = 29;
    _1755_t5 = &_1756_x;
    _1755_t6 = &_1756_y;
    _1756_z = (struct struct0) {_1755_t5, _1755_t6};
    _1755_$retval = $add_int64_t(*_1756_z._0, *_1756_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1755_$retval;
}


int main(void) {
  printf("%ld",_1755_main());
  return 0;
}
