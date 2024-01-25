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
int64_t _1653_main(void);


/* Function definitions */
int64_t _1653_main(void){
    int64_t _1654_x;
    int64_t _1654_y;
    int64_t* _1653_t3;
    int64_t* _1653_t4;
    struct struct0 _1654_z;
    int64_t _1653_$retval;
    _1654_x = 30;
    _1654_y = 29;
    _1653_t3 = &_1654_x;
    _1653_t4 = &_1654_y;
    _1654_z = (struct struct0) {_1653_t3, _1653_t4};
    _1653_$retval = $add_int64_t(*_1654_z._0, *_1654_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1653_$retval;
}


int main(void) {
  printf("%ld",_1653_main());
  return 0;
}
