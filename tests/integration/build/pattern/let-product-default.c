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
int64_t _1142_main(void);

/* Function definitions */
int64_t _1142_main(void){
    int64_t _1142_t1;
    int64_t _1142_t2;
    struct0 _1142_t0;
    int64_t _1143_a;
    int64_t _1143_b;
    int64_t _1142_t4;
    int64_t _1142_t5;
    uint8_t _1142_t7;
    int64_t _1142_t3;
    int64_t _1142_$retval;
    _1142_t1 = 0;
    _1142_t2 = 0;
    _1142_t0 = (struct0) {_1142_t1, _1142_t2};
    _1143_a = _1142_t0._0;
    _1143_b = _1142_t0._1;
    _1142_t4 = $add_int64_t(_1143_a, _1143_b, "tests/integration/pattern/let-product-default.orng:4:11:\n    if a + b == 0 {\n         ^");
    _1142_t5 = 0;
    _1142_t7 = _1142_t4==_1142_t5;
    if (_1142_t7) {
        goto BB1363;
    } else {
        goto BB1367;
    }
BB1363:
    _1142_t3 = 160;
    goto BB1366;
BB1367:
    _1142_t3 = 61;
    goto BB1366;
BB1366:
    _1142_$retval = _1142_t3;
    return _1142_$retval;
}

int main(void) {
  printf("%ld",_1142_main());
  return 0;
}
