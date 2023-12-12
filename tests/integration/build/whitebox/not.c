/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1261_main(void);
int64_t _1263_f(uint8_t _1263_b);

/* Function definitions */
int64_t _1261_main(void) {
    int64_t _1262_x;
    int64_t* _1262_y;
    function0 _1261_t2;
    int64_t _1261_t4;
    uint8_t _1261_t6;
    uint8_t _1261_t5;
    uint8_t _1261_t7;
    int64_t _1261_t3;
    int64_t _1261_$retval;
    _1262_x = 0;
    _1262_y = &_1262_x;
    _1261_t2 = _1263_f;
    _1261_t4 = 1;
    _1261_t6 = *_1262_y == _1261_t4;
    if (_1261_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1261_t5 = 1;
    goto BB2;
BB4:
    _1261_t5 = 0;
    goto BB2;
BB2:
    _1261_t7 = !_1261_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1261_t3 = _1261_t2(_1261_t7);
    $line_idx--;
    _1261_$retval = _1261_t3;
    return _1261_$retval;
}

int64_t _1263_f(uint8_t _1263_b) {
    uint8_t _1263_t0;
    uint8_t _1263_t1;
    int64_t _1263_t2;
    int64_t _1263_$retval;
    _1263_t0 = !_1263_b;
    _1263_b = _1263_t0;
    _1263_t1 = !_1263_t0;
    _1263_b = _1263_t1;
    if (_1263_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1263_t2 = 10;
    goto BB4;
BB1:
    _1263_t2 = 31;
    goto BB4;
BB4:
    _1263_$retval = _1263_t2;
    return _1263_$retval;
}

int main(void) {
  printf("%ld",_1261_main());
  return 0;
}
