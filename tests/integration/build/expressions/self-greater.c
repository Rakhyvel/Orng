/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _801_main(void);
uint8_t _806_f(int64_t _806_x);

/* Function definitions */
int64_t _801_main(void){
    function0 _801_t1;
    int64_t _801_t3;
    uint8_t _801_t2;
    int64_t _801_t0;
    int64_t _801_$retval;
    _801_t1 = _806_f;
    _801_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _801_t2 = _801_t1(_801_t3);
    $line_idx--;
    if (_801_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _801_t0 = 0;
    goto BB4;
BB5:
    _801_t0 = 224;
    goto BB4;
BB4:
    _801_$retval = _801_t0;
    return _801_$retval;
}

uint8_t _806_f(int64_t _806_x){
    uint8_t _806_$retval;
    (void)_806_x;
    _806_$retval = 0;
    return _806_$retval;
}

int main(void) {
  printf("%ld",_801_main());
  return 0;
}
