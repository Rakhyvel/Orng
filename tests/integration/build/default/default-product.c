/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    double _2_t2;
    struct0 _3_x;
    int64_t _2_t6;
    int64_t _2_t7;
    uint8_t _2_t5;
    double _2_t9;
    double _2_t10;
    uint8_t _2_t8;
    int64_t _2_t3;
    int64_t _2_$retval;
    _2_t1 = 0;
    _2_t2 = 0.0e+00;
    _3_x = (struct0) {_2_t1, _2_t2};
    _2_t6 = (&_3_x)->_0;
    _2_t7 = 0;
    _2_t5 = _2_t6 == _2_t7;
    if (_2_t5) {
        goto BB1;
    } else {
        goto BB11;
    }
BB11:
    _2_t3 = 0;
    goto BB10;
BB10:
    _2_$retval = _2_t3;
    return _2_$retval;
BB1:
    _2_t9 = (&_3_x)->_1;
    _2_t10 = 0.0e+00;
    _2_t8 = _2_t9 == _2_t10;
    if (_2_t8) {
        goto BB4;
    } else {
        goto BB11;
    }
BB4:
    _2_t3 = 135;
    goto BB10;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
