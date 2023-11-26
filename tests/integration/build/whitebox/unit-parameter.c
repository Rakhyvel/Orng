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
int64_t _90_main(void);
int64_t _93_f(int64_t _93_x);

/* Function definitions */
int64_t _90_main(void) {
    function0 _90_t0;
    int64_t _90_t2;
    int64_t _90_t1;
    int64_t _90_$retval;
    _90_t0 = _93_f;
    _90_t2 = 219;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    _90_t1 = _90_t0(_90_t2);
    $line_idx--;
    _90_$retval = _90_t1;
    return _90_$retval;
}

int64_t _93_f(int64_t _93_x) {
    int64_t _93_$retval;
    _93_$retval = _93_x;
    return _93_$retval;
}

int main(void) {
  printf("%ld",_90_main());
  return 0;
}
