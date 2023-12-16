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
int64_t _1237_main(void);

/* Function definitions */
int64_t _1237_main(void){
    int64_t _1237_t2;
    int64_t _1237_t3;
    struct0 _1237_t1;
    int64_t _1240_x;
    int64_t _1240_y;
    int64_t _1237_t4;
    int64_t _1237_$retval;
    _1237_t2 = 230;
    _1237_t3 = 4;
    _1237_t1 = (struct0) {_1237_t2, _1237_t3};
    _1240_x = _1237_t1._0;
    _1240_y = _1237_t1._1;
    _1237_t4 = 4;
    _1240_y = $div_int64_t(_1240_y, _1237_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1237_$retval = $add_int64_t(_1240_x, _1240_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1237_$retval;
}

int main(void) {
  printf("%ld",_1237_main());
  return 0;
}
