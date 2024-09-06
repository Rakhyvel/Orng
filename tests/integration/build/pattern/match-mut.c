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
int64_t _1307_main(void);


/* Function definitions */
int64_t _1307_main(void){
    int64_t _1307_t2;
    int64_t _1307_t3;
    struct struct0 _1307_t1;
    int64_t _1310_x;
    int64_t _1310_y;
    int64_t _1307_t4;
    int64_t _1307_$retval;
    _1307_t2 = 230;
    _1307_t3 = 4;
    _1307_t1 = (struct struct0) {_1307_t2, _1307_t3};
    _1310_x = _1307_t1._0;
    _1310_y = _1307_t1._1;
    _1307_t4 = 4;
    _1310_y = $div_int64_t(_1310_y, _1307_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1307_$retval = $add_int64_t(_1310_x, _1310_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1307_$retval;
}


int main(void) {
  printf("%ld",_1307_main());
  return 0;
}
