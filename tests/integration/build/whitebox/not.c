/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1701_main(void);
int64_t _1703_f(uint8_t _1703_b);


/* Function definitions */
int64_t _1701_main(void){
    int64_t _1702_x;
    int64_t* _1702_y;
    function0 _1701_t2;
    int64_t _1701_t4;
    uint8_t _1701_t6;
    uint8_t _1701_t5;
    uint8_t _1701_t7;
    int64_t _1701_t3;
    int64_t _1701_$retval;
    _1702_x = 0;
    _1702_y = &_1702_x;
    _1701_t2 = _1703_f;
    _1701_t4 = 1;
    _1701_t6 = *_1702_y==_1701_t4;
    if (_1701_t6) {
        goto BB1988;
    } else {
        goto BB1991;
    }
BB1988:
    _1701_t5 = 1;
    goto BB1989;
BB1991:
    _1701_t5 = 0;
    goto BB1989;
BB1989:
    _1701_t7 = !_1701_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1701_t3 = _1701_t2(_1701_t7);
    $line_idx--;
    _1701_$retval = _1701_t3;
    return _1701_$retval;
}

int64_t _1703_f(uint8_t _1703_b){
    uint8_t _1703_t0;
    uint8_t _1703_t1;
    int64_t _1703_t2;
    int64_t _1703_$retval;
    _1703_t0 = !_1703_b;
    _1703_b = _1703_t0;
    _1703_t1 = !_1703_t0;
    _1703_b = _1703_t1;
    if (_1703_t0) {
        goto BB1985;
    } else {
        goto BB1981;
    }
BB1985:
    _1703_t2 = 10;
    goto BB1984;
BB1981:
    _1703_t2 = 31;
    goto BB1984;
BB1984:
    _1703_$retval = _1703_t2;
    return _1703_$retval;
}


int main(void) {
  printf("%ld",_1701_main());
  return 0;
}
