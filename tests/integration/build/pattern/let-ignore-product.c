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
int64_t _1322_main(void);

/* Function definitions */
int64_t _1322_main(void){
    int64_t _1322_t1;
    int64_t _1322_t2;
    int64_t _1322_t3;
    struct0 _1322_t0;
    int64_t _1323_a;
    int64_t _1323_c;
    int64_t _1322_$retval;
    _1322_t1 = 100;
    _1322_t2 = 300;
    _1322_t3 = 56;
    _1322_t0 = (struct0) {_1322_t1, _1322_t2, _1322_t3};
    _1323_a = _1322_t0._0;
    _1323_c = _1322_t0._2;
    _1322_$retval = $add_int64_t(_1323_a, _1323_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1322_$retval;
}

int main(void) {
  printf("%ld",_1322_main());
  return 0;
}
