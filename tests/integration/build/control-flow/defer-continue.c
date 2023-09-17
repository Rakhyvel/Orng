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
    int64_t _2_$retval;
    _3_x = 17;
BB1:
    if (_3_x < 36) {
        goto BB4;
    } else {
        goto BB16;
    }
BB4:
    if (_3_x % 2) {
        goto BB12;
    } else {
        goto BB8;
    }
BB16:
    _2_$retval = _3_x;
    return _2_$retval;
BB12:
    _3_x = _3_x + 1;
BB8:
    _3_x = _3_x + 9;
    goto BB1;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
