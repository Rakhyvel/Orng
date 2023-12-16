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
int64_t _650_main(void);
uint8_t _655_addr_equal(int64_t* _655_x,int64_t* _655_y);

/* Function definitions */
int64_t _650_main(void){
    int64_t _651_x;
    int64_t _651_y;
    function0 _650_t4;
    int64_t* _650_t6;
    int64_t* _650_t7;
    uint8_t _650_t5;
    function0 _650_t8;
    int64_t* _650_t10;
    int64_t* _650_t11;
    uint8_t _650_t9;
    int64_t _650_t2;
    int64_t _650_$retval;
    _651_x = 4;
    _651_y = 4;
    _650_t4 = _655_addr_equal;
    _650_t6 = &_651_x;
    _650_t7 = &_651_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _650_t5 = _650_t4(_650_t6, _650_t7);
    $line_idx--;
    if (_650_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _650_t8 = _655_addr_equal;
    _650_t10 = &_651_x;
    _650_t11 = &_651_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _650_t9 = _650_t8(_650_t10, _650_t11);
    $line_idx--;
    if (_650_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _650_t2 = -3;
    goto BB6;
BB3:
    _650_t2 = 236;
    goto BB6;
BB6:
    _650_$retval = _650_t2;
    return _650_$retval;
}

uint8_t _655_addr_equal(int64_t* _655_x,int64_t* _655_y){
    uint8_t _655_t1;
    uint8_t _655_t0;
    uint8_t _655_$retval;
    _655_t1 = _655_x == _655_y;
    if (_655_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _655_t0 = 1;
    goto BB3;
BB4:
    _655_t0 = 0;
    goto BB3;
BB3:
    _655_$retval = _655_t0;
    return _655_$retval;
}

int main(void) {
  printf("%ld",_650_main());
  return 0;
}
