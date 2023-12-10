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
int64_t _1072_main(void);
struct1 _1074_get_the_sum(void);

/* Function definitions */
int64_t _1072_main(void) {
    function0 _1072_t0;
    struct1 _1072_t1;
    struct1 _1073_a;
    int64_t _1072_$retval;
    _1072_t0 = _1074_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _1072_t1 = _1072_t0();
    $line_idx--;
    _1073_a = _1072_t1;
    _1072_$retval = _1073_a._0;
    return _1072_$retval;
}

struct1 _1074_get_the_sum(void) {
    int64_t _1074_t0;
    struct1 _1074_$retval;
    _1074_t0 = 235;
    _1074_$retval = (struct1) {.tag=0, ._0=_1074_t0};
    return _1074_$retval;
}

int main(void) {
  printf("%ld",_1072_main());
  return 0;
}
