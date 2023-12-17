/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t* _0;
    int64_t* _1;
} struct1;

typedef uint8_t(*function0)(int64_t*, int64_t*);

/* Function forward definitions */
int64_t _735_main(void);
uint8_t _740_addr_equal(int64_t* _740_x,int64_t* _740_y);

/* Function definitions */
int64_t _735_main(void){
    int64_t _736_x;
    int64_t _736_y;
    function0 _735_t4;
    int64_t* _735_t6;
    int64_t* _735_t7;
    uint8_t _735_t5;
    function0 _735_t8;
    int64_t* _735_t10;
    int64_t* _735_t11;
    uint8_t _735_t9;
    int64_t _735_t2;
    int64_t _735_$retval;
    _736_x = 4;
    _736_y = 4;
    _735_t4 = _740_addr_equal;
    _735_t6 = &_736_x;
    _735_t7 = &_736_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _735_t5 = _735_t4(_735_t6, _735_t7);
    $line_idx--;
    if (_735_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _735_t8 = _740_addr_equal;
    _735_t10 = &_736_x;
    _735_t11 = &_736_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _735_t9 = _735_t8(_735_t10, _735_t11);
    $line_idx--;
    if (_735_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _735_t2 = -3;
    goto BB6;
BB3:
    _735_t2 = 236;
    goto BB6;
BB6:
    _735_$retval = _735_t2;
    return _735_$retval;
}

uint8_t _740_addr_equal(int64_t* _740_x,int64_t* _740_y){
    uint8_t _740_t1;
    uint8_t _740_t0;
    uint8_t _740_$retval;
    _740_t1 = _740_x == _740_y;
    if (_740_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _740_t0 = 1;
    goto BB3;
BB4:
    _740_t0 = 0;
    goto BB3;
BB3:
    _740_$retval = _740_t0;
    return _740_$retval;
}

int main(void) {
  printf("%ld",_735_main());
  return 0;
}
