/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1191_main(void);
int64_t _1193_f(uint8_t _1193_b);

/* Function definitions */
int64_t _1191_main(void) {
    int64_t _1192_x;
    int64_t* _1192_y;
    function0 _1191_t2;
    int64_t _1191_t4;
    uint8_t _1191_t6;
    uint8_t _1191_t5;
    uint8_t _1191_t7;
    int64_t _1191_t3;
    int64_t _1191_$retval;
    _1192_x = 0;
    _1192_y = &_1192_x;
    _1191_t2 = _1193_f;
    _1191_t4 = 1;
    _1191_t6 = *_1192_y == _1191_t4;
    if (_1191_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1191_t5 = 1;
    goto BB2;
BB4:
    _1191_t5 = 0;
    goto BB2;
BB2:
    _1191_t7 = !_1191_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1191_t3 = _1191_t2(_1191_t7);
    $line_idx--;
    _1191_$retval = _1191_t3;
    return _1191_$retval;
}

int64_t _1193_f(uint8_t _1193_b) {
    uint8_t _1193_t0;
    uint8_t _1193_t1;
    int64_t _1193_t2;
    int64_t _1193_$retval;
    _1193_t0 = !_1193_b;
    _1193_b = _1193_t0;
    _1193_t1 = !_1193_t0;
    _1193_b = _1193_t1;
    if (_1193_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1193_t2 = 10;
    goto BB4;
BB1:
    _1193_t2 = 31;
    goto BB4;
BB4:
    _1193_$retval = _1193_t2;
    return _1193_$retval;
}

int main(void) {
  printf("%ld",_1191_main());
  return 0;
}
