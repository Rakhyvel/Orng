/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1253_main(void);
int64_t _1255_f(uint8_t _1255_b);

/* Function definitions */
int64_t _1253_main(void) {
    int64_t _1254_x;
    int64_t* _1254_y;
    function0 _1253_t2;
    int64_t _1253_t4;
    uint8_t _1253_t6;
    uint8_t _1253_t5;
    uint8_t _1253_t7;
    int64_t _1253_t3;
    int64_t _1253_$retval;
    _1254_x = 0;
    _1254_y = &_1254_x;
    _1253_t2 = _1255_f;
    _1253_t4 = 1;
    _1253_t6 = *_1254_y == _1253_t4;
    if (_1253_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1253_t5 = 1;
    goto BB2;
BB4:
    _1253_t5 = 0;
    goto BB2;
BB2:
    _1253_t7 = !_1253_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1253_t3 = _1253_t2(_1253_t7);
    $line_idx--;
    _1253_$retval = _1253_t3;
    return _1253_$retval;
}

int64_t _1255_f(uint8_t _1255_b) {
    uint8_t _1255_t0;
    uint8_t _1255_t1;
    int64_t _1255_t2;
    int64_t _1255_$retval;
    _1255_t0 = !_1255_b;
    _1255_b = _1255_t0;
    _1255_t1 = !_1255_t0;
    _1255_b = _1255_t1;
    if (_1255_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1255_t2 = 10;
    goto BB4;
BB1:
    _1255_t2 = 31;
    goto BB4;
BB4:
    _1255_$retval = _1255_t2;
    return _1255_$retval;
}

int main(void) {
  printf("%ld",_1253_main());
  return 0;
}
