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
int64_t _1229_main(void);

/* Function definitions */
int64_t _1229_main(void){
    int64_t _1229_t2;
    int64_t _1229_t3;
    struct struct0 _1229_t1;
    int64_t _1232_x;
    int64_t _1232_y;
    int64_t _1229_t4;
    int64_t _1229_$retval;
    _1229_t2 = 230;
    _1229_t3 = 4;
    _1229_t1 = (struct struct0) {_1229_t2, _1229_t3};
    _1232_x = _1229_t1._0;
    _1232_y = _1229_t1._1;
    _1229_t4 = 4;
    _1232_y = $div_int64_t(_1232_y, _1229_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _1229_$retval = $add_int64_t(_1232_x, _1232_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _1229_$retval;
}

int main(void) {
  printf("%ld",_1229_main());
  return 0;
}
