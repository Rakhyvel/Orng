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
int64_t _691_main(void);
struct1 _696_f(void);
struct1 _698_g(void);

/* Function definitions */
int64_t _691_main(void){
    function0 _691_t1;
    struct1 _691_t2;
    uint64_t _691_t3;
    uint64_t _691_t4;
    uint8_t _691_t5;
    int64_t _691_$retval;
    uint64_t _691_t6;
    uint64_t _691_t7;
    uint8_t _691_t8;
    _691_t1 = _696_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _691_t2 = _691_t1();
    $line_idx--;
    _691_t3 = 0;
    _691_t4 = _691_t2.tag;
    _691_t5 = _691_t4 == _691_t3;
    if (_691_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _691_t6 = 1;
    _691_t7 = _691_t2.tag;
    _691_t8 = _691_t7 == _691_t6;
    if (_691_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _691_$retval = 239;
    return _691_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _696_f(void){
    function0 _696_t0;
    struct1 _696_t1;
    uint64_t _696_t2;
    struct1 _696_$retval;
    _696_t0 = _698_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _696_t1 = _696_t0();
    $line_idx--;
    _696_t2 = _696_t1.tag;
    if (_696_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _696_$retval = _696_t1;
    return _696_$retval;
BB3:
    _696_$retval = (struct1) {.tag=0, ._0=(_696_t1._0)};
    return _696_$retval;
}

struct1 _698_g(void){
    struct1 _698_$retval;
    _698_$retval = (struct1) {.tag=1};
    return _698_$retval;
}

int main(void) {
  printf("%ld",_691_main());
  return 0;
}
