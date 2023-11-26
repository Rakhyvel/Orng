/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _63_main(void);
int64_t _65_f(uint8_t _65_b);

/* Function definitions */
int64_t _63_main(void) {
    int64_t _64_x;
    int64_t* _64_y;
    function0 _63_t2;
    int64_t _63_t4;
    uint8_t _63_t6;
    uint8_t _63_t5;
    uint8_t _63_t7;
    int64_t _63_t3;
    int64_t _63_$retval;
    _64_x = 0;
    _64_y = &_64_x;
    _63_t2 = _65_f;
    _63_t4 = 1;
    _63_t6 = *_64_y == _63_t4;
    if (_63_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _63_t5 = 1;
    goto BB2;
BB4:
    _63_t5 = 0;
    goto BB2;
BB2:
    _63_t7 = !_63_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _63_t3 = _63_t2(_63_t7);
    $line_idx--;
    _63_$retval = _63_t3;
    return _63_$retval;
}

int64_t _65_f(uint8_t _65_b) {
    uint8_t _65_t0;
    uint8_t _65_t1;
    int64_t _65_t2;
    int64_t _65_$retval;
    _65_t0 = !_65_b;
    _65_b = _65_t0;
    _65_t1 = !_65_t0;
    _65_b = _65_t1;
    if (_65_b) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _65_t2 = 31;
    goto BB4;
BB5:
    _65_t2 = 10;
    goto BB4;
BB4:
    _65_$retval = _65_t2;
    return _65_$retval;
}

int main(void) {
  printf("%ld",_63_main());
  return 0;
}
