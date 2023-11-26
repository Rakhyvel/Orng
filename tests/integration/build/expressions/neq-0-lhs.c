/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _478_main(void);
int64_t _480_f(int64_t _480_x);

/* Function definitions */
int64_t _478_main(void) {
    function0 _478_t0;
    int64_t _478_t2;
    int64_t _478_t1;
    int64_t _478_$retval;
    _478_t0 = _480_f;
    _478_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _478_t1 = _478_t0(_478_t2);
    $line_idx--;
    _478_$retval = _478_t1;
    return _478_$retval;
}

int64_t _480_f(int64_t _480_x) {
    int64_t _480_t1;
    uint8_t _480_t2;
    int64_t _480_t0;
    int64_t _480_$retval;
    _480_t1 = 0;
    _480_t2 = _480_t1 != _480_x;
    if (_480_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _480_t0 = 174;
    goto BB4;
BB5:
    _480_t0 = 3;
    goto BB4;
BB4:
    _480_$retval = _480_t0;
    return _480_$retval;
}

int main(void) {
  printf("%ld",_478_main());
  return 0;
}
