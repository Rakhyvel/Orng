/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1635_main(void);
int64_t _1637_f(uint8_t _1637_b);

/* Function definitions */
int64_t _1635_main(void){
    int64_t _1636_x;
    int64_t* _1636_y;
    function0 _1635_t2;
    int64_t _1635_t4;
    uint8_t _1635_t6;
    uint8_t _1635_t5;
    uint8_t _1635_t7;
    int64_t _1635_t3;
    int64_t _1635_$retval;
    _1636_x = 0;
    _1636_y = &_1636_x;
    _1635_t2 = _1637_f;
    _1635_t4 = 1;
    _1635_t6 = *_1636_y == _1635_t4;
    if (_1635_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1635_t5 = 1;
    goto BB2;
BB4:
    _1635_t5 = 0;
    goto BB2;
BB2:
    _1635_t7 = !_1635_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1635_t3 = _1635_t2(_1635_t7);
    $line_idx--;
    _1635_$retval = _1635_t3;
    return _1635_$retval;
}

int64_t _1637_f(uint8_t _1637_b){
    uint8_t _1637_t0;
    uint8_t _1637_t1;
    int64_t _1637_t2;
    int64_t _1637_$retval;
    _1637_t0 = !_1637_b;
    _1637_b = _1637_t0;
    _1637_t1 = !_1637_t0;
    _1637_b = _1637_t1;
    if (_1637_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1637_t2 = 10;
    goto BB4;
BB1:
    _1637_t2 = 31;
    goto BB4;
BB4:
    _1637_$retval = _1637_t2;
    return _1637_$retval;
}

int main(void) {
  printf("%ld",_1635_main());
  return 0;
}
