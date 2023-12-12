/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _385_main(void);
uint8_t _390_f(int64_t _390_x);

/* Function definitions */
int64_t _385_main(void) {
    function0 _385_t1;
    int64_t _385_t3;
    uint8_t _385_t2;
    int64_t _385_t0;
    int64_t _385_$retval;
    _385_t1 = _390_f;
    _385_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _385_t2 = _385_t1(_385_t3);
    $line_idx--;
    if (_385_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _385_t0 = 182;
    goto BB4;
BB5:
    _385_t0 = 4;
    goto BB4;
BB4:
    _385_$retval = _385_t0;
    return _385_$retval;
}

uint8_t _390_f(int64_t _390_x) {
    uint8_t _390_$retval;
    (void)_390_x;
    _390_$retval = 1;
    return _390_$retval;
}

int main(void) {
  printf("%ld",_385_main());
  return 0;
}
