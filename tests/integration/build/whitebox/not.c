/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1629_main(void);
int64_t _1631_f(uint8_t _1631_b);

/* Function definitions */
int64_t _1629_main(void){
    int64_t _1630_x;
    int64_t* _1630_y;
    function0 _1629_t2;
    int64_t _1629_t4;
    uint8_t _1629_t6;
    uint8_t _1629_t5;
    uint8_t _1629_t7;
    int64_t _1629_t3;
    int64_t _1629_$retval;
    _1630_x = 0;
    _1630_y = &_1630_x;
    _1629_t2 = _1631_f;
    _1629_t4 = 1;
    _1629_t6 = *_1630_y==_1629_t4;
    if (_1629_t6) {
        goto BB1929;
    } else {
        goto BB1932;
    }
BB1929:
    _1629_t5 = 1;
    goto BB1930;
BB1932:
    _1629_t5 = 0;
    goto BB1930;
BB1930:
    _1629_t7 = !_1629_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1629_t3 = _1629_t2(_1629_t7);
    $line_idx--;
    _1629_$retval = _1629_t3;
    return _1629_$retval;
}

int64_t _1631_f(uint8_t _1631_b){
    uint8_t _1631_t0;
    uint8_t _1631_t1;
    int64_t _1631_t2;
    int64_t _1631_$retval;
    _1631_t0 = !_1631_b;
    _1631_b = _1631_t0;
    _1631_t1 = !_1631_t0;
    _1631_b = _1631_t1;
    if (_1631_t0) {
        goto BB1926;
    } else {
        goto BB1922;
    }
BB1926:
    _1631_t2 = 10;
    goto BB1925;
BB1922:
    _1631_t2 = 31;
    goto BB1925;
BB1925:
    _1631_$retval = _1631_t2;
    return _1631_$retval;
}

int main(void) {
  printf("%ld",_1629_main());
  return 0;
}
