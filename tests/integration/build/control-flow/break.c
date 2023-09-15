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
    int64_t _4_i;
    int64_t _2_$retval;
    _3_x = 36;
    _4_i = 0;
BB1:
    if (_4_i < 70) {
        goto BB2;
    } else {
        goto BB17;
    }
BB2:
    if (_4_i % 2 == 0) {
        goto BB9;
    } else {
        goto BB14;
    }
BB17:
    _3_x = 10;
BB9:
    _2_$retval = _3_x;
    return _2_$retval;
BB14:
    _3_x = _3_x + 1;
    _4_i = _4_i + 1;
    goto BB1;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
