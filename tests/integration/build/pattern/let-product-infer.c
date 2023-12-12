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
int64_t _862_main(void);

/* Function definitions */
int64_t _862_main(void) {
    int64_t _862_t1;
    int64_t _862_t2;
    struct0 _862_t0;
    int64_t _863_a;
    int64_t _863_b;
    int64_t _862_$retval;
    _862_t1 = 100;
    _862_t2 = 58;
    _862_t0 = (struct0) {_862_t1, _862_t2};
    _863_a = _862_t0._0;
    _863_b = _862_t0._1;
    _862_$retval = $add_int64_t(_863_a, _863_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _862_$retval;
}

int main(void) {
  printf("%ld",_862_main());
  return 0;
}
