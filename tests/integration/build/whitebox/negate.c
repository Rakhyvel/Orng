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
    int64_t _2_t2;
    int64_t _2_$retval;
    _3_x = 1;
    _3_y = &_3_x;
    if (-*_3_y == -1) {
        goto BB1;
    } else {
        goto BB9;
    }
BB9:
    _2_t2 = 10;
    goto BB6;
BB6:
    _2_$retval = _2_t2;
    return _2_$retval;
BB1:
    _2_t2 = 32;
    goto BB6;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
