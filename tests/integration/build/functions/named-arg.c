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
int64_t _4_div(int64_t _4_x,int64_t _4_y);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:2:23:\nfn main() -> Int {div(x = 510, y = 10)}\n                     ^";
    _2_t0 = _4_div(510, 10);
    $line_idx--;
    _2_$retval = _2_t0;
    return _2_$retval;
}

int64_t _4_div(int64_t _4_x,int64_t _4_y) {
    int64_t _4_$retval;
    _4_$retval = _4_x / _4_y;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
