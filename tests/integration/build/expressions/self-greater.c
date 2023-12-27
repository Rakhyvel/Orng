/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _829_main(void);
uint8_t _834_f(int64_t _834_x);

/* Function definitions */
int64_t _829_main(void){
    function0 _829_t1;
    int64_t _829_t3;
    uint8_t _829_t2;
    int64_t _829_t0;
    int64_t _829_$retval;
    _829_t1 = _834_f;
    _829_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _829_t2 = _829_t1(_829_t3);
    $line_idx--;
    if (_829_t2) {
        goto BB1048;
    } else {
        goto BB1052;
    }
BB1048:
    _829_t0 = 0;
    goto BB1051;
BB1052:
    _829_t0 = 224;
    goto BB1051;
BB1051:
    _829_$retval = _829_t0;
    return _829_$retval;
}

uint8_t _834_f(int64_t _834_x){
    uint8_t _834_$retval;
    (void)_834_x;
    _834_$retval = 0;
    return _834_$retval;
}

int main(void) {
  printf("%ld",_829_main());
  return 0;
}
