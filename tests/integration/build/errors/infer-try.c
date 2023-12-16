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
int64_t _606_main(void);
struct1 _611_f(void);
struct1 _613_g(void);

/* Function definitions */
int64_t _606_main(void){
    function0 _606_t1;
    struct1 _606_t2;
    uint64_t _606_t3;
    uint64_t _606_t4;
    uint8_t _606_t5;
    int64_t _606_$retval;
    uint64_t _606_t6;
    uint64_t _606_t7;
    uint8_t _606_t8;
    _606_t1 = _611_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _606_t2 = _606_t1();
    $line_idx--;
    _606_t3 = 0;
    _606_t4 = _606_t2.tag;
    _606_t5 = _606_t4 == _606_t3;
    if (_606_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _606_t6 = 1;
    _606_t7 = _606_t2.tag;
    _606_t8 = _606_t7 == _606_t6;
    if (_606_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _606_$retval = 239;
    return _606_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _611_f(void){
    function0 _611_t0;
    struct1 _611_t1;
    uint64_t _611_t2;
    struct1 _611_$retval;
    _611_t0 = _613_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _611_t1 = _611_t0();
    $line_idx--;
    _611_t2 = _611_t1.tag;
    if (_611_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _611_$retval = _611_t1;
    return _611_$retval;
BB3:
    _611_$retval = (struct1) {.tag=0, ._0=(_611_t1._0)};
    return _611_$retval;
}

struct1 _613_g(void){
    struct1 _613_$retval;
    _613_$retval = (struct1) {.tag=1};
    return _613_$retval;
}

int main(void) {
  printf("%ld",_606_main());
  return 0;
}
