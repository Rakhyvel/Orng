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
int64_t _271_main(void);
struct1 _276_f(void);

/* Function definitions */
int64_t _271_main(void) {
    function0 _271_t1;
    struct1 _271_t2;
    uint64_t _271_t3;
    uint64_t _271_t4;
    uint8_t _271_t5;
    int64_t _271_$retval;
    uint64_t _271_t6;
    uint64_t _271_t7;
    uint8_t _271_t8;
    _271_t1 = _276_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _271_t2 = _271_t1();
    $line_idx--;
    _271_t3 = 0;
    _271_t4 = _271_t2.tag;
    _271_t5 = _271_t4 == _271_t3;
    if (_271_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _271_t6 = 1;
    _271_t7 = _271_t2.tag;
    _271_t8 = _271_t7 == _271_t6;
    if (_271_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _271_$retval = 238;
    return _271_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _276_f(void) {
    struct1 _276_$retval;
    _276_$retval = (struct1) {.tag=1};
    return _276_$retval;
}

int main(void) {
  printf("%ld",_271_main());
  return 0;
}
