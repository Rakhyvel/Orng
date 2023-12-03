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
int64_t _335_main(void);
struct1 _340_f(void);

/* Function definitions */
int64_t _335_main(void) {
    function0 _335_t1;
    struct1 _335_t2;
    uint64_t _335_t3;
    uint64_t _335_t4;
    uint8_t _335_t5;
    int64_t _335_$retval;
    uint64_t _335_t6;
    uint64_t _335_t7;
    uint8_t _335_t8;
    _335_t1 = _340_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _335_t2 = _335_t1();
    $line_idx--;
    _335_t3 = 0;
    _335_t4 = _335_t2.tag;
    _335_t5 = _335_t4 == _335_t3;
    if (_335_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _335_t6 = 1;
    _335_t7 = _335_t2.tag;
    _335_t8 = _335_t7 == _335_t6;
    if (_335_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _335_$retval = 238;
    return _335_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _340_f(void) {
    struct1 _340_$retval;
    _340_$retval = (struct1) {.tag=1};
    return _340_$retval;
}

int main(void) {
  printf("%ld",_335_main());
  return 0;
}
