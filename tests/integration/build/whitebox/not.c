/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1591_main(void);
int64_t _1593_f(uint8_t _1593_b);

/* Function definitions */
int64_t _1591_main(void){
    int64_t _1592_x;
    int64_t* _1592_y;
    function0 _1591_t2;
    int64_t _1591_t4;
    uint8_t _1591_t6;
    uint8_t _1591_t5;
    uint8_t _1591_t7;
    int64_t _1591_t3;
    int64_t _1591_$retval;
    _1592_x = 0;
    _1592_y = &_1592_x;
    _1591_t2 = _1593_f;
    _1591_t4 = 1;
    _1591_t6 = *_1592_y==_1591_t4;
    if (_1591_t6) {
        goto BB1946;
    } else {
        goto BB1949;
    }
BB1946:
    _1591_t5 = 1;
    goto BB1947;
BB1949:
    _1591_t5 = 0;
    goto BB1947;
BB1947:
    _1591_t7 = !_1591_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1591_t3 = _1591_t2(_1591_t7);
    $line_idx--;
    _1591_$retval = _1591_t3;
    return _1591_$retval;
}

int64_t _1593_f(uint8_t _1593_b){
    uint8_t _1593_t0;
    uint8_t _1593_t1;
    int64_t _1593_t2;
    int64_t _1593_$retval;
    _1593_t0 = !_1593_b;
    _1593_b = _1593_t0;
    _1593_t1 = !_1593_t0;
    _1593_b = _1593_t1;
    if (_1593_t0) {
        goto BB1943;
    } else {
        goto BB1939;
    }
BB1943:
    _1593_t2 = 10;
    goto BB1942;
BB1939:
    _1593_t2 = 31;
    goto BB1942;
BB1942:
    _1593_$retval = _1593_t2;
    return _1593_$retval;
}

int main(void) {
  printf("%ld",_1591_main());
  return 0;
}
