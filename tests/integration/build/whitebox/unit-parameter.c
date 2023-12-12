/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1306_main(void);
int64_t _1308_f(int64_t _1308_x);

/* Function definitions */
int64_t _1306_main(void) {
    function0 _1306_t0;
    int64_t _1306_t3;
    int64_t _1306_t1;
    int64_t _1306_$retval;
    _1306_t0 = _1308_f;
    _1306_t3 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1306_t1 = _1306_t0(_1306_t3);
    $line_idx--;
    _1306_$retval = _1306_t1;
    return _1306_$retval;
}

int64_t _1308_f(int64_t _1308_x) {
    int64_t _1308_$retval;
    _1308_$retval = _1308_x;
    return _1308_$retval;
}

int main(void) {
  printf("%ld",_1306_main());
  return 0;
}
