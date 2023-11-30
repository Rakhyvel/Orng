/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _834_main(void);
int64_t _836_g(int64_t _836_x);
int64_t _839_f(int64_t _839_x);

/* Function definitions */
int64_t _834_main(void) {
    function0 _834_t0;
    int64_t _834_t2;
    int64_t _834_t1;
    int64_t _834_$retval;
    _834_t0 = _836_g;
    _834_t2 = 194;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    _834_t1 = _834_t0(_834_t2);
    $line_idx--;
    _834_$retval = _834_t1;
    return _834_$retval;
}

int64_t _836_g(int64_t _836_x) {
    int64_t _838_z;
    function0 _836_t0;
    int64_t _836_t1;
    int64_t _836_$retval;
    _838_z = _836_x;
    _836_t0 = _839_f;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    _836_t1 = _836_t0(_838_z);
    $line_idx--;
    _836_$retval = _836_t1;
    return _836_$retval;
}

int64_t _839_f(int64_t _839_x) {
    int64_t _839_$retval;
    _839_$retval = _839_x;
    return _839_$retval;
}

int main(void) {
  printf("%ld",_834_main());
  return 0;
}
