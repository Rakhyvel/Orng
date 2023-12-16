/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _885_main(void);
uint8_t _890_f(int64_t _890_x);

/* Function definitions */
int64_t _885_main(void){
    function0 _885_t1;
    int64_t _885_t3;
    uint8_t _885_t2;
    int64_t _885_t0;
    int64_t _885_$retval;
    _885_t1 = _890_f;
    _885_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _885_t2 = _885_t1(_885_t3);
    $line_idx--;
    if (_885_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _885_t0 = 0;
    goto BB4;
BB5:
    _885_t0 = 223;
    goto BB4;
BB4:
    _885_$retval = _885_t0;
    return _885_$retval;
}

uint8_t _890_f(int64_t _890_x){
    uint8_t _890_$retval;
    (void)_890_x;
    _890_$retval = 0;
    return _890_$retval;
}

int main(void) {
  printf("%ld",_885_main());
  return 0;
}
