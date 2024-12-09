/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _802_main(void);
int64_t _804_f(int64_t _804_x);


/* Function definitions */
int64_t _802_main(void){
    function0 _802_t0;
    int64_t _802_t2;
    int64_t _802_t1;
    int64_t _802_$retval;
    _802_t0 = (function0) _804_f;
    _802_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _802_t1 = _802_t0(_802_t2);
    $line_idx--;
    _802_$retval = _802_t1;
    return _802_$retval;
}

int64_t _804_f(int64_t _804_x){
    int64_t _804_t1;
    uint8_t _804_t3;
    int64_t _804_t0;
    int64_t _804_$retval;
    _804_t1 = 0;
    _804_t3 = _804_x==_804_t1;
    if (_804_t3) {
        goto BB973;
    } else {
        goto BB969;
    }
BB973:
    _804_t0 = 3;
    goto BB972;
BB969:
    _804_t0 = 173;
    goto BB972;
BB972:
    _804_$retval = _804_t0;
    return _804_$retval;
}


int main(void) {
  printf("%ld",_802_main());
  return 0;
}
