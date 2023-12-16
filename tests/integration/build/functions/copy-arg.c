/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _882_main(void);
int64_t _884_g(int64_t _884_x);
int64_t _886_f(int64_t _886_x);

/* Function definitions */
int64_t _882_main(void) {
    function0 _882_t0;
    int64_t _882_t2;
    int64_t _882_t1;
    int64_t _882_$retval;
    _882_t0 = _884_g;
    _882_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _882_t1 = _882_t0(_882_t2);
    $line_idx--;
    _882_$retval = _882_t1;
    return _882_$retval;
}

int64_t _884_g(int64_t _884_x) {
    int64_t _885_z;
    function0 _884_t0;
    int64_t _884_t1;
    int64_t _884_$retval;
    _885_z = _884_x;
    _884_t0 = _886_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _884_t1 = _884_t0(_885_z);
    $line_idx--;
    _884_$retval = _884_t1;
    return _884_$retval;
}

int64_t _886_f(int64_t _886_x) {
    int64_t _886_$retval;
    _886_$retval = _886_x;
    return _886_$retval;
}

int main(void) {
  printf("%ld",_882_main());
  return 0;
}
