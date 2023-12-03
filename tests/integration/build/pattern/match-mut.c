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
int64_t _886_main(void);

/* Function definitions */
int64_t _886_main(void) {
    int64_t _886_t2;
    int64_t _886_t3;
    struct0 _886_t1;
    int64_t _889_x;
    int64_t _889_y;
    int64_t _886_t4;
    int64_t _886_$retval;
    _886_t2 = 230;
    _886_t3 = 4;
    _886_t1 = (struct0) {_886_t2, _886_t3};
    _889_x = _886_t1._0;
    _889_y = _886_t1._1;
    _886_t4 = 4;
    _889_y = $div_int64_t(_889_y, _886_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _886_$retval = $add_int64_t(_889_x, _889_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _886_$retval;
}

int main(void) {
  printf("%ld",_886_main());
  return 0;
}
