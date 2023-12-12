/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _603_main(void);
uint8_t _608_f(int64_t _608_x);

/* Function definitions */
int64_t _603_main(void) {
    function0 _603_t1;
    int64_t _603_t3;
    uint8_t _603_t2;
    int64_t _603_t0;
    int64_t _603_$retval;
    _603_t1 = _608_f;
    _603_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _603_t2 = _603_t1(_603_t3);
    $line_idx--;
    if (_603_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _603_t0 = 228;
    goto BB4;
BB5:
    _603_t0 = 0;
    goto BB4;
BB4:
    _603_$retval = _603_t0;
    return _603_$retval;
}

uint8_t _608_f(int64_t _608_x) {
    uint8_t _608_$retval;
    (void)_608_x;
    _608_$retval = 1;
    return _608_$retval;
}

int main(void) {
  printf("%ld",_603_main());
  return 0;
}
