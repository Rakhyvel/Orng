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
int64_t _1150_main(void);

/* Function definitions */
int64_t _1150_main(void) {
    int64_t _1150_t2;
    int64_t _1150_t3;
    struct0 _1150_t1;
    int64_t _1153_x;
    int64_t _1153_y;
    int64_t _1150_t4;
    int64_t _1150_$retval;
    _1150_t2 = 230;
    _1150_t3 = 4;
    _1150_t1 = (struct0) {_1150_t2, _1150_t3};
    _1153_x = _1150_t1._0;
    _1153_y = _1150_t1._1;
    _1150_t4 = 4;
    _1153_y = $div_int64_t(_1153_y, _1150_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1150_$retval = $add_int64_t(_1153_x, _1153_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1150_$retval;
}

int main(void) {
  printf("%ld",_1150_main());
  return 0;
}
