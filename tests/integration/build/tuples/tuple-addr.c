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
int64_t _1157_main(void);

/* Function definitions */
int64_t _1157_main(void) {
    int64_t _1158_x;
    int64_t _1158_y;
    int64_t* _1157_t3;
    int64_t* _1157_t4;
    struct0 _1158_z;
    int64_t _1157_$retval;
    _1158_x = 30;
    _1158_y = 29;
    _1157_t3 = &_1158_x;
    _1157_t4 = &_1158_y;
    _1158_z = (struct0) {_1157_t3, _1157_t4};
    _1157_$retval = $add_int64_t(*_1158_z._0, *_1158_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _1157_$retval;
}

int main(void) {
  printf("%ld",_1157_main());
  return 0;
}
