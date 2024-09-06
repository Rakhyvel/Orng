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
int64_t _1890_main(void);


/* Function definitions */
int64_t _1890_main(void){
    int64_t _1891_x;
    int64_t _1891_y;
    int64_t* _1890_t5;
    int64_t* _1890_t6;
    struct struct0 _1891_z;
    int64_t _1890_$retval;
    _1891_x = 30;
    _1891_y = 29;
    _1890_t5 = &_1891_x;
    _1890_t6 = &_1891_y;
    _1891_z = (struct struct0) {_1890_t5, _1890_t6};
    _1890_$retval = $add_int64_t(*_1891_z._0, *_1891_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1890_$retval;
}


int main(void) {
  printf("%ld",_1890_main());
  return 0;
}
