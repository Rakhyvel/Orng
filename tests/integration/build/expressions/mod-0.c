/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _688_main(void);
uint8_t _693_f(int64_t _693_x);

/* Function definitions */
int64_t _688_main(void) {
    function0 _688_t1;
    int64_t _688_t3;
    uint8_t _688_t2;
    int64_t _688_t0;
    int64_t _688_$retval;
    _688_t1 = _693_f;
    _688_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _688_t2 = _688_t1(_688_t3);
    $line_idx--;
    if (_688_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _688_t0 = 191;
    goto BB4;
BB5:
    _688_t0 = 4;
    goto BB4;
BB4:
    _688_$retval = _688_t0;
    return _688_$retval;
}

uint8_t _693_f(int64_t _693_x) {
    uint8_t _693_$retval;
    (void)_693_x;
    _693_$retval = 1;
    return _693_$retval;
}

int main(void) {
  printf("%ld",_688_main());
  return 0;
}
