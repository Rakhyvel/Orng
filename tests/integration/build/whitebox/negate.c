/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1627_main(void);

/* Function definitions */
int64_t _1627_main(void){
    int64_t _1628_x;
    int64_t* _1628_y;
    int64_t _1627_t3;
    int64_t _1627_t5;
    uint8_t _1627_t7;
    int64_t _1627_t2;
    int64_t _1627_$retval;
    _1628_x = 1;
    _1628_y = &_1628_x;
    _1627_t3 = $negate_int64_t(*_1628_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1627_t5 = -1;
    _1627_t7 = _1627_t3==_1627_t5;
    if (_1627_t7) {
        goto BB1913;
    } else {
        goto BB1917;
    }
BB1913:
    _1627_t2 = 32;
    goto BB1916;
BB1917:
    _1627_t2 = 10;
    goto BB1916;
BB1916:
    _1627_$retval = _1627_t2;
    return _1627_$retval;
}

int main(void) {
  printf("%ld",_1627_main());
  return 0;
}
