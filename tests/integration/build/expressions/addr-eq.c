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
int64_t _544_main(void);
uint8_t _549_addr_equal(int64_t* _549_x,int64_t* _549_y);

/* Function definitions */
int64_t _544_main(void) {
    int64_t _545_x;
    int64_t _545_y;
    function0 _544_t4;
    int64_t* _544_t6;
    int64_t* _544_t7;
    uint8_t _544_t5;
    function0 _544_t8;
    int64_t* _544_t10;
    int64_t* _544_t11;
    uint8_t _544_t9;
    int64_t _544_t2;
    int64_t _544_$retval;
    _545_x = 4;
    _545_y = 4;
    _544_t4 = _549_addr_equal;
    _544_t6 = &_545_x;
    _544_t7 = &_545_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _544_t5 = _544_t4(_544_t6, _544_t7);
    $line_idx--;
    if (_544_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _544_t8 = _549_addr_equal;
    _544_t10 = &_545_x;
    _544_t11 = &_545_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _544_t9 = _544_t8(_544_t10, _544_t11);
    $line_idx--;
    if (_544_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _544_t2 = -3;
    goto BB6;
BB3:
    _544_t2 = 236;
    goto BB6;
BB6:
    _544_$retval = _544_t2;
    return _544_$retval;
}

uint8_t _549_addr_equal(int64_t* _549_x,int64_t* _549_y) {
    uint8_t _549_t1;
    uint8_t _549_t0;
    uint8_t _549_$retval;
    _549_t1 = _549_x == _549_y;
    if (_549_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _549_t0 = 1;
    goto BB3;
BB4:
    _549_t0 = 0;
    goto BB3;
BB3:
    _549_$retval = _549_t0;
    return _549_$retval;
}

int main(void) {
  printf("%ld",_544_main());
  return 0;
}
