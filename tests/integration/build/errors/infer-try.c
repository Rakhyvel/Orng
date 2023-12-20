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
int64_t _585_main(void);
struct1 _590_f(void);
struct1 _592_g(void);

/* Function definitions */
int64_t _585_main(void){
    function0 _585_t1;
    struct1 _585_t2;
    uint64_t _585_t3;
    uint64_t _585_t4;
    uint8_t _585_t5;
    int64_t _585_$retval;
    uint64_t _585_t6;
    uint64_t _585_t7;
    uint8_t _585_t8;
    _585_t1 = _590_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _585_t2 = _585_t1();
    $line_idx--;
    _585_t3 = 0;
    _585_t4 = _585_t2.tag;
    _585_t5 = _585_t4 == _585_t3;
    if (_585_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _585_t6 = 1;
    _585_t7 = _585_t2.tag;
    _585_t8 = _585_t7 == _585_t6;
    if (_585_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _585_$retval = 239;
    return _585_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _590_f(void){
    function0 _590_t0;
    struct1 _590_t1;
    uint64_t _590_t2;
    struct1 _590_$retval;
    _590_t0 = _592_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _590_t1 = _590_t0();
    $line_idx--;
    _590_t2 = _590_t1.tag;
    if (_590_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _590_$retval = _590_t1;
    return _590_$retval;
BB3:
    _590_$retval = (struct1) {.tag=0, ._0=(_590_t1._0)};
    return _590_$retval;
}

struct1 _592_g(void){
    struct1 _592_$retval;
    _592_$retval = (struct1) {.tag=1};
    return _592_$retval;
}

int main(void) {
  printf("%ld",_585_main());
  return 0;
}
