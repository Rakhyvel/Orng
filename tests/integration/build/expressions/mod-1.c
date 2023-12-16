/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _704_main(void);
uint8_t _709_f(int64_t _709_x);

/* Function definitions */
int64_t _704_main(void){
    function0 _704_t1;
    int64_t _704_t3;
    uint8_t _704_t2;
    int64_t _704_t0;
    int64_t _704_$retval;
    _704_t1 = _709_f;
    _704_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _704_t2 = _704_t1(_704_t3);
    $line_idx--;
    if (_704_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _704_t0 = 192;
    goto BB4;
BB5:
    _704_t0 = 4;
    goto BB4;
BB4:
    _704_$retval = _704_t0;
    return _704_$retval;
}

uint8_t _709_f(int64_t _709_x){
    uint8_t _709_$retval;
    (void)_709_x;
    _709_$retval = 1;
    return _709_$retval;
}

int main(void) {
  printf("%ld",_704_main());
  return 0;
}
