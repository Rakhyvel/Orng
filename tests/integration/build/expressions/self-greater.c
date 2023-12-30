/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _841_main(void);
uint8_t _846_f(int64_t _846_x);

/* Function definitions */
int64_t _841_main(void){
    function0 _841_t1;
    int64_t _841_t3;
    uint8_t _841_t2;
    int64_t _841_t0;
    int64_t _841_$retval;
    _841_t1 = _846_f;
    _841_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _841_t2 = _841_t1(_841_t3);
    $line_idx--;
    if (_841_t2) {
        goto BB1058;
    } else {
        goto BB1062;
    }
BB1058:
    _841_t0 = 0;
    goto BB1061;
BB1062:
    _841_t0 = 224;
    goto BB1061;
BB1061:
    _841_$retval = _841_t0;
    return _841_$retval;
}

uint8_t _846_f(int64_t _846_x){
    uint8_t _846_$retval;
    (void)_846_x;
    _846_$retval = 0;
    return _846_$retval;
}

int main(void) {
  printf("%ld",_841_main());
  return 0;
}
