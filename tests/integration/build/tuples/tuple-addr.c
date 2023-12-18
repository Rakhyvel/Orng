/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
} struct0;

/* Function forward definitions */
int64_t _1797_main(void);

/* Function definitions */
int64_t _1797_main(void){
    int64_t _1798_x;
    int64_t _1798_y;
    int64_t* _1797_t3;
    int64_t* _1797_t4;
    struct0 _1798_z;
    int64_t _1797_$retval;
    _1798_x = 30;
    _1798_y = 29;
    _1797_t3 = &_1798_x;
    _1797_t4 = &_1798_y;
    _1798_z = (struct0) {_1797_t3, _1797_t4};
    _1797_$retval = $add_int64_t(*_1798_z._0, *_1798_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1797_$retval;
}

int main(void) {
  printf("%ld",_1797_main());
  return 0;
}
