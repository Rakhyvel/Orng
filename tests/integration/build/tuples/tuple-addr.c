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
int64_t _1923_main(void);


/* Function definitions */
int64_t _1923_main(void){
    int64_t _1924_x;
    int64_t _1924_y;
    int64_t* _1923_t5;
    int64_t* _1923_t6;
    struct struct0 _1924_z;
    int64_t _1923_$retval;
    _1924_x = 30;
    _1924_y = 29;
    _1923_t5 = &_1924_x;
    _1923_t6 = &_1924_y;
    _1924_z = (struct struct0) {_1923_t5, _1923_t6};
    _1923_$retval = $add_int64_t(*_1924_z._0, *_1924_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1923_$retval;
}


int main(void) {
  printf("%ld",_1923_main());
  return 0;
}
