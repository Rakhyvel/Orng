/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _755_main(void);
uint8_t _760_f(int64_t _760_x);

/* Function definitions */
int64_t _755_main(void){
    function0 _755_t1;
    int64_t _755_t3;
    uint8_t _755_t2;
    int64_t _755_t0;
    int64_t _755_$retval;
    _755_t1 = _760_f;
    _755_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-1.orng:3:10:\n    if f(4) {\n        ^";
    _755_t2 = _755_t1(_755_t3);
    $line_idx--;
    if (_755_t2) {
        goto BB924;
    } else {
        goto BB928;
    }
BB924:
    _755_t0 = 192;
    goto BB927;
BB928:
    _755_t0 = 4;
    goto BB927;
BB927:
    _755_$retval = _755_t0;
    return _755_$retval;
}

uint8_t _760_f(int64_t _760_x){
    uint8_t _760_$retval;
    (void)_760_x;
    _760_$retval = 1;
    return _760_$retval;
}

int main(void) {
  printf("%ld",_755_main());
  return 0;
}
