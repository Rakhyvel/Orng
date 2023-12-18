/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _859_main(void);
uint8_t _864_f(int64_t _864_x);

/* Function definitions */
int64_t _859_main(void){
    function0 _859_t1;
    int64_t _859_t3;
    uint8_t _859_t2;
    int64_t _859_t0;
    int64_t _859_$retval;
    _859_t1 = _864_f;
    _859_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _859_t2 = _859_t1(_859_t3);
    $line_idx--;
    if (_859_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _859_t0 = 191;
    goto BB4;
BB5:
    _859_t0 = 4;
    goto BB4;
BB4:
    _859_$retval = _859_t0;
    return _859_$retval;
}

uint8_t _864_f(int64_t _864_x){
    uint8_t _864_$retval;
    (void)_864_x;
    _864_$retval = 1;
    return _864_$retval;
}

int main(void) {
  printf("%ld",_859_main());
  return 0;
}
