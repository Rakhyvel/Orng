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
int64_t _362_main(void);
struct1 _367_f(void);

/* Function definitions */
int64_t _362_main(void) {
    function0 _362_t1;
    struct1 _362_t2;
    uint64_t _362_t3;
    uint64_t _362_t4;
    uint8_t _362_t5;
    int64_t _362_$retval;
    uint64_t _362_t6;
    uint64_t _362_t7;
    uint8_t _362_t8;
    _362_t1 = _367_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:3:13:\n    match f() {\n           ^";
    _362_t2 = _362_t1();
    $line_idx--;
    _362_t3 = 0;
    _362_t4 = _362_t2.tag;
    _362_t5 = _362_t4 == _362_t3;
    if (_362_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _362_t6 = 1;
    _362_t7 = _362_t2.tag;
    _362_t8 = _362_t7 == _362_t6;
    if (_362_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _362_$retval = 238;
    return _362_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-return.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _367_f(void) {
    struct1 _367_$retval;
    _367_$retval = (struct1) {.tag=1};
    return _367_$retval;
}

int main(void) {
  printf("%ld",_362_main());
  return 0;
}
