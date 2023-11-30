/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _687_main(void);
uint8_t _692_f(int64_t _692_x);

/* Function definitions */
int64_t _687_main(void) {
    function0 _687_t1;
    int64_t _687_t3;
    uint8_t _687_t2;
    int64_t _687_t0;
    int64_t _687_$retval;
    _687_t1 = _692_f;
    _687_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-1.orng:3:10:\n    if f(4) {\n        ^";
    _687_t2 = _687_t1(_687_t3);
    $line_idx--;
    if (_687_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _687_t0 = 186;
    goto BB4;
BB5:
    _687_t0 = 4;
    goto BB4;
BB4:
    _687_$retval = _687_t0;
    return _687_$retval;
}

uint8_t _692_f(int64_t _692_x) {
    uint8_t _692_$retval;
    (void)_692_x;
    _692_$retval = 1;
    return _692_$retval;
}

int main(void) {
  printf("%ld",_687_main());
  return 0;
}
