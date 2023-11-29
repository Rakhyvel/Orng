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
int64_t _33_main(void);
struct1 _35_f(void);

/* Function definitions */
int64_t _33_main(void) {
    function0 _33_t0;
    struct1 _33_t1;
    int64_t _33_$retval;
    _33_t0 = _35_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _33_t1 = _33_t0();
    $line_idx--;
    _33_$retval = _33_t1._1;
    return _33_$retval;
}

struct1 _35_f(void) {
    int64_t _35_t1;
    int64_t _35_t2;
    struct1 _35_$retval;
    _35_t1 = 45;
    _35_t2 = 221;
    _35_$retval = (struct1) {_35_t1, _35_t2};
    return _35_$retval;
}

int main(void) {
  printf("%ld",_33_main());
  return 0;
}
