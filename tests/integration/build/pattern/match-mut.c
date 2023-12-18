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
int64_t _1411_main(void);

/* Function definitions */
int64_t _1411_main(void){
    int64_t _1411_t2;
    int64_t _1411_t3;
    struct0 _1411_t1;
    int64_t _1414_x;
    int64_t _1414_y;
    int64_t _1411_t4;
    int64_t _1411_$retval;
    _1411_t2 = 230;
    _1411_t3 = 4;
    _1411_t1 = (struct0) {_1411_t2, _1411_t3};
    _1414_x = _1411_t1._0;
    _1414_y = _1411_t1._1;
    _1411_t4 = 4;
    _1414_y = $div_int64_t(_1414_y, _1411_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1411_$retval = $add_int64_t(_1414_x, _1414_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1411_$retval;
}

int main(void) {
  printf("%ld",_1411_main());
  return 0;
}
