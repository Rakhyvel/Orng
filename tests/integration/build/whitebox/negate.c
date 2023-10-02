/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t* _2_y;
    int64_t _1_t2;
    int64_t _1_$retval;
    _2_x = 1;
    _2_y = &_2_x;
    if ($negate_int64_t(*_2_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^") == -1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_t2 = 32;
    goto BB4;
BB5:
    _1_t2 = 10;
BB4:
    _1_$retval = _1_t2;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
