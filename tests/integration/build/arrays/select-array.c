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
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    struct0 _2_t10;
    struct0 _2_t16;
    int64_t _2_$retval;
    _2_t1 = (struct0) {1, 2, 3};
    _2_t10 = _2_t1;
    *((int64_t*)&_2_t10 + 1) = 72;
    _2_t16 = _2_t1;
    _2_$retval = *((int64_t*)&_2_t16 + 1);
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
