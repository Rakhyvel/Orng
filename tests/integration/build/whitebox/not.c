/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1160_main(void);
int64_t _1162_f(uint8_t _1162_b);

/* Function definitions */
int64_t _1160_main(void) {
    int64_t _1161_x;
    int64_t* _1161_y;
    function0 _1160_t2;
    int64_t _1160_t4;
    uint8_t _1160_t6;
    uint8_t _1160_t5;
    uint8_t _1160_t7;
    int64_t _1160_t3;
    int64_t _1160_$retval;
    _1161_x = 0;
    _1161_y = &_1161_x;
    _1160_t2 = _1162_f;
    _1160_t4 = 1;
    _1160_t6 = *_1161_y == _1160_t4;
    if (_1160_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1160_t5 = 1;
    goto BB2;
BB4:
    _1160_t5 = 0;
    goto BB2;
BB2:
    _1160_t7 = !_1160_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1160_t3 = _1160_t2(_1160_t7);
    $line_idx--;
    _1160_$retval = _1160_t3;
    return _1160_$retval;
}

int64_t _1162_f(uint8_t _1162_b) {
    uint8_t _1162_t0;
    uint8_t _1162_t1;
    int64_t _1162_t2;
    int64_t _1162_$retval;
    _1162_t0 = !_1162_b;
    _1162_b = _1162_t0;
    _1162_t1 = !_1162_t0;
    _1162_b = _1162_t1;
    if (_1162_b) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1162_t2 = 31;
    goto BB4;
BB5:
    _1162_t2 = 10;
    goto BB4;
BB4:
    _1162_$retval = _1162_t2;
    return _1162_$retval;
}

int main(void) {
  printf("%ld",_1160_main());
  return 0;
}
