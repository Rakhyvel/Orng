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
int64_t _1304_main(void);


/* Function definitions */
int64_t _1304_main(void){
    int64_t _1304_t2;
    int64_t _1304_t3;
    struct struct0 _1304_t1;
    int64_t _1307_x;
    int64_t _1307_y;
    int64_t _1304_t4;
    int64_t _1304_$retval;
    _1304_t2 = 230;
    _1304_t3 = 4;
    _1304_t1 = (struct struct0) {_1304_t2, _1304_t3};
    _1307_x = _1304_t1._0;
    _1307_y = _1304_t1._1;
    _1304_t4 = 4;
    _1307_y = $div_int64_t(_1307_y, _1304_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1304_$retval = $add_int64_t(_1307_x, _1307_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1304_$retval;
}


int main(void) {
  printf("%ld",_1304_main());
  return 0;
}
