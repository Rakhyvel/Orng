/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _867_main(void);
uint8_t _872_f(int64_t _872_x);

/* Function definitions */
int64_t _867_main(void){
    function0 _867_t1;
    int64_t _867_t3;
    uint8_t _867_t2;
    int64_t _867_t0;
    int64_t _867_$retval;
    _867_t1 = _872_f;
    _867_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _867_t2 = _867_t1(_867_t3);
    $line_idx--;
    if (_867_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _867_t0 = 192;
    goto BB4;
BB5:
    _867_t0 = 4;
    goto BB4;
BB4:
    _867_$retval = _867_t0;
    return _867_$retval;
}

uint8_t _872_f(int64_t _872_x){
    uint8_t _872_$retval;
    (void)_872_x;
    _872_$retval = 1;
    return _872_$retval;
}

int main(void) {
  printf("%ld",_867_main());
  return 0;
}
