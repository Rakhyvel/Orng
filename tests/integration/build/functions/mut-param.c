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
int64_t _4_sumDown(int64_t _4_x);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:27:\nfn main() -> Int {sumDown(8) + 2}\n                         ^";
    _2_t0 = _4_sumDown(8);
    $line_idx--;
    _2_$retval = _2_t0 + 2;
    return _2_$retval;
}

int64_t _4_sumDown(int64_t _4_x) {
    int64_t _6_i;
    int64_t _4_$retval;
    _6_i = _4_x;
BB1:
    if (_6_i >= 0) {
        goto BB4;
    } else {
        goto BB9;
    }
BB4:
    _4_x = _4_x + _6_i;
    _6_i = _6_i - 1;
    goto BB1;
BB9:
    _4_$retval = _4_x;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
