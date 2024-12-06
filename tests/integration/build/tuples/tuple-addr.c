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
int64_t _1910_main(void);


/* Function definitions */
int64_t _1910_main(void){
    int64_t _1911_x;
    int64_t _1911_y;
    int64_t* _1910_t5;
    int64_t* _1910_t6;
    struct struct0 _1911_z;
    int64_t _1910_$retval;
    _1911_x = 30;
    _1911_y = 29;
    _1910_t5 = &_1911_x;
    _1910_t6 = &_1911_y;
    _1911_z = (struct struct0) {_1910_t5, _1910_t6};
    _1910_$retval = $add_int64_t(*_1911_z._0, *_1911_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1910_$retval;
}


int main(void) {
  printf("%ld",_1910_main());
  return 0;
}
