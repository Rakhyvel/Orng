/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _17_main(void);

/* Function definitions */
int64_t _17_main(void) {
    int64_t _17_t1;
    int64_t _17_t4;
    struct0 _18_x;
    struct0* _18_y;
    int64_t _17_$retval;
    _17_t1 = 19;
    _17_t4 = 39;
    _18_x = (struct0) {_17_t1, _17_t4};
    _18_y = &_18_x;
    _17_$retval = $add_int64_t((*_18_y)._0, (*_18_y)._1, "tests/integration/tuples/addr-tuple.orng:5:11:\n    y^.a + y^.b\n         ^");
    return _17_$retval;
}

int main(void) {
  printf("%ld",_17_main());
  return 0;
}
