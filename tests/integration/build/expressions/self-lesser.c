/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _962_main(void);
uint8_t _967_f(int64_t _967_x);

/* Function definitions */
int64_t _962_main(void){
    function0 _962_t1;
    int64_t _962_t3;
    uint8_t _962_t2;
    int64_t _962_t0;
    int64_t _962_$retval;
    _962_t1 = _967_f;
    _962_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser.orng:3:10:\n    if f(4) {\n        ^";
    _962_t2 = _962_t1(_962_t3);
    $line_idx--;
    if (_962_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _962_t0 = 0;
    goto BB4;
BB5:
    _962_t0 = 226;
    goto BB4;
BB4:
    _962_$retval = _962_t0;
    return _962_$retval;
}

uint8_t _967_f(int64_t _967_x){
    uint8_t _967_$retval;
    (void)_967_x;
    _967_$retval = 0;
    return _967_$retval;
}

int main(void) {
  printf("%ld",_962_main());
  return 0;
}
