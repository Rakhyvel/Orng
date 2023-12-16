/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _726_main(void);
uint8_t _731_f(int64_t _731_x);

/* Function definitions */
int64_t _726_main(void) {
    function0 _726_t1;
    int64_t _726_t3;
    uint8_t _726_t2;
    int64_t _726_t0;
    int64_t _726_$retval;
    _726_t1 = _731_f;
    _726_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _726_t2 = _726_t1(_726_t3);
    $line_idx--;
    if (_726_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _726_t0 = 187;
    goto BB4;
BB5:
    _726_t0 = 4;
    goto BB4;
BB4:
    _726_$retval = _726_t0;
    return _726_$retval;
}

uint8_t _731_f(int64_t _731_x) {
    uint8_t _731_$retval;
    (void)_731_x;
    _731_$retval = 1;
    return _731_$retval;
}

int main(void) {
  printf("%ld",_726_main());
  return 0;
}
