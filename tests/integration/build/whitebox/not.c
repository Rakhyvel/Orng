/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1280_main(void);
int64_t _1282_f(uint8_t _1282_b);

/* Function definitions */
int64_t _1280_main(void) {
    int64_t _1281_x;
    int64_t* _1281_y;
    function0 _1280_t2;
    int64_t _1280_t4;
    uint8_t _1280_t6;
    uint8_t _1280_t5;
    uint8_t _1280_t7;
    int64_t _1280_t3;
    int64_t _1280_$retval;
    _1281_x = 0;
    _1281_y = &_1281_x;
    _1280_t2 = _1282_f;
    _1280_t4 = 1;
    _1280_t6 = *_1281_y == _1280_t4;
    if (_1280_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1280_t5 = 1;
    goto BB2;
BB4:
    _1280_t5 = 0;
    goto BB2;
BB2:
    _1280_t7 = !_1280_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1280_t3 = _1280_t2(_1280_t7);
    $line_idx--;
    _1280_$retval = _1280_t3;
    return _1280_$retval;
}

int64_t _1282_f(uint8_t _1282_b) {
    uint8_t _1282_t0;
    uint8_t _1282_t1;
    int64_t _1282_t2;
    int64_t _1282_$retval;
    _1282_t0 = !_1282_b;
    _1282_b = _1282_t0;
    _1282_t1 = !_1282_t0;
    _1282_b = _1282_t1;
    if (_1282_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1282_t2 = 10;
    goto BB4;
BB1:
    _1282_t2 = 31;
    goto BB4;
BB4:
    _1282_$retval = _1282_t2;
    return _1282_$retval;
}

int main(void) {
  printf("%ld",_1280_main());
  return 0;
}
