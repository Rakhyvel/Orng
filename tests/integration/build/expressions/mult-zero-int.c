/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _890_main(void);
uint8_t _895_f(int64_t _895_x);

/* Function definitions */
int64_t _890_main(void){
    function0 _890_t1;
    int64_t _890_t3;
    uint8_t _890_t2;
    int64_t _890_t0;
    int64_t _890_$retval;
    _890_t1 = _895_f;
    _890_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _890_t2 = _890_t1(_890_t3);
    $line_idx--;
    if (_890_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _890_t0 = 187;
    goto BB4;
BB5:
    _890_t0 = 4;
    goto BB4;
BB4:
    _890_$retval = _890_t0;
    return _890_$retval;
}

uint8_t _895_f(int64_t _895_x){
    uint8_t _895_$retval;
    (void)_895_x;
    _895_$retval = 1;
    return _895_$retval;
}

int main(void) {
  printf("%ld",_890_main());
  return 0;
}
