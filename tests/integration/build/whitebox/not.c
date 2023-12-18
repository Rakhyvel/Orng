/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1869_main(void);
int64_t _1871_f(uint8_t _1871_b);

/* Function definitions */
int64_t _1869_main(void){
    int64_t _1870_x;
    int64_t* _1870_y;
    function0 _1869_t2;
    int64_t _1869_t4;
    uint8_t _1869_t6;
    uint8_t _1869_t5;
    uint8_t _1869_t7;
    int64_t _1869_t3;
    int64_t _1869_$retval;
    _1870_x = 0;
    _1870_y = &_1870_x;
    _1869_t2 = _1871_f;
    _1869_t4 = 1;
    _1869_t6 = *_1870_y == _1869_t4;
    if (_1869_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1869_t5 = 1;
    goto BB2;
BB4:
    _1869_t5 = 0;
    goto BB2;
BB2:
    _1869_t7 = !_1869_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1869_t3 = _1869_t2(_1869_t7);
    $line_idx--;
    _1869_$retval = _1869_t3;
    return _1869_$retval;
}

int64_t _1871_f(uint8_t _1871_b){
    uint8_t _1871_t0;
    uint8_t _1871_t1;
    int64_t _1871_t2;
    int64_t _1871_$retval;
    _1871_t0 = !_1871_b;
    _1871_b = _1871_t0;
    _1871_t1 = !_1871_t0;
    _1871_b = _1871_t1;
    if (_1871_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1871_t2 = 10;
    goto BB4;
BB1:
    _1871_t2 = 31;
    goto BB4;
BB4:
    _1871_$retval = _1871_t2;
    return _1871_$retval;
}

int main(void) {
  printf("%ld",_1869_main());
  return 0;
}
