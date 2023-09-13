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
} struct0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t _2_$retval;
    _3_x = (struct0) {120};
    _2_$retval = *(int64_t*)&_3_x;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
