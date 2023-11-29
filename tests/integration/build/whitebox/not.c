/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1681_main(void);
int64_t _1683_f(uint8_t _1683_b);

/* Function definitions */
int64_t _1681_main(void) {
    int64_t _1682_x;
    int64_t* _1682_y;
    function0 _1681_t2;
    int64_t _1681_t4;
    uint8_t _1681_t6;
    uint8_t _1681_t5;
    uint8_t _1681_t7;
    int64_t _1681_t3;
    int64_t _1681_$retval;
    _1682_x = 0;
    _1682_y = &_1682_x;
    _1681_t2 = _1683_f;
    _1681_t4 = 1;
    _1681_t6 = *_1682_y == _1681_t4;
    if (_1681_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1681_t5 = 1;
    goto BB2;
BB4:
    _1681_t5 = 0;
    goto BB2;
BB2:
    _1681_t7 = !_1681_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1681_t3 = _1681_t2(_1681_t7);
    $line_idx--;
    _1681_$retval = _1681_t3;
    return _1681_$retval;
}

int64_t _1683_f(uint8_t _1683_b) {
    uint8_t _1683_t0;
    uint8_t _1683_t1;
    int64_t _1683_t2;
    int64_t _1683_$retval;
    _1683_t0 = !_1683_b;
    _1683_b = _1683_t0;
    _1683_t1 = !_1683_t0;
    _1683_b = _1683_t1;
    if (_1683_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1683_t2 = 10;
    goto BB4;
BB1:
    _1683_t2 = 31;
    goto BB4;
BB4:
    _1683_$retval = _1683_t2;
    return _1683_$retval;
}

int main(void) {
  printf("%ld",_1681_main());
  return 0;
}
