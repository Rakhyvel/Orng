/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1660_main(void);
int64_t _1662_f(uint8_t _1662_b);

/* Function definitions */
int64_t _1660_main(void) {
    int64_t _1661_x;
    int64_t* _1661_y;
    function0 _1660_t2;
    int64_t _1660_t4;
    uint8_t _1660_t6;
    uint8_t _1660_t5;
    uint8_t _1660_t7;
    int64_t _1660_t3;
    int64_t _1660_$retval;
    _1661_x = 0;
    _1661_y = &_1661_x;
    _1660_t2 = _1662_f;
    _1660_t4 = 1;
    _1660_t6 = *_1661_y == _1660_t4;
    if (_1660_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1660_t5 = 1;
    goto BB2;
BB4:
    _1660_t5 = 0;
    goto BB2;
BB2:
    _1660_t7 = !_1660_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1660_t3 = _1660_t2(_1660_t7);
    $line_idx--;
    _1660_$retval = _1660_t3;
    return _1660_$retval;
}

int64_t _1662_f(uint8_t _1662_b) {
    uint8_t _1662_t0;
    uint8_t _1662_t1;
    int64_t _1662_t2;
    int64_t _1662_$retval;
    _1662_t0 = !_1662_b;
    _1662_b = _1662_t0;
    _1662_t1 = !_1662_t0;
    _1662_b = _1662_t1;
    if (_1662_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1662_t2 = 10;
    goto BB4;
BB1:
    _1662_t2 = 31;
    goto BB4;
BB4:
    _1662_$retval = _1662_t2;
    return _1662_$retval;
}

int main(void) {
  printf("%ld",_1660_main());
  return 0;
}
