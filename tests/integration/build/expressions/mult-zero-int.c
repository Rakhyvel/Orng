/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _539_main(void);
uint8_t _544_f(int64_t _544_x);

/* Function definitions */
int64_t _539_main(void) {
    function0 _539_t1;
    int64_t _539_t3;
    uint8_t _539_t2;
    int64_t _539_t0;
    int64_t _539_$retval;
    _539_t1 = _544_f;
    _539_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _539_t2 = _539_t1(_539_t3);
    $line_idx--;
    if (_539_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _539_t0 = 187;
    goto BB4;
BB5:
    _539_t0 = 4;
    goto BB4;
BB4:
    _539_$retval = _539_t0;
    return _539_$retval;
}

uint8_t _544_f(int64_t _544_x) {
    uint8_t _544_$retval;
    (void)_544_x;
    _544_$retval = 1;
    return _544_$retval;
}

int main(void) {
  printf("%ld",_539_main());
  return 0;
}
