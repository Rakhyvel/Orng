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
    _3_x = 0;
    goto BB1;
BB1:
    if (_3_x < 100) {
        goto BB2;
    } else {
        goto BB9;
    }
BB9:
    _2_$retval = _3_x;
    return _2_$retval;
BB2:
    if (_3_x == 40) {
        goto BB5;
    } else {
        goto BB14;
    }
BB14:
    _3_x = _3_x + 1;
    goto BB1;
BB5:
    _3_x = _3_x + 1;
    goto BB9;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
