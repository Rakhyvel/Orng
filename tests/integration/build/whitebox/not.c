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
int64_t _1772_main(void);
int64_t _1774_f(uint8_t _1774_b);


/* Function definitions */
int64_t _1772_main(void){
    int64_t _1773_x;
    int64_t* _1773_y;
    function0 _1772_t2;
    int64_t _1772_t4;
    uint8_t _1772_t6;
    uint8_t _1772_t5;
    uint8_t _1772_t7;
    int64_t _1772_t3;
    int64_t _1772_$retval;
    _1773_x = 0;
    _1773_y = &_1773_x;
    _1772_t2 = _1774_f;
    _1772_t4 = 1;
    _1772_t6 = *_1773_y==_1772_t4;
    if (_1772_t6) {
        goto BB2050;
    } else {
        goto BB2053;
    }
BB2050:
    _1772_t5 = 1;
    goto BB2051;
BB2053:
    _1772_t5 = 0;
    goto BB2051;
BB2051:
    _1772_t7 = !_1772_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1772_t3 = _1772_t2(_1772_t7);
    $line_idx--;
    _1772_$retval = _1772_t3;
    return _1772_$retval;
}

int64_t _1774_f(uint8_t _1774_b){
    uint8_t _1774_t0;
    uint8_t _1774_t1;
    int64_t _1774_t2;
    int64_t _1774_$retval;
    _1774_t0 = !_1774_b;
    _1774_b = _1774_t0;
    _1774_t1 = !_1774_t0;
    _1774_b = _1774_t1;
    if (_1774_t0) {
        goto BB2047;
    } else {
        goto BB2043;
    }
BB2047:
    _1774_t2 = 10;
    goto BB2046;
BB2043:
    _1774_t2 = 31;
    goto BB2046;
BB2046:
    _1774_$retval = _1774_t2;
    return _1774_$retval;
}


int main(void) {
  printf("%ld",_1772_main());
  return 0;
}
