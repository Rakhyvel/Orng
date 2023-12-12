/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _404_main(void);
uint8_t _409_f(int64_t _409_x);

/* Function definitions */
int64_t _404_main(void) {
    function0 _404_t1;
    int64_t _404_t3;
    uint8_t _404_t2;
    int64_t _404_t0;
    int64_t _404_$retval;
    _404_t1 = _409_f;
    _404_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _404_t2 = _404_t1(_404_t3);
    $line_idx--;
    if (_404_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _404_t0 = 182;
    goto BB4;
BB5:
    _404_t0 = 4;
    goto BB4;
BB4:
    _404_$retval = _404_t0;
    return _404_$retval;
}

uint8_t _409_f(int64_t _409_x) {
    uint8_t _409_$retval;
    (void)_409_x;
    _409_$retval = 1;
    return _409_$retval;
}

int main(void) {
  printf("%ld",_404_main());
  return 0;
}
