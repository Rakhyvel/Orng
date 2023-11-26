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
int64_t _982_main(void);
struct1 _984_get_the_sum(void);

/* Function definitions */
int64_t _982_main(void) {
    function0 _982_t0;
    struct1 _982_t1;
    struct1 _983_a;
    int64_t _982_$retval;
    _982_t0 = _984_get_the_sum;
    $lines[$line_idx++] = "tests/integration/sums/1-sum.orng:5:25:\n    let a = get_the_sum()\n                       ^";
    _982_t1 = _982_t0();
    $line_idx--;
    _983_a = _982_t1;
    _982_$retval = _983_a._0;
    return _982_$retval;
}

struct1 _984_get_the_sum(void) {
    int64_t _984_t0;
    struct1 _984_$retval;
    _984_t0 = 235;
    _984_$retval = (struct1) {.tag=0, ._0=_984_t0};
    return _984_$retval;
}

int main(void) {
  printf("%ld",_982_main());
  return 0;
}
