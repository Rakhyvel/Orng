/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _727_main(void);
uint8_t _732_f(int64_t _732_x);

/* Function definitions */
int64_t _727_main(void){
    function0 _727_t1;
    int64_t _727_t3;
    uint8_t _727_t2;
    int64_t _727_t0;
    int64_t _727_$retval;
    _727_t1 = _732_f;
    _727_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _727_t2 = _727_t1(_727_t3);
    $line_idx--;
    if (_727_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _727_t0 = 182;
    goto BB4;
BB5:
    _727_t0 = 4;
    goto BB4;
BB4:
    _727_$retval = _727_t0;
    return _727_$retval;
}

uint8_t _732_f(int64_t _732_x){
    uint8_t _732_$retval;
    (void)_732_x;
    _732_$retval = 1;
    return _732_$retval;
}

int main(void) {
  printf("%ld",_727_main());
  return 0;
}
