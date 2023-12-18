/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _953_main(void);
uint8_t _958_f(int64_t _958_x);

/* Function definitions */
int64_t _953_main(void){
    function0 _953_t1;
    int64_t _953_t3;
    uint8_t _953_t2;
    int64_t _953_t0;
    int64_t _953_$retval;
    _953_t1 = _958_f;
    _953_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _953_t2 = _953_t1(_953_t3);
    $line_idx--;
    if (_953_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _953_t0 = 0;
    goto BB4;
BB5:
    _953_t0 = 224;
    goto BB4;
BB4:
    _953_$retval = _953_t0;
    return _953_$retval;
}

uint8_t _958_f(int64_t _958_x){
    uint8_t _958_$retval;
    (void)_958_x;
    _958_$retval = 0;
    return _958_$retval;
}

int main(void) {
  printf("%ld",_953_main());
  return 0;
}
