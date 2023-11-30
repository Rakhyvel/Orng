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
int64_t _523_main(void);
uint8_t _528_addr_equal(int64_t* _528_x,int64_t* _528_y);

/* Function definitions */
int64_t _523_main(void) {
    int64_t _524_x;
    int64_t _524_y;
    function0 _523_t4;
    int64_t* _523_t6;
    int64_t* _523_t7;
    uint8_t _523_t5;
    function0 _523_t8;
    int64_t* _523_t10;
    int64_t* _523_t11;
    uint8_t _523_t9;
    int64_t _523_t2;
    int64_t _523_$retval;
    _524_x = 4;
    _524_y = 4;
    _523_t4 = _528_addr_equal;
    _523_t6 = &_524_x;
    _523_t7 = &_524_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _523_t5 = _523_t4(_523_t6, _523_t7);
    $line_idx--;
    if (_523_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _523_t8 = _528_addr_equal;
    _523_t10 = &_524_x;
    _523_t11 = &_524_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _523_t9 = _523_t8(_523_t10, _523_t11);
    $line_idx--;
    if (_523_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _523_t2 = -3;
    goto BB6;
BB3:
    _523_t2 = 236;
    goto BB6;
BB6:
    _523_$retval = _523_t2;
    return _523_$retval;
}

uint8_t _528_addr_equal(int64_t* _528_x,int64_t* _528_y) {
    uint8_t _528_t1;
    uint8_t _528_t0;
    uint8_t _528_$retval;
    _528_t1 = _528_x == _528_y;
    if (_528_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _528_t0 = 1;
    goto BB3;
BB4:
    _528_t0 = 0;
    goto BB3;
BB3:
    _528_$retval = _528_t0;
    return _528_$retval;
}

int main(void) {
  printf("%ld",_523_main());
  return 0;
}
