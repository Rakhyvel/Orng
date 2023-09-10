/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _3_x;
    int64_t _2_t3;
    uint8_t _2_t2;
    int64_t _2_t6;
    uint8_t _2_t5;
    int64_t _2_t7;
    int64_t _2_$retval;
    int64_t _2_t9;
    _3_x = 0;
    goto BB1;
BB1:
    _2_t3 = 100;
    _2_t2 = _3_x < _2_t3;
    if (_2_t2) {
        goto BB2;
    } else {
        goto BB9;
    }
BB9:
    _2_$retval = _3_x;
    return _2_$retval;
BB2:
    _2_t6 = 40;
    _2_t5 = _3_x == _2_t6;
    if (_2_t5) {
        goto BB5;
    } else {
        goto BB14;
    }
BB14:
    _2_t9 = 1;
    _3_x = _3_x + _2_t9;
    goto BB1;
BB5:
    _2_t7 = 1;
    _3_x = _3_x + _2_t7;
    goto BB9;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
