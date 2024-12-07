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
int64_t _1918_main(void);


/* Function definitions */
int64_t _1918_main(void){
    int64_t _1919_x;
    int64_t _1919_y;
    int64_t* _1918_t5;
    int64_t* _1918_t6;
    struct struct0 _1919_z;
    int64_t _1918_$retval;
    _1919_x = 30;
    _1919_y = 29;
    _1918_t5 = &_1919_x;
    _1918_t6 = &_1919_y;
    _1919_z = (struct struct0) {_1918_t5, _1918_t6};
    _1918_$retval = $add_int64_t(*_1919_z._0, *_1919_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1918_$retval;
}


int main(void) {
  printf("%ld",_1918_main());
  return 0;
}
