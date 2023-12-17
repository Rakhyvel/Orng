/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1780_main(void);
int64_t _1782_f(uint8_t _1782_b);

/* Function definitions */
int64_t _1780_main(void){
    int64_t _1781_x;
    int64_t* _1781_y;
    function0 _1780_t2;
    int64_t _1780_t4;
    uint8_t _1780_t6;
    uint8_t _1780_t5;
    uint8_t _1780_t7;
    int64_t _1780_t3;
    int64_t _1780_$retval;
    _1781_x = 0;
    _1781_y = &_1781_x;
    _1780_t2 = _1782_f;
    _1780_t4 = 1;
    _1780_t6 = *_1781_y == _1780_t4;
    if (_1780_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1780_t5 = 1;
    goto BB2;
BB4:
    _1780_t5 = 0;
    goto BB2;
BB2:
    _1780_t7 = !_1780_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1780_t3 = _1780_t2(_1780_t7);
    $line_idx--;
    _1780_$retval = _1780_t3;
    return _1780_$retval;
}

int64_t _1782_f(uint8_t _1782_b){
    uint8_t _1782_t0;
    uint8_t _1782_t1;
    int64_t _1782_t2;
    int64_t _1782_$retval;
    _1782_t0 = !_1782_b;
    _1782_b = _1782_t0;
    _1782_t1 = !_1782_t0;
    _1782_b = _1782_t1;
    if (_1782_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1782_t2 = 10;
    goto BB4;
BB1:
    _1782_t2 = 31;
    goto BB4;
BB4:
    _1782_$retval = _1782_t2;
    return _1782_$retval;
}

int main(void) {
  printf("%ld",_1780_main());
  return 0;
}
