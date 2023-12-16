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
int64_t _546_main(void);
struct1 _551_f(void);
struct1 _553_g(void);

/* Function definitions */
int64_t _546_main(void){
    function0 _546_t1;
    struct1 _546_t2;
    uint64_t _546_t3;
    uint64_t _546_t4;
    uint8_t _546_t5;
    int64_t _546_$retval;
    uint64_t _546_t6;
    uint64_t _546_t7;
    uint8_t _546_t8;
    _546_t1 = _551_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _546_t2 = _546_t1();
    $line_idx--;
    _546_t3 = 0;
    _546_t4 = _546_t2.tag;
    _546_t5 = _546_t4 == _546_t3;
    if (_546_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _546_t6 = 1;
    _546_t7 = _546_t2.tag;
    _546_t8 = _546_t7 == _546_t6;
    if (_546_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _546_$retval = 239;
    return _546_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _551_f(void){
    function0 _551_t0;
    struct1 _551_t1;
    uint64_t _551_t2;
    struct1 _551_$retval;
    _551_t0 = _553_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _551_t1 = _551_t0();
    $line_idx--;
    _551_t2 = _551_t1.tag;
    if (_551_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _551_$retval = _551_t1;
    return _551_$retval;
BB3:
    _551_$retval = (struct1) {.tag=0, ._0=(_551_t1._0)};
    return _551_$retval;
}

struct1 _553_g(void){
    struct1 _553_$retval;
    _553_$retval = (struct1) {.tag=1};
    return _553_$retval;
}

int main(void) {
  printf("%ld",_546_main());
  return 0;
}
