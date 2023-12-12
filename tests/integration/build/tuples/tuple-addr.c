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
int64_t _1208_main(void);

/* Function definitions */
int64_t _1208_main(void) {
    int64_t _1209_x;
    int64_t _1209_y;
    int64_t* _1208_t3;
    int64_t* _1208_t4;
    struct0 _1209_z;
    int64_t _1208_$retval;
    _1209_x = 30;
    _1209_y = 29;
    _1208_t3 = &_1209_x;
    _1208_t4 = &_1209_y;
    _1209_z = (struct0) {_1208_t3, _1208_t4};
    _1208_$retval = $add_int64_t(*_1209_z._0, *_1209_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1208_$retval;
}

int main(void) {
  printf("%ld",_1208_main());
  return 0;
}
