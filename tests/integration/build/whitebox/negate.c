/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1760_main(void);


/* Function definitions */
int64_t _1760_main(void){
    int64_t _1761_x;
    int64_t* _1761_y;
    int64_t _1760_t3;
    int64_t _1760_t5;
    uint8_t _1760_t7;
    int64_t _1760_t2;
    int64_t _1760_$retval;
    _1761_x = 1;
    _1761_y = &_1761_x;
    _1760_t3 = $negate_int64_t(*_1761_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1760_t5 = -1;
    _1760_t7 = _1760_t3==_1760_t5;
    if (_1760_t7) {
        goto BB2022;
    } else {
        goto BB2026;
    }
BB2022:
    _1760_t2 = 32;
    goto BB2025;
BB2026:
    _1760_t2 = 10;
    goto BB2025;
BB2025:
    _1760_$retval = _1760_t2;
    return _1760_$retval;
}


int main(void) {
  printf("%ld",_1760_main());
  return 0;
}
