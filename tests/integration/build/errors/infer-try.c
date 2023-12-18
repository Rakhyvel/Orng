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
int64_t _698_main(void);
struct1 _703_f(void);
struct1 _705_g(void);

/* Function definitions */
int64_t _698_main(void){
    function0 _698_t1;
    struct1 _698_t2;
    uint64_t _698_t3;
    uint64_t _698_t4;
    uint8_t _698_t5;
    int64_t _698_$retval;
    uint64_t _698_t6;
    uint64_t _698_t7;
    uint8_t _698_t8;
    _698_t1 = _703_f;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:3:13:\n    match f() {\n           ^";
    _698_t2 = _698_t1();
    $line_idx--;
    _698_t3 = 0;
    _698_t4 = _698_t2.tag;
    _698_t5 = _698_t4 == _698_t3;
    if (_698_t5) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:4:27:\n        .ok => unreachable\n                         ^";
    $panic("reached unreachable code\n");
BB4:
    _698_t6 = 1;
    _698_t7 = _698_t2.tag;
    _698_t8 = _698_t7 == _698_t6;
    if (_698_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _698_$retval = 239;
    return _698_$retval;
BB10:
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:6:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

struct1 _703_f(void){
    function0 _703_t0;
    struct1 _703_t1;
    uint64_t _703_t2;
    struct1 _703_$retval;
    _703_t0 = _705_g;
    $lines[$line_idx++] = "tests/integration/errors/infer-try.orng:11:19:\n    (.ok <- try g())\n                 ^";
    _703_t1 = _703_t0();
    $line_idx--;
    _703_t2 = _703_t1.tag;
    if (_703_t2) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _703_$retval = _703_t1;
    return _703_$retval;
BB3:
    _703_$retval = (struct1) {.tag=0, ._0=(_703_t1._0)};
    return _703_$retval;
}

struct1 _705_g(void){
    struct1 _705_$retval;
    _705_$retval = (struct1) {.tag=1};
    return _705_$retval;
}

int main(void) {
  printf("%ld",_698_main());
  return 0;
}
