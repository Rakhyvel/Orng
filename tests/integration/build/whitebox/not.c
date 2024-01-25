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
int64_t _1728_main(void);
int64_t _1730_f(uint8_t _1730_b);


/* Function definitions */
int64_t _1728_main(void){
    int64_t _1729_x;
    int64_t* _1729_y;
    function0 _1728_t2;
    int64_t _1728_t4;
    uint8_t _1728_t6;
    uint8_t _1728_t5;
    uint8_t _1728_t7;
    int64_t _1728_t3;
    int64_t _1728_$retval;
    _1729_x = 0;
    _1729_y = &_1729_x;
    _1728_t2 = _1730_f;
    _1728_t4 = 1;
    _1728_t6 = *_1729_y==_1728_t4;
    if (_1728_t6) {
        goto BB2010;
    } else {
        goto BB2013;
    }
BB2010:
    _1728_t5 = 1;
    goto BB2011;
BB2013:
    _1728_t5 = 0;
    goto BB2011;
BB2011:
    _1728_t7 = !_1728_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1728_t3 = _1728_t2(_1728_t7);
    $line_idx--;
    _1728_$retval = _1728_t3;
    return _1728_$retval;
}

int64_t _1730_f(uint8_t _1730_b){
    uint8_t _1730_t0;
    uint8_t _1730_t1;
    int64_t _1730_t2;
    int64_t _1730_$retval;
    _1730_t0 = !_1730_b;
    _1730_b = _1730_t0;
    _1730_t1 = !_1730_t0;
    _1730_b = _1730_t1;
    if (_1730_t0) {
        goto BB2007;
    } else {
        goto BB2003;
    }
BB2007:
    _1730_t2 = 10;
    goto BB2006;
BB2003:
    _1730_t2 = 31;
    goto BB2006;
BB2006:
    _1730_$retval = _1730_t2;
    return _1730_$retval;
}


int main(void) {
  printf("%ld",_1728_main());
  return 0;
}
