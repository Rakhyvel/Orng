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
int64_t _535_main(void);
struct1 _540_f(void);
struct1 _542_g(void);

/* Function definitions */
int64_t _535_main(void){
    function0 _535_t1;
    struct1 _535_t2;
    uint64_t _535_t3;
    uint64_t _535_t4;
    uint8_t _535_t5;
    int64_t _535_$retval;
    uint64_t _535_t6;
    uint64_t _535_t7;
    uint8_t _535_t8;
    _535_t1 = _540_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _535_t2 = _535_t1();
    $line_idx--;
    _535_t3 = 0;
    _535_t4 = _535_t2.tag;
    _535_t5 = _535_t4 == _535_t3;
    if (_535_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _535_t6 = 1;
    _535_t7 = _535_t2.tag;
    _535_t8 = _535_t7 == _535_t6;
    if (_535_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _535_$retval = 239;
    return _535_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _540_f(void){
    function0 _540_t0;
    struct1 _540_t1;
    uint64_t _540_t2;
    struct1 _540_$retval;
    _540_t0 = _542_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _540_t1 = _540_t0();
    $line_idx--;
    _540_t2 = _540_t1.tag;
    if (_540_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _540_$retval = _540_t1;
    return _540_$retval;
BB3:
    _540_$retval = (struct1) {.tag=0, ._0=(_540_t1._0)};
    return _540_$retval;
}

struct1 _542_g(void){
    struct1 _542_$retval;
    _542_$retval = (struct1) {.tag=1};
    return _542_$retval;
}

int main(void) {
  printf("%ld",_535_main());
  return 0;
}
