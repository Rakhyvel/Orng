/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _797_main(void);
uint8_t _802_f(int64_t _802_x);

/* Function definitions */
int64_t _797_main(void) {
    function0 _797_t1;
    int64_t _797_t3;
    uint8_t _797_t2;
    int64_t _797_t0;
    int64_t _797_$retval;
    _797_t1 = _802_f;
    _797_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _797_t2 = _797_t1(_797_t3);
    $line_idx--;
    if (_797_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _797_t0 = 0;
    goto BB4;
BB5:
    _797_t0 = 223;
    goto BB4;
BB4:
    _797_$retval = _797_t0;
    return _797_$retval;
}

uint8_t _802_f(int64_t _802_x) {
    uint8_t _802_$retval;
    (void)_802_x;
    _802_$retval = 0;
    return _802_$retval;
}

int main(void) {
  printf("%ld",_797_main());
  return 0;
}
