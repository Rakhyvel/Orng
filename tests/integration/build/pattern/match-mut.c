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
int64_t _1417_main(void);

/* Function definitions */
int64_t _1417_main(void){
    int64_t _1417_t2;
    int64_t _1417_t3;
    struct0 _1417_t1;
    int64_t _1420_x;
    int64_t _1420_y;
    int64_t _1417_t4;
    int64_t _1417_$retval;
    _1417_t2 = 230;
    _1417_t3 = 4;
    _1417_t1 = (struct0) {_1417_t2, _1417_t3};
    _1420_x = _1417_t1._0;
    _1420_y = _1417_t1._1;
    _1417_t4 = 4;
    _1420_y = $div_int64_t(_1420_y, _1417_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1417_$retval = $add_int64_t(_1420_x, _1420_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1417_$retval;
}

int main(void) {
  printf("%ld",_1417_main());
  return 0;
}
