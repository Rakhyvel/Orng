/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _622_main(void);
uint8_t _627_f(int64_t _627_x);

/* Function definitions */
int64_t _622_main(void) {
    function0 _622_t1;
    int64_t _622_t3;
    uint8_t _622_t2;
    int64_t _622_t0;
    int64_t _622_$retval;
    _622_t1 = _627_f;
    _622_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _622_t2 = _622_t1(_622_t3);
    $line_idx--;
    if (_622_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _622_t0 = 228;
    goto BB4;
BB5:
    _622_t0 = 0;
    goto BB4;
BB4:
    _622_$retval = _622_t0;
    return _622_$retval;
}

uint8_t _627_f(int64_t _627_x) {
    uint8_t _627_$retval;
    (void)_627_x;
    _627_$retval = 1;
    return _627_$retval;
}

int main(void) {
  printf("%ld",_622_main());
  return 0;
}
