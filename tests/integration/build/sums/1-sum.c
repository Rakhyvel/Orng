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
int64_t _2_main(void);
struct1 _4_get_the_sum(void);

/* Function definitions */
int64_t _2_main(void) {
    function0 _2_t0;
    struct1 _2_t1;
    struct1 _3_a;
    int64_t _2_$retval;
    _2_t0 = _4_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _2_t1 = _2_t0();
    $line_idx--;
    _3_a = _2_t1;
    _2_$retval = _3_a._0;
    return _2_$retval;
}

struct1 _4_get_the_sum(void) {
    int64_t _4_t0;
    struct1 _4_$retval;
    _4_t0 = 235;
    _4_$retval = (struct1) {.tag=0, ._0=_4_t0};
    return _4_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
