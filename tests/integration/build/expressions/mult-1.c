/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _761_main(void);
uint8_t _766_f(int64_t _766_x);


/* Function definitions */
int64_t _761_main(void){
    function0 _761_t1;
    int64_t _761_t3;
    uint8_t _761_t2;
    int64_t _761_t0;
    int64_t _761_$retval;
    _761_t1 = (function0) _766_f;
    _761_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _761_t2 = _761_t1(_761_t3);
    $line_idx--;
    if (_761_t2) {
        goto BB898;
    } else {
        goto BB902;
    }
BB898:
    _761_t0 = 186;
    goto BB901;
BB902:
    _761_t0 = 4;
    goto BB901;
BB901:
    _761_$retval = _761_t0;
    return _761_$retval;
}

uint8_t _766_f(int64_t _766_x){
    uint8_t _766_$retval;
    (void)_766_x;
    goto BB891;
BB891:
    _766_$retval = 1;
    return _766_$retval;
}


int main(void) {
  printf("%ld",_761_main());
  return 0;
}
