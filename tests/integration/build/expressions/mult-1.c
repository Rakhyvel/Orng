/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _751_main(void);
uint8_t _756_f(int64_t _756_x);

/* Function definitions */
int64_t _751_main(void){
    function0 _751_t1;
    int64_t _751_t3;
    uint8_t _751_t2;
    int64_t _751_t0;
    int64_t _751_$retval;
    _751_t1 = _756_f;
    _751_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _751_t2 = _751_t1(_751_t3);
    $line_idx--;
    if (_751_t2) {
        goto BB933;
    } else {
        goto BB937;
    }
BB933:
    _751_t0 = 186;
    goto BB936;
BB937:
    _751_t0 = 4;
    goto BB936;
BB936:
    _751_$retval = _751_t0;
    return _751_$retval;
}

uint8_t _756_f(int64_t _756_x){
    uint8_t _756_$retval;
    (void)_756_x;
    _756_$retval = 1;
    return _756_$retval;
}

int main(void) {
  printf("%ld",_751_main());
  return 0;
}
