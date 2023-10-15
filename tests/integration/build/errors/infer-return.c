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
struct0 _6_f(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _1_t1 = _6_f();
    $line_idx--;
    if (_1_t1.tag) {
        goto BB4;
    } else {
        goto BB3;
    }
BB4:
    if (_1_t1.tag == 1) {
        goto BB6;
    } else {
        goto BB10;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB6:
    _1_$retval = 238;
    return _1_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct0 _6_f(void) {
    struct0 _6_$retval;
    _6_$retval = (struct0) {.tag=1};
    return _6_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
