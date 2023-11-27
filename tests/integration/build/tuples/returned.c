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
int64_t _1096_main(void);
struct1 _1098_f(void);

/* Function definitions */
int64_t _1096_main(void) {
    function0 _1096_t0;
    struct1 _1096_t1;
    int64_t _1096_$retval;
    _1096_t0 = _1098_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1096_t1 = _1096_t0();
    $line_idx--;
    _1096_$retval = _1096_t1._1;
    return _1096_$retval;
}

struct1 _1098_f(void) {
    int64_t _1098_t1;
    int64_t _1098_t2;
    struct1 _1098_$retval;
    _1098_t1 = 45;
    _1098_t2 = 221;
    _1098_$retval = (struct1) {_1098_t1, _1098_t2};
    return _1098_$retval;
}

int main(void) {
  printf("%ld",_1096_main());
  return 0;
}
