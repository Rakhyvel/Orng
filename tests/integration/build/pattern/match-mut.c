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
int64_t _820_main(void);

/* Function definitions */
int64_t _820_main(void) {
    int64_t _820_t2;
    int64_t _820_t3;
    struct0 _820_t1;
    int64_t _823_x;
    int64_t _823_y;
    int64_t _820_t4;
    int64_t _820_$retval;
    _820_t2 = 230;
    _820_t3 = 4;
    _820_t1 = (struct0) {_820_t2, _820_t3};
    _823_x = _820_t1._0;
    _823_y = _820_t1._1;
    _820_t4 = 4;
    _823_y = $div_int64_t(_823_y, _820_t4, "tests/integration/pattern/match-mut.orng:5:17:\n            y /= 4\n               ^");
    _820_$retval = $add_int64_t(_823_x, _823_y, "tests/integration/pattern/match-mut.orng:6:16:\n            x + y\n              ^");
    return _820_$retval;
}

int main(void) {
  printf("%ld",_820_main());
  return 0;
}
