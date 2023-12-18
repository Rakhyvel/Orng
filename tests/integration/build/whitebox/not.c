/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1881_main(void);
int64_t _1883_f(uint8_t _1883_b);

/* Function definitions */
int64_t _1881_main(void){
    int64_t _1882_x;
    int64_t* _1882_y;
    function0 _1881_t2;
    int64_t _1881_t4;
    uint8_t _1881_t6;
    uint8_t _1881_t5;
    uint8_t _1881_t7;
    int64_t _1881_t3;
    int64_t _1881_$retval;
    _1882_x = 0;
    _1882_y = &_1882_x;
    _1881_t2 = _1883_f;
    _1881_t4 = 1;
    _1881_t6 = *_1882_y == _1881_t4;
    if (_1881_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1881_t5 = 1;
    goto BB2;
BB4:
    _1881_t5 = 0;
    goto BB2;
BB2:
    _1881_t7 = !_1881_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1881_t3 = _1881_t2(_1881_t7);
    $line_idx--;
    _1881_$retval = _1881_t3;
    return _1881_$retval;
}

int64_t _1883_f(uint8_t _1883_b){
    uint8_t _1883_t0;
    uint8_t _1883_t1;
    int64_t _1883_t2;
    int64_t _1883_$retval;
    _1883_t0 = !_1883_b;
    _1883_b = _1883_t0;
    _1883_t1 = !_1883_t0;
    _1883_b = _1883_t1;
    if (_1883_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1883_t2 = 10;
    goto BB4;
BB1:
    _1883_t2 = 31;
    goto BB4;
BB4:
    _1883_$retval = _1883_t2;
    return _1883_$retval;
}

int main(void) {
  printf("%ld",_1881_main());
  return 0;
}
