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
int64_t _28_main(void);
struct1 _33_f(void);

/* Function definitions */
int64_t _28_main(void) {
    function0 _28_t1;
    struct1 _28_t2;
    uint64_t _28_t3;
    uint64_t _28_t4;
    uint8_t _28_t5;
    int64_t _28_$retval;
    uint64_t _28_t6;
    uint64_t _28_t7;
    uint8_t _28_t8;
    _28_t1 = _33_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _28_t2 = _28_t1();
    $line_idx--;
    _28_t3 = 0;
    _28_t4 = _28_t2.tag;
    _28_t5 = _28_t4 == _28_t3;
    if (_28_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _28_t6 = 1;
    _28_t7 = _28_t2.tag;
    _28_t8 = _28_t7 == _28_t6;
    if (_28_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _28_$retval = 238;
    return _28_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _33_f(void) {
    struct1 _33_$retval;
    _33_$retval = (struct1) {.tag=1};
    return _33_$retval;
}

int main(void) {
  printf("%ld",_28_main());
  return 0;
}
