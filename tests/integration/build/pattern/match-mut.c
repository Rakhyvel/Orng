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
int64_t _937_main(void);

/* Function definitions */
int64_t _937_main(void) {
    int64_t _937_t2;
    int64_t _937_t3;
    struct0 _937_t1;
    int64_t _940_x;
    int64_t _940_y;
    int64_t _937_t4;
    int64_t _937_$retval;
    _937_t2 = 230;
    _937_t3 = 4;
    _937_t1 = (struct0) {_937_t2, _937_t3};
    _940_x = _937_t1._0;
    _940_y = _937_t1._1;
    _937_t4 = 4;
    _940_y = $div_int64_t(_940_y, _937_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _937_$retval = $add_int64_t(_940_x, _940_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _937_$retval;
}

int main(void) {
  printf("%ld",_937_main());
  return 0;
}
