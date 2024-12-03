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
int64_t _1898_main(void);


/* Function definitions */
int64_t _1898_main(void){
    int64_t _1899_x;
    int64_t _1899_y;
    int64_t* _1898_t5;
    int64_t* _1898_t6;
    struct struct0 _1899_z;
    int64_t _1898_$retval;
    _1899_x = 30;
    _1899_y = 29;
    _1898_t5 = &_1899_x;
    _1898_t6 = &_1899_y;
    _1899_z = (struct struct0) {_1898_t5, _1898_t6};
    _1898_$retval = $add_int64_t(*_1899_z._0, *_1899_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1898_$retval;
}


int main(void) {
  printf("%ld",_1898_main());
  return 0;
}
