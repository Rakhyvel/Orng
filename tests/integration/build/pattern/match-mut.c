/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1240_main(void);


/* Function definitions */
int64_t _1240_main(void){
    int64_t _1240_t2;
    int64_t _1240_t3;
    struct struct0 _1240_t1;
    int64_t _1243_x;
    int64_t _1243_y;
    int64_t _1240_t4;
    int64_t _1240_$retval;
    _1240_t2 = 230;
    _1240_t3 = 4;
    _1240_t1 = (struct struct0) {_1240_t2, _1240_t3};
    _1243_x = _1240_t1._0;
    _1243_y = _1240_t1._1;
    _1240_t4 = 4;
    _1243_y = $div_int64_t(_1243_y, _1240_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1240_$retval = $add_int64_t(_1243_x, _1243_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1240_$retval;
}


int main(void) {
  printf("%ld",_1240_main());
  return 0;
}
