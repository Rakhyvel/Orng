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
int64_t _1743_main(void);


/* Function definitions */
int64_t _1743_main(void){
    int64_t _1744_x;
    int64_t _1744_y;
    int64_t* _1743_t5;
    int64_t* _1743_t6;
    struct struct0 _1744_z;
    int64_t _1743_$retval;
    _1744_x = 30;
    _1744_y = 29;
    _1743_t5 = &_1744_x;
    _1743_t6 = &_1744_y;
    _1744_z = (struct struct0) {_1743_t5, _1743_t6};
    _1743_$retval = $add_int64_t(*_1744_z._0, *_1744_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1743_$retval;
}


int main(void) {
  printf("%ld",_1743_main());
  return 0;
}
