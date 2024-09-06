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
int64_t _1851_main(void);


/* Function definitions */
int64_t _1851_main(void){
    int64_t _1852_x;
    int64_t _1852_y;
    int64_t* _1851_t5;
    int64_t* _1851_t6;
    struct struct0 _1852_z;
    int64_t _1851_$retval;
    _1852_x = 30;
    _1852_y = 29;
    _1851_t5 = &_1852_x;
    _1851_t6 = &_1852_y;
    _1852_z = (struct struct0) {_1851_t5, _1851_t6};
    _1851_$retval = $add_int64_t(*_1852_z._0, *_1852_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1851_$retval;
}


int main(void) {
  printf("%ld",_1851_main());
  return 0;
}
