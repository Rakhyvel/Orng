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
int64_t _1621_main(void);
int64_t _1623_f(uint8_t _1623_b);

/* Function definitions */
int64_t _1621_main(void){
    int64_t _1622_x;
    int64_t* _1622_y;
    function0 _1621_t2;
    int64_t _1621_t4;
    uint8_t _1621_t6;
    uint8_t _1621_t5;
    uint8_t _1621_t7;
    int64_t _1621_t3;
    int64_t _1621_$retval;
    _1622_x = 0;
    _1622_y = &_1622_x;
    _1621_t2 = _1623_f;
    _1621_t4 = 1;
    _1621_t6 = *_1622_y==_1621_t4;
    if (_1621_t6) {
        goto BB1933;
    } else {
        goto BB1936;
    }
BB1933:
    _1621_t5 = 1;
    goto BB1934;
BB1936:
    _1621_t5 = 0;
    goto BB1934;
BB1934:
    _1621_t7 = !_1621_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1621_t3 = _1621_t2(_1621_t7);
    $line_idx--;
    _1621_$retval = _1621_t3;
    return _1621_$retval;
}

int64_t _1623_f(uint8_t _1623_b){
    uint8_t _1623_t0;
    uint8_t _1623_t1;
    int64_t _1623_t2;
    int64_t _1623_$retval;
    _1623_t0 = !_1623_b;
    _1623_b = _1623_t0;
    _1623_t1 = !_1623_t0;
    _1623_b = _1623_t1;
    if (_1623_t0) {
        goto BB1930;
    } else {
        goto BB1926;
    }
BB1930:
    _1623_t2 = 10;
    goto BB1929;
BB1926:
    _1623_t2 = 31;
    goto BB1929;
BB1929:
    _1623_$retval = _1623_t2;
    return _1623_$retval;
}

int main(void) {
  printf("%ld",_1621_main());
  return 0;
}
