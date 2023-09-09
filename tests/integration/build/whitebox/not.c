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
    int64_t* _3_y;
    int64_t _2_t3;
    int64_t _2_t4;
    uint8_t _2_t2;
    uint8_t _2_t5;
    uint8_t _2_t6;
    uint8_t _2_t7;
    int64_t _2_t8;
    int64_t _2_$retval;
BB0:
    _3_x = 0;
    _3_y = &_3_x;
    _2_t3 = *_3_y;
    _2_t4 = 1;
    _2_t2 = _2_t3 == _2_t4;
    if (_2_t2) {
        goto BB1;
    } else {
        goto BB9;
    }
BB9:
    _2_t2 = 0;
    goto BB2;
BB2:
    _2_t5 = !_2_t2;
    _2_t6 = !_2_t5;
    _2_t7 = !_2_t6;
    if (_2_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB7:
    _2_t8 = 10;
    goto BB6;
BB6:
    _2_$retval = _2_t8;
    return _2_$retval;
BB3:
    _2_t8 = 31;
    goto BB6;
BB1:
    _2_t2 = 1;
    goto BB2;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
