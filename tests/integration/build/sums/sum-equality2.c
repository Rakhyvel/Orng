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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
struct0 _6_f(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0 _1_t2;
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1_t1 = _6_f();
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1_t2 = _6_f();
    $line_idx--;
    if (_1_t1.tag == _1_t2.tag) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_t0 = 212;
    goto BB4;
BB5:
    _1_t0 = -1;
BB4:
    _1_$retval = _1_t0;
    return _1_$retval;
}

struct0 _6_f(void) {
    struct0 _6_$retval;
    _6_$retval = (struct0) {.tag=0};
    return _6_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
