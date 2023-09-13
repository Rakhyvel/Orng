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
    int64_t _3_a;
    int64_t _3_b;
    int64_t _2_t5;
    int64_t _2_$retval;
    _2_t0 = (struct0) {0, 0};
    _3_a = _2_t0._0;
    _3_b = _2_t0._1;
    if (_3_a + _3_b == 0) {
        goto BB1;
    } else {
        goto BB9;
    }
BB9:
    _2_t5 = 61;
    goto BB6;
BB6:
    _2_$retval = _2_t5;
    return _2_$retval;
BB1:
    _2_t5 = 160;
    goto BB6;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
