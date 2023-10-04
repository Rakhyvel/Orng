/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t _1_$retval;
    _2_x = (struct0) {100, 100, 3, 4};
    _1_$retval = $add_int64_t($add_int64_t($add_int64_t(*(int64_t*)&_2_x, *((int64_t*)&_2_x + 1), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^"), *((int64_t*)&_2_x + 2), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^"), *((int64_t*)&_2_x + 3), "tests/integration/layout/trailing-comma.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
