/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _875_main(void);
uint8_t _880_f(int64_t _880_x);

/* Function definitions */
int64_t _875_main(void){
    function0 _875_t1;
    int64_t _875_t3;
    uint8_t _875_t2;
    int64_t _875_t0;
    int64_t _875_$retval;
    _875_t1 = _880_f;
    _875_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _875_t2 = _875_t1(_875_t3);
    $line_idx--;
    if (_875_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _875_t0 = 186;
    goto BB4;
BB5:
    _875_t0 = 4;
    goto BB4;
BB4:
    _875_$retval = _875_t0;
    return _875_$retval;
}

uint8_t _880_f(int64_t _880_x){
    uint8_t _880_$retval;
    (void)_880_x;
    _880_$retval = 1;
    return _880_$retval;
}

int main(void) {
  printf("%ld",_875_main());
  return 0;
}
