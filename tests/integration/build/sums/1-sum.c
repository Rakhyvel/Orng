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
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
struct0 _3_get_the_sum(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    $line_idx--;
    _1_$retval = _3_get_the_sum()._0;
    return _1_$retval;
}

struct0 _3_get_the_sum(void) {
    struct0 _3_$retval;
    _3_$retval = (struct0) {.tag=0, ._0=235};
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
