/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _509_main(void);
int64_t _511_f(int64_t _511_x);

/* Function definitions */
int64_t _509_main(void) {
    function0 _509_t0;
    int64_t _509_t2;
    int64_t _509_t1;
    int64_t _509_$retval;
    _509_t0 = _511_f;
    _509_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-lhs.orng:3:7:\n    f(1)\n     ^";
    _509_t1 = _509_t0(_509_t2);
    $line_idx--;
    _509_$retval = _509_t1;
    return _509_$retval;
}

int64_t _511_f(int64_t _511_x) {
    int64_t _511_t1;
    uint8_t _511_t2;
    int64_t _511_t0;
    int64_t _511_$retval;
    _511_t1 = 0;
    _511_t2 = _511_t1 != _511_x;
    if (_511_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _511_t0 = 174;
    goto BB4;
BB5:
    _511_t0 = 3;
    goto BB4;
BB4:
    _511_$retval = _511_t0;
    return _511_$retval;
}

int main(void) {
  printf("%ld",_509_main());
  return 0;
}
