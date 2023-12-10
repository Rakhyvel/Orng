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
int64_t _910_main(void);

/* Function definitions */
int64_t _910_main(void) {
    int64_t _910_t2;
    int64_t _910_t3;
    struct0 _910_t1;
    int64_t _913_x;
    int64_t _913_y;
    int64_t _910_t4;
    int64_t _910_$retval;
    _910_t2 = 230;
    _910_t3 = 4;
    _910_t1 = (struct0) {_910_t2, _910_t3};
    _913_x = _910_t1._0;
    _913_y = _910_t1._1;
    _910_t4 = 4;
    _913_y = $div_int64_t(_913_y, _910_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _910_$retval = $add_int64_t(_913_x, _913_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _910_$retval;
}

int main(void) {
  printf("%ld",_910_main());
  return 0;
}
