/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _806_main(void);
uint8_t _811_f(int64_t _811_x);

/* Function definitions */
int64_t _806_main(void) {
    function0 _806_t1;
    int64_t _806_t3;
    uint8_t _806_t2;
    int64_t _806_t0;
    int64_t _806_$retval;
    _806_t1 = _811_f;
    _806_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _806_t2 = _806_t1(_806_t3);
    $line_idx--;
    if (_806_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _806_t0 = 0;
    goto BB4;
BB5:
    _806_t0 = 223;
    goto BB4;
BB4:
    _806_$retval = _806_t0;
    return _806_$retval;
}

uint8_t _811_f(int64_t _811_x) {
    uint8_t _811_$retval;
    (void)_811_x;
    _811_$retval = 0;
    return _811_$retval;
}

int main(void) {
  printf("%ld",_806_main());
  return 0;
}
