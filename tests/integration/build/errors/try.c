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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1_main();
struct0 _3_f(uint8_t _3_fail);
struct0 _8_g();

/* Function definitions */
int64_t _1_main() {
    struct0 _1_t1;
    int64_t _1_t0;
    struct0 _1_t7;
    int64_t _1_t6;
    int64_t _1_$retval;
$lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";    _1_t1 = _3_f(1);
    $line_idx--;
    if (_1_t1.tag) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1_t0 = _1_t1._1;
    goto BB2;
BB7:
    _1_t0 = 122;
BB2:
$lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";    _1_t7 = _3_f(0);
    $line_idx--;
    if (_1_t7.tag) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1_t6 = _1_t7._1;
    goto BB4;
BB6:
    _1_t6 = 122;
BB4:
    _1_$retval = $add_int64_t(_1_t0, _1_t6, "tests/integration/errors/try.orng:2:3:\nfn main() -> Int { \n ^");
    return _1_$retval;
}

struct0 _3_f(uint8_t _3_fail) {
    struct0 _3_t1;
    int64_t _3_t3;
    struct0 _3_t0;
    struct0 _3_$retval;
    if (_3_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
$lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";    _3_t1 = _8_g();
    $line_idx--;
    if (_3_t1.tag) {
        goto BB2;
    } else {
        goto BB7;
    }
BB8:
    _3_t0 = (struct0) {.tag=1, ._1=0};
    goto BB6;
BB2:
    _3_t3 = _3_t1._1;
    _3_t0 = (struct0) {.tag=1, ._1=_3_t3};
    goto BB6;
BB7:
    _3_$retval = _3_t1;
    return _3_$retval;
BB6:
    _3_$retval = _3_t0;
    return _3_$retval;
}

struct0 _8_g() {
    struct0 _8_$retval;
    _8_$retval = (struct0) {.tag=0};
    return _8_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
