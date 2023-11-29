/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _3_main(void);
struct1 _5_get_the_sum(void);

/* Function definitions */
int64_t _3_main(void) {
    function0 _3_t0;
    struct1 _3_t1;
    struct1 _4_a;
    int64_t _3_$retval;
    _3_t0 = _5_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _3_t1 = _3_t0();
    $line_idx--;
    _4_a = _3_t1;
    _3_$retval = _4_a._0;
    return _3_$retval;
}

struct1 _5_get_the_sum(void) {
    int64_t _5_t0;
    struct1 _5_$retval;
    _5_t0 = 235;
    _5_$retval = (struct1) {.tag=0, ._0=_5_t0};
    return _5_$retval;
}

int main(void) {
  printf("%ld",_3_main());
  return 0;
}
