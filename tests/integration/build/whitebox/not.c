/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1683_main(void);
int64_t _1685_f(uint8_t _1685_b);

/* Function definitions */
int64_t _1683_main(void) {
    int64_t _1684_x;
    int64_t* _1684_y;
    function0 _1683_t2;
    int64_t _1683_t4;
    uint8_t _1683_t6;
    uint8_t _1683_t5;
    uint8_t _1683_t7;
    int64_t _1683_t3;
    int64_t _1683_$retval;
    _1684_x = 0;
    _1684_y = &_1684_x;
    _1683_t2 = _1685_f;
    _1683_t4 = 1;
    _1683_t6 = *_1684_y == _1683_t4;
    if (_1683_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1683_t5 = 1;
    goto BB2;
BB4:
    _1683_t5 = 0;
    goto BB2;
BB2:
    _1683_t7 = !_1683_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1683_t3 = _1683_t2(_1683_t7);
    $line_idx--;
    _1683_$retval = _1683_t3;
    return _1683_$retval;
}

int64_t _1685_f(uint8_t _1685_b) {
    uint8_t _1685_t0;
    uint8_t _1685_t1;
    int64_t _1685_t2;
    int64_t _1685_$retval;
    _1685_t0 = !_1685_b;
    _1685_b = _1685_t0;
    _1685_t1 = !_1685_t0;
    _1685_b = _1685_t1;
    if (_1685_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1685_t2 = 10;
    goto BB4;
BB1:
    _1685_t2 = 31;
    goto BB4;
BB4:
    _1685_$retval = _1685_t2;
    return _1685_$retval;
}

int main(void) {
  printf("%ld",_1683_main());
  return 0;
}
