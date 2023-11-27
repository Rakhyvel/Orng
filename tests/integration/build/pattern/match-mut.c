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
int64_t _851_main(void);

/* Function definitions */
int64_t _851_main(void) {
    int64_t _851_t2;
    int64_t _851_t3;
    struct0 _851_t1;
    int64_t _854_x;
    int64_t _854_y;
    int64_t _851_t4;
    int64_t _851_$retval;
    _851_t2 = 230;
    _851_t3 = 4;
    _851_t1 = (struct0) {_851_t2, _851_t3};
    _854_x = _851_t1._0;
    _854_y = _851_t1._1;
    _851_t4 = 4;
    _854_y = $div_int64_t(_854_y, _851_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _851_$retval = $add_int64_t(_854_x, _854_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _851_$retval;
}

int main(void) {
  printf("%ld",_851_main());
  return 0;
}
