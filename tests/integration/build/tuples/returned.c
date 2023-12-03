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
int64_t _1134_main(void);
struct1 _1136_f(void);

/* Function definitions */
int64_t _1134_main(void) {
    function0 _1134_t0;
    struct1 _1134_t1;
    int64_t _1134_$retval;
    _1134_t0 = _1136_f;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().y\n     ^";
    _1134_t1 = _1134_t0();
    $line_idx--;
    _1134_$retval = _1134_t1._1;
    return _1134_$retval;
}

struct1 _1136_f(void) {
    int64_t _1136_t1;
    int64_t _1136_t2;
    struct1 _1136_$retval;
    _1136_t1 = 45;
    _1136_t2 = 221;
    _1136_$retval = (struct1) {_1136_t1, _1136_t2};
    return _1136_$retval;
}

int main(void) {
  printf("%ld",_1134_main());
  return 0;
}
