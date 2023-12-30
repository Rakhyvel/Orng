/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1616_main(void);
int64_t _1618_f(uint8_t _1618_b);

/* Function definitions */
int64_t _1616_main(void){
    int64_t _1617_x;
    int64_t* _1617_y;
    function0 _1616_t2;
    int64_t _1616_t4;
    uint8_t _1616_t6;
    uint8_t _1616_t5;
    uint8_t _1616_t7;
    int64_t _1616_t3;
    int64_t _1616_$retval;
    _1617_x = 0;
    _1617_y = &_1617_x;
    _1616_t2 = _1618_f;
    _1616_t4 = 1;
    _1616_t6 = *_1617_y==_1616_t4;
    if (_1616_t6) {
        goto BB1929;
    } else {
        goto BB1932;
    }
BB1929:
    _1616_t5 = 1;
    goto BB1930;
BB1932:
    _1616_t5 = 0;
    goto BB1930;
BB1930:
    _1616_t7 = !_1616_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1616_t3 = _1616_t2(_1616_t7);
    $line_idx--;
    _1616_$retval = _1616_t3;
    return _1616_$retval;
}

int64_t _1618_f(uint8_t _1618_b){
    uint8_t _1618_t0;
    uint8_t _1618_t1;
    int64_t _1618_t2;
    int64_t _1618_$retval;
    _1618_t0 = !_1618_b;
    _1618_b = _1618_t0;
    _1618_t1 = !_1618_t0;
    _1618_b = _1618_t1;
    if (_1618_t0) {
        goto BB1926;
    } else {
        goto BB1922;
    }
BB1926:
    _1618_t2 = 10;
    goto BB1925;
BB1922:
    _1618_t2 = 31;
    goto BB1925;
BB1925:
    _1618_$retval = _1618_t2;
    return _1618_$retval;
}

int main(void) {
  printf("%ld",_1616_main());
  return 0;
}
