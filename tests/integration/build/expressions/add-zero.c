/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _582_main(void);
uint8_t _587_f(int64_t _587_x);

/* Function definitions */
int64_t _582_main(void){
    function0 _582_t1;
    int64_t _582_t3;
    uint8_t _582_t2;
    int64_t _582_t0;
    int64_t _582_$retval;
    _582_t1 = _587_f;
    _582_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _582_t2 = _582_t1(_582_t3);
    $line_idx--;
    if (_582_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _582_t0 = 182;
    goto BB4;
BB5:
    _582_t0 = 4;
    goto BB4;
BB4:
    _582_$retval = _582_t0;
    return _582_$retval;
}

uint8_t _587_f(int64_t _587_x){
    uint8_t _587_$retval;
    (void)_587_x;
    _587_$retval = 1;
    return _587_$retval;
}

int main(void) {
  printf("%ld",_582_main());
  return 0;
}
