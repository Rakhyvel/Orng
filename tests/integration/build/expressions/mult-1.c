/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _868_main(void);
uint8_t _873_f(int64_t _873_x);

/* Function definitions */
int64_t _868_main(void){
    function0 _868_t1;
    int64_t _868_t3;
    uint8_t _868_t2;
    int64_t _868_t0;
    int64_t _868_$retval;
    _868_t1 = _873_f;
    _868_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _868_t2 = _868_t1(_868_t3);
    $line_idx--;
    if (_868_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _868_t0 = 186;
    goto BB4;
BB5:
    _868_t0 = 4;
    goto BB4;
BB4:
    _868_$retval = _868_t0;
    return _868_$retval;
}

uint8_t _873_f(int64_t _873_x){
    uint8_t _873_$retval;
    (void)_873_x;
    _873_$retval = 1;
    return _873_$retval;
}

int main(void) {
  printf("%ld",_868_main());
  return 0;
}
