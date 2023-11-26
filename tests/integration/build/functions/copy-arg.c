/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _598_main(void);
int64_t _600_g(int64_t _600_x);
int64_t _602_f(int64_t _602_x);

/* Function definitions */
int64_t _598_main(void) {
    function0 _598_t0;
    int64_t _598_t2;
    int64_t _598_t1;
    int64_t _598_$retval;
    _598_t0 = _600_g;
    _598_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _598_t1 = _598_t0(_598_t2);
    $line_idx--;
    _598_$retval = _598_t1;
    return _598_$retval;
}

int64_t _600_g(int64_t _600_x) {
    int64_t _601_z;
    function0 _600_t0;
    int64_t _600_t1;
    int64_t _600_$retval;
    _601_z = _600_x;
    _600_t0 = _602_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _600_t1 = _600_t0(_601_z);
    $line_idx--;
    _600_$retval = _600_t1;
    return _600_$retval;
}

int64_t _602_f(int64_t _602_x) {
    int64_t _602_$retval;
    _602_$retval = _602_x;
    return _602_$retval;
}

int main(void) {
  printf("%ld",_598_main());
  return 0;
}
