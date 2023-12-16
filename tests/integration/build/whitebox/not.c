/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1624_main(void);
int64_t _1626_f(uint8_t _1626_b);

/* Function definitions */
int64_t _1624_main(void){
    int64_t _1625_x;
    int64_t* _1625_y;
    function0 _1624_t2;
    int64_t _1624_t4;
    uint8_t _1624_t6;
    uint8_t _1624_t5;
    uint8_t _1624_t7;
    int64_t _1624_t3;
    int64_t _1624_$retval;
    _1625_x = 0;
    _1625_y = &_1625_x;
    _1624_t2 = _1626_f;
    _1624_t4 = 1;
    _1624_t6 = *_1625_y == _1624_t4;
    if (_1624_t6) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _1624_t5 = 1;
    goto BB2;
BB4:
    _1624_t5 = 0;
    goto BB2;
BB2:
    _1624_t7 = !_1624_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1624_t3 = _1624_t2(_1624_t7);
    $line_idx--;
    _1624_$retval = _1624_t3;
    return _1624_$retval;
}

int64_t _1626_f(uint8_t _1626_b){
    uint8_t _1626_t0;
    uint8_t _1626_t1;
    int64_t _1626_t2;
    int64_t _1626_$retval;
    _1626_t0 = !_1626_b;
    _1626_b = _1626_t0;
    _1626_t1 = !_1626_t0;
    _1626_b = _1626_t1;
    if (_1626_t0) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1626_t2 = 10;
    goto BB4;
BB1:
    _1626_t2 = 31;
    goto BB4;
BB4:
    _1626_$retval = _1626_t2;
    return _1626_$retval;
}

int main(void) {
  printf("%ld",_1624_main());
  return 0;
}
