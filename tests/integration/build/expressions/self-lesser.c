/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _817_main(void);
uint8_t _822_f(int64_t _822_x);

/* Function definitions */
int64_t _817_main(void){
    function0 _817_t1;
    int64_t _817_t3;
    uint8_t _817_t2;
    int64_t _817_t0;
    int64_t _817_$retval;
    _817_t1 = _822_f;
    _817_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _817_t2 = _817_t1(_817_t3);
    $line_idx--;
    if (_817_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _817_t0 = 0;
    goto BB4;
BB5:
    _817_t0 = 226;
    goto BB4;
BB4:
    _817_$retval = _817_t0;
    return _817_$retval;
}

uint8_t _822_f(int64_t _822_x){
    uint8_t _822_$retval;
    (void)_822_x;
    _822_$retval = 0;
    return _822_$retval;
}

int main(void) {
  printf("%ld",_817_main());
  return 0;
}
