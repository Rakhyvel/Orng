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
    int64_t _3_y;
    int64_t* _2_t3;
    int64_t* _2_t4;
    int64_t _2_$retval;
    _3_x = 30;
    _3_y = 29;
    _2_t3 = &_3_x;
    _2_t4 = &_3_y;
    _2_$retval = *_2_t3 + *_2_t4;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
