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
int64_t _310_main(void);
struct1 _315_f(void);
struct1 _317_g(void);

/* Function definitions */
int64_t _310_main(void) {
    function0 _310_t1;
    struct1 _310_t2;
    uint64_t _310_t3;
    uint64_t _310_t4;
    uint8_t _310_t5;
    int64_t _310_$retval;
    uint64_t _310_t6;
    uint64_t _310_t7;
    uint8_t _310_t8;
    _310_t1 = _315_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _310_t2 = _310_t1();
    $line_idx--;
    _310_t3 = 0;
    _310_t4 = _310_t2.tag;
    _310_t5 = _310_t4 == _310_t3;
    if (_310_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _310_t6 = 1;
    _310_t7 = _310_t2.tag;
    _310_t8 = _310_t7 == _310_t6;
    if (_310_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _310_$retval = 239;
    return _310_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _315_f(void) {
    function0 _315_t0;
    struct1 _315_t1;
    uint64_t _315_t2;
    struct1 _315_$retval;
    _315_t0 = _317_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _315_t1 = _315_t0();
    $line_idx--;
    _315_t2 = _315_t1.tag;
    if (_315_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _315_$retval = _315_t1;
    return _315_$retval;
BB3:
    _315_$retval = (struct1) {.tag=0, ._0=(_315_t1._0)};
    return _315_$retval;
}

struct1 _317_g(void) {
    struct1 _317_$retval;
    _317_$retval = (struct1) {.tag=1};
    return _317_$retval;
}

int main(void) {
  printf("%ld",_310_main());
  return 0;
}
