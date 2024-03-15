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
int64_t _834_main(void);
uint8_t _839_f(int64_t _839_x);


/* Function definitions */
int64_t _834_main(void){
    function0 _834_t1;
    int64_t _834_t3;
    uint8_t _834_t2;
    int64_t _834_t0;
    int64_t _834_$retval;
    _834_t1 = (function0) _839_f;
    _834_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _834_t2 = _834_t1(_834_t3);
    $line_idx--;
    if (_834_t2) {
        goto BB1010;
    } else {
        goto BB1014;
    }
BB1010:
    _834_t0 = 0;
    goto BB1013;
BB1014:
    _834_t0 = 224;
    goto BB1013;
BB1013:
    _834_$retval = _834_t0;
    return _834_$retval;
}

uint8_t _839_f(int64_t _839_x){
    uint8_t _839_$retval;
    (void)_839_x;
    _839_$retval = 0;
    return _839_$retval;
}


int main(void) {
  printf("%ld",_834_main());
  return 0;
}
