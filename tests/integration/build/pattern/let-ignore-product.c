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
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _863_main(void);

/* Function definitions */
int64_t _863_main(void) {
    int64_t _863_t1;
    int64_t _863_t2;
    int64_t _863_t3;
    struct0 _863_t0;
    int64_t _864_a;
    int64_t _864_c;
    int64_t _863_$retval;
    _863_t1 = 100;
    _863_t2 = 300;
    _863_t3 = 56;
    _863_t0 = (struct0) {_863_t1, _863_t2, _863_t3};
    _864_a = _863_t0._0;
    _864_c = _863_t0._2;
    _863_$retval = $add_int64_t(_864_a, _864_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _863_$retval;
}

int main(void) {
  printf("%ld",_863_main());
  return 0;
}
