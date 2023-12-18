/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _977_main(void);
uint8_t _982_f(int64_t _982_x);

/* Function definitions */
int64_t _977_main(void){
    function0 _977_t1;
    int64_t _977_t3;
    uint8_t _977_t2;
    int64_t _977_t0;
    int64_t _977_$retval;
    _977_t1 = _982_f;
    _977_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-neq.orng:3:10:\n    if f(4) {\n        ^";
    _977_t2 = _977_t1(_977_t3);
    $line_idx--;
    if (_977_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _977_t0 = 0;
    goto BB4;
BB5:
    _977_t0 = 223;
    goto BB4;
BB4:
    _977_$retval = _977_t0;
    return _977_$retval;
}

uint8_t _982_f(int64_t _982_x){
    uint8_t _982_$retval;
    (void)_982_x;
    _982_$retval = 0;
    return _982_$retval;
}

int main(void) {
  printf("%ld",_977_main());
  return 0;
}
