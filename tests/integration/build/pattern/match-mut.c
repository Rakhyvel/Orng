/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1244_main(void);

/* Function definitions */
int64_t _1244_main(void){
    int64_t _1244_t2;
    int64_t _1244_t3;
    struct struct0 _1244_t1;
    int64_t _1247_x;
    int64_t _1247_y;
    int64_t _1244_t4;
    int64_t _1244_$retval;
    _1244_t2 = 230;
    _1244_t3 = 4;
    _1244_t1 = (struct struct0) {_1244_t2, _1244_t3};
    _1247_x = _1244_t1._0;
    _1247_y = _1244_t1._1;
    _1244_t4 = 4;
    _1247_y = $div_int64_t(_1247_y, _1244_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1244_$retval = $add_int64_t(_1247_x, _1247_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1244_$retval;
}

int main(void) {
  printf("%ld",_1244_main());
  return 0;
}
