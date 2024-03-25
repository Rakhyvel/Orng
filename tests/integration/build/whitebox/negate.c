/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1851_main(void);


/* Function definitions */
int64_t _1851_main(void){
    int64_t _1852_x;
    int64_t* _1852_y;
    int64_t _1851_t5;
    int64_t _1851_t7;
    uint8_t _1851_t9;
    int64_t _1851_t4;
    int64_t _1851_$retval;
    _1852_x = 1;
    _1852_y = &_1852_x;
    _1851_t5 = $negate_int64_t(*_1852_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1851_t7 = -1;
    _1851_t9 = _1851_t5==_1851_t7;
    if (_1851_t9) {
        goto BB2062;
    } else {
        goto BB2066;
    }
BB2062:
    _1851_t4 = 32;
    goto BB2065;
BB2066:
    _1851_t4 = 10;
    goto BB2065;
BB2065:
    _1851_$retval = _1851_t4;
    return _1851_$retval;
}


int main(void) {
  printf("%ld",_1851_main());
  return 0;
}
