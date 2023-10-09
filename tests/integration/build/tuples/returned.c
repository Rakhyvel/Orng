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
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
struct0 _3_f(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/tuples/returned.orng:3:7:\n    f().x\n     ^";
    _1_t0 = _3_f();
    $line_idx--;
    _1_$retval = _1_t0._0;
    return _1_$retval;
}

struct0 _3_f(void) {
    struct0 _3_$retval;
    _3_$retval = (struct0) {221, 45};
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
