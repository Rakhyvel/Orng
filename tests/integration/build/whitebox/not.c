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
int64_t _1657_main(void);
int64_t _1659_f(uint8_t _1659_b);

/* Function definitions */
int64_t _1657_main(void){
    int64_t _1658_x;
    int64_t* _1658_y;
    function0 _1657_t2;
    int64_t _1657_t4;
    uint8_t _1657_t6;
    uint8_t _1657_t5;
    uint8_t _1657_t7;
    int64_t _1657_t3;
    int64_t _1657_$retval;
    _1658_x = 0;
    _1658_y = &_1658_x;
    _1657_t2 = _1659_f;
    _1657_t4 = 1;
    _1657_t6 = *_1658_y==_1657_t4;
    if (_1657_t6) {
        goto BB1948;
    } else {
        goto BB1951;
    }
BB1948:
    _1657_t5 = 1;
    goto BB1949;
BB1951:
    _1657_t5 = 0;
    goto BB1949;
BB1949:
    _1657_t7 = !_1657_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1657_t3 = _1657_t2(_1657_t7);
    $line_idx--;
    _1657_$retval = _1657_t3;
    return _1657_$retval;
}

int64_t _1659_f(uint8_t _1659_b){
    uint8_t _1659_t0;
    uint8_t _1659_t1;
    int64_t _1659_t2;
    int64_t _1659_$retval;
    _1659_t0 = !_1659_b;
    _1659_b = _1659_t0;
    _1659_t1 = !_1659_t0;
    _1659_b = _1659_t1;
    if (_1659_t0) {
        goto BB1945;
    } else {
        goto BB1941;
    }
BB1945:
    _1659_t2 = 10;
    goto BB1944;
BB1941:
    _1659_t2 = 31;
    goto BB1944;
BB1944:
    _1659_$retval = _1659_t2;
    return _1659_$retval;
}

int main(void) {
  printf("%ld",_1657_main());
  return 0;
}
