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
int64_t _918_main(void);

/* Function definitions */
int64_t _918_main(void) {
    int64_t _918_t2;
    int64_t _918_t3;
    struct0 _918_t1;
    int64_t _921_x;
    int64_t _921_y;
    int64_t _918_t4;
    int64_t _918_$retval;
    _918_t2 = 230;
    _918_t3 = 4;
    _918_t1 = (struct0) {_918_t2, _918_t3};
    _921_x = _918_t1._0;
    _921_y = _918_t1._1;
    _918_t4 = 4;
    _921_y = $div_int64_t(_921_y, _918_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _918_$retval = $add_int64_t(_921_x, _921_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _918_$retval;
}

int main(void) {
  printf("%ld",_918_main());
  return 0;
}
