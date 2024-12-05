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
int64_t _1904_main(void);


/* Function definitions */
int64_t _1904_main(void){
    int64_t _1905_x;
    int64_t _1905_y;
    int64_t* _1904_t5;
    int64_t* _1904_t6;
    struct struct0 _1905_z;
    int64_t _1904_$retval;
    _1905_x = 30;
    _1905_y = 29;
    _1904_t5 = &_1905_x;
    _1904_t6 = &_1905_y;
    _1905_z = (struct struct0) {_1904_t5, _1904_t6};
    _1904_$retval = $add_int64_t(*_1905_z._0, *_1905_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1904_$retval;
}


int main(void) {
  printf("%ld",_1904_main());
  return 0;
}
