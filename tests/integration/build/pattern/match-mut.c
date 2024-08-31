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
int64_t _1254_main(void);


/* Function definitions */
int64_t _1254_main(void){
    int64_t _1254_t2;
    int64_t _1254_t3;
    struct struct0 _1254_t1;
    int64_t _1257_x;
    int64_t _1257_y;
    int64_t _1254_t4;
    int64_t _1254_$retval;
    _1254_t2 = 230;
    _1254_t3 = 4;
    _1254_t1 = (struct struct0) {_1254_t2, _1254_t3};
    _1257_x = _1254_t1._0;
    _1257_y = _1254_t1._1;
    _1254_t4 = 4;
    _1257_y = $div_int64_t(_1257_y, _1254_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1254_$retval = $add_int64_t(_1257_x, _1257_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1254_$retval;
}


int main(void) {
  printf("%ld",_1254_main());
  return 0;
}
