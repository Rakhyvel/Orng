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
int64_t _385_main(void);
uint8_t _390_addr_equal(int64_t* _390_x,int64_t* _390_y);

/* Function definitions */
int64_t _385_main(void) {
    int64_t _386_x;
    int64_t _386_y;
    function0 _385_t4;
    int64_t* _385_t6;
    int64_t* _385_t7;
    uint8_t _385_t5;
    function0 _385_t8;
    int64_t* _385_t10;
    int64_t* _385_t11;
    uint8_t _385_t9;
    int64_t _385_t2;
    int64_t _385_$retval;
    _386_x = 4;
    _386_y = 4;
    _385_t4 = _390_addr_equal;
    _385_t6 = &_386_x;
    _385_t7 = &_386_x;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:19:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                 ^";
    _385_t5 = _385_t4(_385_t6, _385_t7);
    $line_idx--;
    if (_385_t5) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _385_t8 = _390_addr_equal;
    _385_t10 = &_386_x;
    _385_t11 = &_386_y;
    $lines[$line_idx++] = "tests/integration/expressions/addr-eq.orng:5:46:\n    if addr_equal(&x, &x) and not addr_equal(&x, &y) {\n                                            ^";
    _385_t9 = _385_t8(_385_t10, _385_t11);
    $line_idx--;
    if (_385_t9) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _385_t2 = -3;
    goto BB6;
BB3:
    _385_t2 = 236;
    goto BB6;
BB6:
    _385_$retval = _385_t2;
    return _385_$retval;
}

uint8_t _390_addr_equal(int64_t* _390_x,int64_t* _390_y) {
    uint8_t _390_t1;
    uint8_t _390_t0;
    uint8_t _390_$retval;
    _390_t1 = _390_x == _390_y;
    if (_390_t1) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _390_t0 = 1;
    goto BB3;
BB4:
    _390_t0 = 0;
    goto BB3;
BB3:
    _390_$retval = _390_t0;
    return _390_$retval;
}

int main(void) {
  printf("%ld",_385_main());
  return 0;
}
