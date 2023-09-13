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
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t0;
    int64_t _3_x;
    int64_t _3_y;
    int64_t _2_$retval;
    _2_t0 = (struct0) {5, 30};
    _3_x = _2_t0._0;
    _3_y = _2_t0._1;
    _2_$retval = _3_x * _3_y + 1;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
