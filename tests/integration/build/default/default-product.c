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
    struct0 _3_x;
    int64_t _2_t3;
    int64_t _2_$retval;
    _3_x = (struct0) {0, 0.0e+00};
    if (_3_x._0 == 0) {
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
    if (_3_x._1 == 0.0e+00) {
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
