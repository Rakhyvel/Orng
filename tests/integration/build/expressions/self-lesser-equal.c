/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _849_main(void);
uint8_t _854_f(int64_t _854_x);

/* Function definitions */
int64_t _849_main(void){
    function0 _849_t1;
    int64_t _849_t3;
    uint8_t _849_t2;
    int64_t _849_t0;
    int64_t _849_$retval;
    _849_t1 = _854_f;
    _849_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _849_t2 = _849_t1(_849_t3);
    $line_idx--;
    if (_849_t2) {
        goto BB1067;
    } else {
        goto BB1071;
    }
BB1067:
    _849_t0 = 228;
    goto BB1070;
BB1071:
    _849_t0 = 0;
    goto BB1070;
BB1070:
    _849_$retval = _849_t0;
    return _849_$retval;
}

uint8_t _854_f(int64_t _854_x){
    uint8_t _854_$retval;
    (void)_854_x;
    _854_$retval = 1;
    return _854_$retval;
}

int main(void) {
  printf("%ld",_849_main());
  return 0;
}
