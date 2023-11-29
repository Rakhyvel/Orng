/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1314_main(void);
int64_t _1316_f(uint8_t _1316_b);

/* Function definitions */
int64_t _1314_main(void) {
    int64_t _1315_x;
    int64_t* _1315_y;
    function0 _1314_t2;
    int64_t _1314_t4;
    uint8_t _1314_t6;
    uint8_t _1314_t5;
    uint8_t _1314_t7;
    int64_t _1314_t3;
    int64_t _1314_$retval;
    _1315_x = 0;
    _1315_y = &_1315_x;
    _1314_t2 = _1316_f;
    _1314_t4 = 1;
    _1314_t6 = *_1315_y == _1314_t4;
    if (_1314_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1314_t5 = 1;
    goto BB2;
BB4:
    _1314_t5 = 0;
    goto BB2;
BB2:
    _1314_t7 = !_1314_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1314_t3 = _1314_t2(_1314_t7);
    $line_idx--;
    _1314_$retval = _1314_t3;
    return _1314_$retval;
}

int64_t _1316_f(uint8_t _1316_b) {
    uint8_t _1316_t0;
    uint8_t _1316_t1;
    int64_t _1316_t2;
    int64_t _1316_$retval;
    _1316_t0 = !_1316_b;
    _1316_b = _1316_t0;
    _1316_t1 = !_1316_t0;
    _1316_b = _1316_t1;
    if (_1316_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1316_t2 = 10;
    goto BB4;
BB1:
    _1316_t2 = 31;
    goto BB4;
BB4:
    _1316_$retval = _1316_t2;
    return _1316_$retval;
}

int main(void) {
  printf("%ld",_1314_main());
  return 0;
}
