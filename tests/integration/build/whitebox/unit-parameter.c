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
int64_t _1187_main(void);
int64_t _1190_f(int64_t _1190_x);

/* Function definitions */
int64_t _1187_main(void) {
    function0 _1187_t0;
    int64_t _1187_t2;
    int64_t _1187_t1;
    int64_t _1187_$retval;
    _1187_t0 = _1190_f;
    _1187_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _1187_t1 = _1187_t0(_1187_t2);
    $line_idx--;
    _1187_$retval = _1187_t1;
    return _1187_$retval;
}

int64_t _1190_f(int64_t _1190_x) {
    int64_t _1190_$retval;
    _1190_$retval = _1190_x;
    return _1190_$retval;
}

int main(void) {
  printf("%ld",_1187_main());
  return 0;
}
