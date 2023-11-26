/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _8_main(void);
uint8_t _13_f(int64_t _13_x);

/* Function definitions */
int64_t _8_main(void) {
    function0 _8_t1;
    int64_t _8_t3;
    uint8_t _8_t2;
    int64_t _8_t0;
    int64_t _8_$retval;
    _8_t1 = _13_f;
    _8_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _8_t2 = _8_t1(_8_t3);
    $line_idx--;
    if (_8_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _8_t0 = 182;
    goto BB4;
BB5:
    _8_t0 = 4;
    goto BB4;
BB4:
    _8_$retval = _8_t0;
    return _8_$retval;
}

uint8_t _13_f(int64_t _13_x) {
    uint8_t _13_t5;
    uint8_t _13_t4;
    uint8_t _13_$retval;
    (void)_13_x;
    _13_t5 = 1;
    if (_13_t5) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _13_t4 = 1;
    goto BB3;
BB4:
    _13_t4 = 0;
    goto BB3;
BB3:
    _13_$retval = _13_t4;
    return _13_$retval;
}

int main(void) {
  printf("%ld",_8_main());
  return 0;
}
