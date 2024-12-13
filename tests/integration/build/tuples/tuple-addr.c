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
int64_t _1940_main(void);


/* Function definitions */
int64_t _1940_main(void){
    int64_t _1941_x;
    int64_t _1941_y;
    int64_t* _1940_t5;
    int64_t* _1940_t6;
    struct struct0 _1941_z;
    int64_t _1940_$retval;
    _1941_x = 30;
    _1941_y = 29;
    _1940_t5 = &_1941_x;
    _1940_t6 = &_1941_y;
    _1941_z = (struct struct0) {_1940_t5, _1940_t6};
    _1940_$retval = $add_int64_t(*_1941_z._0, *_1941_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1940_$retval;
}


int main(void) {
  printf("%ld",_1940_main());
  return 0;
}
