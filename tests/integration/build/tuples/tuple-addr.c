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
int64_t _1888_main(void);


/* Function definitions */
int64_t _1888_main(void){
    int64_t _1889_x;
    int64_t _1889_y;
    int64_t* _1888_t5;
    int64_t* _1888_t6;
    struct struct0 _1889_z;
    int64_t _1888_$retval;
    _1889_x = 30;
    _1889_y = 29;
    _1888_t5 = &_1889_x;
    _1888_t6 = &_1889_y;
    _1889_z = (struct struct0) {_1888_t5, _1888_t6};
    _1888_$retval = $add_int64_t(*_1889_z._0, *_1889_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1888_$retval;
}


int main(void) {
  printf("%ld",_1888_main());
  return 0;
}
