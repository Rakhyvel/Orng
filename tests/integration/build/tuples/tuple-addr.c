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
int64_t _1804_main(void);

/* Function definitions */
int64_t _1804_main(void){
    int64_t _1805_x;
    int64_t _1805_y;
    int64_t* _1804_t3;
    int64_t* _1804_t4;
    struct0 _1805_z;
    int64_t _1804_$retval;
    _1805_x = 30;
    _1805_y = 29;
    _1804_t3 = &_1805_x;
    _1804_t4 = &_1805_y;
    _1805_z = (struct0) {_1804_t3, _1804_t4};
    _1804_$retval = $add_int64_t(*_1805_z._0, *_1805_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1804_$retval;
}

int main(void) {
  printf("%ld",_1804_main());
  return 0;
}
