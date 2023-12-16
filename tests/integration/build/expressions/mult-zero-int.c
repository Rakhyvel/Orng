/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _805_main(void);
uint8_t _810_f(int64_t _810_x);

/* Function definitions */
int64_t _805_main(void){
    function0 _805_t1;
    int64_t _805_t3;
    uint8_t _805_t2;
    int64_t _805_t0;
    int64_t _805_$retval;
    _805_t1 = _810_f;
    _805_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _805_t2 = _805_t1(_805_t3);
    $line_idx--;
    if (_805_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _805_t0 = 187;
    goto BB4;
BB5:
    _805_t0 = 4;
    goto BB4;
BB4:
    _805_$retval = _805_t0;
    return _805_$retval;
}

uint8_t _810_f(int64_t _810_x){
    uint8_t _810_$retval;
    (void)_810_x;
    _810_$retval = 1;
    return _810_$retval;
}

int main(void) {
  printf("%ld",_805_main());
  return 0;
}
