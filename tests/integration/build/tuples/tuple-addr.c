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
int64_t _1893_main(void);


/* Function definitions */
int64_t _1893_main(void){
    int64_t _1894_x;
    int64_t _1894_y;
    int64_t* _1893_t5;
    int64_t* _1893_t6;
    struct struct0 _1894_z;
    int64_t _1893_$retval;
    _1894_x = 30;
    _1894_y = 29;
    _1893_t5 = &_1894_x;
    _1893_t6 = &_1894_y;
    _1894_z = (struct struct0) {_1893_t5, _1893_t6};
    _1893_$retval = $add_int64_t(*_1894_z._0, *_1894_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1893_$retval;
}


int main(void) {
  printf("%ld",_1893_main());
  return 0;
}
