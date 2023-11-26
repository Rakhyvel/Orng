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
int64_t _53_main(void);

/* Function definitions */
int64_t _53_main(void) {
    int64_t _54_x;
    int64_t _54_y;
    int64_t* _53_t3;
    int64_t* _53_t4;
    struct0 _54_z;
    int64_t _53_$retval;
    _54_x = 30;
    _54_y = 29;
    _53_t3 = &_54_x;
    _53_t4 = &_54_y;
    _54_z = (struct0) {_53_t3, _53_t4};
    _53_$retval = $add_int64_t(*_54_z._0, *_54_z._1, "tests/integration/tuples/tuple-addr.orng:6:11:\n    z.a^ + z.b^\n         ^");
    return _53_$retval;
}

int main(void) {
  printf("%ld",_53_main());
  return 0;
}
