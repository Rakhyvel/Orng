/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _799_main(void);
uint8_t _804_f(int64_t _804_x);

/* Function definitions */
int64_t _799_main(void) {
    function0 _799_t1;
    int64_t _799_t3;
    uint8_t _799_t2;
    int64_t _799_t0;
    int64_t _799_$retval;
    _799_t1 = _804_f;
    _799_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _799_t2 = _799_t1(_799_t3);
    $line_idx--;
    if (_799_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _799_t0 = 0;
    goto BB4;
BB5:
    _799_t0 = 223;
    goto BB4;
BB4:
    _799_$retval = _799_t0;
    return _799_$retval;
}

uint8_t _804_f(int64_t _804_x) {
    uint8_t _804_$retval;
    (void)_804_x;
    _804_$retval = 0;
    return _804_$retval;
}

int main(void) {
  printf("%ld",_799_main());
  return 0;
}
