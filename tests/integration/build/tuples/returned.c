/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _30_main(void);
struct1 _32_f(void);

/* Function definitions */
int64_t _30_main(void) {
    function0 _30_t0;
    struct1 _30_t1;
    int64_t _30_$retval;
    _30_t0 = _32_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _30_t1 = _30_t0();
    $line_idx--;
    _30_$retval = _30_t1._1;
    return _30_$retval;
}

struct1 _32_f(void) {
    int64_t _32_t1;
    int64_t _32_t2;
    struct1 _32_$retval;
    _32_t1 = 45;
    _32_t2 = 221;
    _32_$retval = (struct1) {_32_t1, _32_t2};
    return _32_$retval;
}

int main(void) {
  printf("%ld",_30_main());
  return 0;
}
