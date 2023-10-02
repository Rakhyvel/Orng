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
    int64_t _2_y;
    int64_t* _1_t3;
    int64_t* _1_t4;
    int64_t _1_$retval;
    _2_x = 30;
    _2_y = 29;
    _1_t3 = &_2_x;
    _1_t4 = &_2_y;
    _1_$retval = $add_int64_t(*_1_t3, *_1_t4, "tests/integration/tuples/tuple-addr.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
