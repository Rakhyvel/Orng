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
int64_t _940_main(void);

/* Function definitions */
int64_t _940_main(void) {
    int64_t _940_t2;
    int64_t _940_t3;
    struct0 _940_t1;
    int64_t _943_x;
    int64_t _943_y;
    int64_t _940_t4;
    int64_t _940_$retval;
    _940_t2 = 230;
    _940_t3 = 4;
    _940_t1 = (struct0) {_940_t2, _940_t3};
    _943_x = _940_t1._0;
    _943_y = _940_t1._1;
    _940_t4 = 4;
    _943_y = $div_int64_t(_943_y, _940_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _940_$retval = $add_int64_t(_943_x, _943_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _940_$retval;
}

int main(void) {
  printf("%ld",_940_main());
  return 0;
}
