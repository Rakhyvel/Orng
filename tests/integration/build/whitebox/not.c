/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1229_main(void);
int64_t _1231_f(uint8_t _1231_b);

/* Function definitions */
int64_t _1229_main(void) {
    int64_t _1230_x;
    int64_t* _1230_y;
    function0 _1229_t2;
    int64_t _1229_t4;
    uint8_t _1229_t6;
    uint8_t _1229_t5;
    uint8_t _1229_t7;
    int64_t _1229_t3;
    int64_t _1229_$retval;
    _1230_x = 0;
    _1230_y = &_1230_x;
    _1229_t2 = _1231_f;
    _1229_t4 = 1;
    _1229_t6 = *_1230_y == _1229_t4;
    if (_1229_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1229_t5 = 1;
    goto BB2;
BB4:
    _1229_t5 = 0;
    goto BB2;
BB2:
    _1229_t7 = !_1229_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1229_t3 = _1229_t2(_1229_t7);
    $line_idx--;
    _1229_$retval = _1229_t3;
    return _1229_$retval;
}

int64_t _1231_f(uint8_t _1231_b) {
    uint8_t _1231_t0;
    uint8_t _1231_t1;
    int64_t _1231_t2;
    int64_t _1231_$retval;
    _1231_t0 = !_1231_b;
    _1231_b = _1231_t0;
    _1231_t1 = !_1231_t0;
    _1231_b = _1231_t1;
    if (_1231_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1231_t2 = 10;
    goto BB4;
BB1:
    _1231_t2 = 31;
    goto BB4;
BB4:
    _1231_$retval = _1231_t2;
    return _1231_$retval;
}

int main(void) {
  printf("%ld",_1229_main());
  return 0;
}
