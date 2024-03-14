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
int64_t _1274_main(void);


/* Function definitions */
int64_t _1274_main(void){
    int64_t _1274_t2;
    int64_t _1274_t3;
    struct struct0 _1274_t1;
    int64_t _1277_x;
    int64_t _1277_y;
    int64_t _1274_t4;
    int64_t _1274_$retval;
    _1274_t2 = 230;
    _1274_t3 = 4;
    _1274_t1 = (struct struct0) {_1274_t2, _1274_t3};
    _1277_x = _1274_t1._0;
    _1277_y = _1274_t1._1;
    _1274_t4 = 4;
    _1277_y = $div_int64_t(_1277_y, _1274_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1274_$retval = $add_int64_t(_1277_x, _1277_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1274_$retval;
}


int main(void) {
  printf("%ld",_1274_main());
  return 0;
}
