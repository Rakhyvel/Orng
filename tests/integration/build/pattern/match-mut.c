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
int64_t _1239_main(void);

/* Function definitions */
int64_t _1239_main(void){
    int64_t _1239_t2;
    int64_t _1239_t3;
    struct struct0 _1239_t1;
    int64_t _1242_x;
    int64_t _1242_y;
    int64_t _1239_t4;
    int64_t _1239_$retval;
    _1239_t2 = 230;
    _1239_t3 = 4;
    _1239_t1 = (struct struct0) {_1239_t2, _1239_t3};
    _1242_x = _1239_t1._0;
    _1242_y = _1239_t1._1;
    _1239_t4 = 4;
    _1242_y = $div_int64_t(_1242_y, _1239_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1239_$retval = $add_int64_t(_1242_x, _1242_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1239_$retval;
}

int main(void) {
  printf("%ld",_1239_main());
  return 0;
}
