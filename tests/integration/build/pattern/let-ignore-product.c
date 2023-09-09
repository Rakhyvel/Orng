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
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    struct0 _2_t0;
    int64_t _3_a;
    int64_t _3_c;
    int64_t _2_$retval;
BB0:
    _2_t1 = 100;
    _2_t2 = 300;
    _2_t3 = 56;
    _2_t0 = (struct0) {_2_t1, _2_t2, _2_t3};
    _3_a = (&_2_t0)->_0;
    _3_c = (&_2_t0)->_2;
    _2_$retval = _3_a + _3_c;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
