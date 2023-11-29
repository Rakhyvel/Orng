/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _416_main(void);
uint8_t _421_f(int64_t _421_x);

/* Function definitions */
int64_t _416_main(void) {
    function0 _416_t1;
    int64_t _416_t3;
    uint8_t _416_t2;
    int64_t _416_t0;
    int64_t _416_$retval;
    _416_t1 = _421_f;
    _416_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _416_t2 = _416_t1(_416_t3);
    $line_idx--;
    if (_416_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _416_t0 = 182;
    goto BB4;
BB5:
    _416_t0 = 4;
    goto BB4;
BB4:
    _416_$retval = _416_t0;
    return _416_$retval;
}

uint8_t _421_f(int64_t _421_x) {
    uint8_t _421_$retval;
    (void)_421_x;
    _421_$retval = 1;
    return _421_$retval;
}

int main(void) {
  printf("%ld",_416_main());
  return 0;
}
