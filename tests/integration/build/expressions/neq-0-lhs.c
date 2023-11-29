/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _581_main(void);
int64_t _583_f(int64_t _583_x);

/* Function definitions */
int64_t _581_main(void) {
    function0 _581_t0;
    int64_t _581_t2;
    int64_t _581_t1;
    int64_t _581_$retval;
    _581_t0 = _583_f;
    _581_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _581_t1 = _581_t0(_581_t2);
    $line_idx--;
    _581_$retval = _581_t1;
    return _581_$retval;
}

int64_t _583_f(int64_t _583_x) {
    int64_t _583_t1;
    uint8_t _583_t2;
    int64_t _583_t0;
    int64_t _583_$retval;
    _583_t1 = 0;
    _583_t2 = _583_t1 != _583_x;
    if (_583_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _583_t0 = 174;
    goto BB4;
BB5:
    _583_t0 = 3;
    goto BB4;
BB4:
    _583_$retval = _583_t0;
    return _583_$retval;
}

int main(void) {
  printf("%ld",_581_main());
  return 0;
}
