/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _861_main(void);
uint8_t _866_f(int64_t _866_x);

/* Function definitions */
int64_t _861_main(void){
    function0 _861_t1;
    int64_t _861_t3;
    uint8_t _861_t2;
    int64_t _861_t0;
    int64_t _861_$retval;
    _861_t1 = _866_f;
    _861_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-greater.orng:3:10:\n    if f(4) {\n        ^";
    _861_t2 = _861_t1(_861_t3);
    $line_idx--;
    if (_861_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _861_t0 = 0;
    goto BB4;
BB5:
    _861_t0 = 224;
    goto BB4;
BB4:
    _861_$retval = _861_t0;
    return _861_$retval;
}

uint8_t _866_f(int64_t _866_x){
    uint8_t _866_$retval;
    (void)_866_x;
    _866_$retval = 0;
    return _866_$retval;
}

int main(void) {
  printf("%ld",_861_main());
  return 0;
}
