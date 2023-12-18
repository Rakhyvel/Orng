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
int64_t _742_main(void);
uint8_t _747_addr_equal(int64_t* _747_x,int64_t* _747_y);

/* Function definitions */
int64_t _742_main(void){
    int64_t _743_x;
    int64_t _743_y;
    function0 _742_t4;
    int64_t* _742_t6;
    int64_t* _742_t7;
    uint8_t _742_t5;
    function0 _742_t8;
    int64_t* _742_t10;
    int64_t* _742_t11;
    uint8_t _742_t9;
    int64_t _742_t2;
    int64_t _742_$retval;
    _743_x = 4;
    _743_y = 4;
    _742_t4 = _747_addr_equal;
    _742_t6 = &_743_x;
    _742_t7 = &_743_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _742_t5 = _742_t4(_742_t6, _742_t7);
    $line_idx--;
    if (_742_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _742_t8 = _747_addr_equal;
    _742_t10 = &_743_x;
    _742_t11 = &_743_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _742_t9 = _742_t8(_742_t10, _742_t11);
    $line_idx--;
    if (_742_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _742_t2 = -3;
    goto BB6;
BB3:
    _742_t2 = 236;
    goto BB6;
BB6:
    _742_$retval = _742_t2;
    return _742_$retval;
}

uint8_t _747_addr_equal(int64_t* _747_x,int64_t* _747_y){
    uint8_t _747_t1;
    uint8_t _747_t0;
    uint8_t _747_$retval;
    _747_t1 = _747_x == _747_y;
    if (_747_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _747_t0 = 1;
    goto BB3;
BB4:
    _747_t0 = 0;
    goto BB3;
BB3:
    _747_$retval = _747_t0;
    return _747_$retval;
}

int main(void) {
  printf("%ld",_742_main());
  return 0;
}
