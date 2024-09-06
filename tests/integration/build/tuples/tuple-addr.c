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
int64_t _1858_main(void);


/* Function definitions */
int64_t _1858_main(void){
    int64_t _1859_x;
    int64_t _1859_y;
    int64_t* _1858_t5;
    int64_t* _1858_t6;
    struct struct0 _1859_z;
    int64_t _1858_$retval;
    _1859_x = 30;
    _1859_y = 29;
    _1858_t5 = &_1859_x;
    _1858_t6 = &_1859_y;
    _1859_z = (struct struct0) {_1858_t5, _1858_t6};
    _1858_$retval = $add_int64_t(*_1859_z._0, *_1859_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1858_$retval;
}


int main(void) {
  printf("%ld",_1858_main());
  return 0;
}
