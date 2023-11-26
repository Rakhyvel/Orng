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
int64_t _105_main(void);

/* Function definitions */
int64_t _105_main(void) {
    int64_t _105_t2;
    int64_t _105_t3;
    struct0 _105_t1;
    int64_t _108_x;
    int64_t _108_y;
    int64_t _105_t4;
    int64_t _105_$retval;
    _105_t2 = 230;
    _105_t3 = 4;
    _105_t1 = (struct0) {_105_t2, _105_t3};
    _108_x = _105_t1._0;
    _108_y = _105_t1._1;
    _105_t4 = 4;
    _108_y = $div_int64_t(_108_y, _105_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _105_$retval = $add_int64_t(_108_x, _108_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _105_$retval;
}

int main(void) {
  printf("%ld",_105_main());
  return 0;
}
