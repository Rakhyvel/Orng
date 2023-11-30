/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _711_main(void);
uint8_t _716_f(int64_t _716_x);

/* Function definitions */
int64_t _711_main(void) {
    function0 _711_t1;
    int64_t _711_t3;
    uint8_t _711_t2;
    int64_t _711_t0;
    int64_t _711_$retval;
    _711_t1 = _716_f;
    _711_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _711_t2 = _711_t1(_711_t3);
    $line_idx--;
    if (_711_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _711_t0 = 187;
    goto BB4;
BB5:
    _711_t0 = 4;
    goto BB4;
BB4:
    _711_$retval = _711_t0;
    return _711_$retval;
}

uint8_t _716_f(int64_t _716_x) {
    uint8_t _716_$retval;
    (void)_716_x;
    _716_$retval = 1;
    return _716_$retval;
}

int main(void) {
  printf("%ld",_711_main());
  return 0;
}
