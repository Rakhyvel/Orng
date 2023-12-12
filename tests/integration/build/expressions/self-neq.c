/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _638_main(void);
uint8_t _643_f(int64_t _643_x);

/* Function definitions */
int64_t _638_main(void) {
    function0 _638_t1;
    int64_t _638_t3;
    uint8_t _638_t2;
    int64_t _638_t0;
    int64_t _638_$retval;
    _638_t1 = _643_f;
    _638_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _638_t2 = _638_t1(_638_t3);
    $line_idx--;
    if (_638_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _638_t0 = 0;
    goto BB4;
BB5:
    _638_t0 = 223;
    goto BB4;
BB4:
    _638_$retval = _638_t0;
    return _638_$retval;
}

uint8_t _643_f(int64_t _643_x) {
    uint8_t _643_$retval;
    (void)_643_x;
    _643_$retval = 0;
    return _643_$retval;
}

int main(void) {
  printf("%ld",_638_main());
  return 0;
}
