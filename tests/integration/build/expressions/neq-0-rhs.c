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
int64_t _804_main(void);
int64_t _806_f(int64_t _806_x);


/* Function definitions */
int64_t _804_main(void){
    function0 _804_t0;
    int64_t _804_t2;
    int64_t _804_t1;
    int64_t _804_$retval;
    _804_t0 = _806_f;
    _804_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _804_t1 = _804_t0(_804_t2);
    $line_idx--;
    _804_$retval = _804_t1;
    return _804_$retval;
}

int64_t _806_f(int64_t _806_x){
    int64_t _806_t1;
    uint8_t _806_t3;
    int64_t _806_t0;
    int64_t _806_$retval;
    _806_t1 = 0;
    _806_t3 = _806_x==_806_t1;
    if (_806_t3) {
        goto BB1008;
    } else {
        goto BB1004;
    }
BB1008:
    _806_t0 = 3;
    goto BB1007;
BB1004:
    _806_t0 = 173;
    goto BB1007;
BB1007:
    _806_$retval = _806_t0;
    return _806_$retval;
}


int main(void) {
  printf("%ld",_804_main());
  return 0;
}
