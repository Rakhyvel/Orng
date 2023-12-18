/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _961_main(void);
uint8_t _966_f(int64_t _966_x);

/* Function definitions */
int64_t _961_main(void){
    function0 _961_t1;
    int64_t _961_t3;
    uint8_t _961_t2;
    int64_t _961_t0;
    int64_t _961_$retval;
    _961_t1 = _966_f;
    _961_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _961_t2 = _961_t1(_961_t3);
    $line_idx--;
    if (_961_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _961_t0 = 228;
    goto BB4;
BB5:
    _961_t0 = 0;
    goto BB4;
BB4:
    _961_$retval = _961_t0;
    return _961_$retval;
}

uint8_t _966_f(int64_t _966_x){
    uint8_t _966_$retval;
    (void)_966_x;
    _966_$retval = 1;
    return _966_$retval;
}

int main(void) {
  printf("%ld",_961_main());
  return 0;
}
