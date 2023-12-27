/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _619_main(void);
uint8_t _624_f(int64_t _624_x);

/* Function definitions */
int64_t _619_main(void){
    function0 _619_t1;
    int64_t _619_t3;
    uint8_t _619_t2;
    int64_t _619_t0;
    int64_t _619_$retval;
    _619_t1 = _624_f;
    _619_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _619_t2 = _619_t1(_619_t3);
    $line_idx--;
    if (_619_t2) {
        goto BB774;
    } else {
        goto BB778;
    }
BB774:
    _619_t0 = 182;
    goto BB777;
BB778:
    _619_t0 = 4;
    goto BB777;
BB777:
    _619_$retval = _619_t0;
    return _619_$retval;
}

uint8_t _624_f(int64_t _624_x){
    uint8_t _624_$retval;
    (void)_624_x;
    _624_$retval = 1;
    return _624_$retval;
}

int main(void) {
  printf("%ld",_619_main());
  return 0;
}
