/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1695_main(void);
int64_t _1697_f(uint8_t _1697_b);

/* Function definitions */
int64_t _1695_main(void){
    int64_t _1696_x;
    int64_t* _1696_y;
    function0 _1695_t2;
    int64_t _1695_t4;
    uint8_t _1695_t6;
    uint8_t _1695_t5;
    uint8_t _1695_t7;
    int64_t _1695_t3;
    int64_t _1695_$retval;
    _1696_x = 0;
    _1696_y = &_1696_x;
    _1695_t2 = _1697_f;
    _1695_t4 = 1;
    _1695_t6 = *_1696_y == _1695_t4;
    if (_1695_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1695_t5 = 1;
    goto BB2;
BB4:
    _1695_t5 = 0;
    goto BB2;
BB2:
    _1695_t7 = !_1695_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1695_t3 = _1695_t2(_1695_t7);
    $line_idx--;
    _1695_$retval = _1695_t3;
    return _1695_$retval;
}

int64_t _1697_f(uint8_t _1697_b){
    uint8_t _1697_t0;
    uint8_t _1697_t1;
    int64_t _1697_t2;
    int64_t _1697_$retval;
    _1697_t0 = !_1697_b;
    _1697_b = _1697_t0;
    _1697_t1 = !_1697_t0;
    _1697_b = _1697_t1;
    if (_1697_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1697_t2 = 10;
    goto BB4;
BB1:
    _1697_t2 = 31;
    goto BB4;
BB4:
    _1697_$retval = _1697_t2;
    return _1697_$retval;
}

int main(void) {
  printf("%ld",_1695_main());
  return 0;
}
