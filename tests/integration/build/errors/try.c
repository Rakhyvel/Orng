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

typedef struct1(*function0)(uint8_t);

typedef struct1(*function2)(void);

/* Function forward definitions */
int64_t _566_main(void);
struct1 _568_f(uint8_t _568_fail);
struct1 _573_g(void);

/* Function definitions */
int64_t _566_main(void){
    function0 _566_t1;
    uint8_t _566_t3;
    struct1 _566_t2;
    uint64_t _566_t4;
    int64_t _566_t0;
    function0 _566_t7;
    uint8_t _566_t9;
    struct1 _566_t8;
    uint64_t _566_t10;
    int64_t _566_t6;
    int64_t _566_$retval;
    _566_t1 = _568_f;
    _566_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _566_t2 = _566_t1(_566_t3);
    $line_idx--;
    _566_t4 = _566_t2.tag;
    if (_566_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _566_t0 = 122;
    goto BB2;
BB7:
    _566_t0 = _566_t2._0;
    goto BB2;
BB2:
    _566_t7 = _568_f;
    _566_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _566_t8 = _566_t7(_566_t9);
    $line_idx--;
    _566_t10 = _566_t8.tag;
    if (_566_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _566_t6 = 122;
    goto BB4;
BB6:
    _566_t6 = _566_t8._0;
    goto BB4;
BB4:
    _566_$retval = $add_int64_t(_566_t0, _566_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _566_$retval;
}

struct1 _568_f(uint8_t _568_fail){
    function2 _568_t1;
    struct1 _568_t2;
    uint64_t _568_t3;
    struct1 _568_$retval;
    int64_t _568_t5;
    struct1 _568_t0;
    int64_t _571_x;
    if (_568_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _568_t1 = _573_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _568_t2 = _568_t1();
    $line_idx--;
    _568_t3 = _568_t2.tag;
    if (_568_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _568_t5 = 0;
    _568_t0 = (struct1) {.tag=0, ._0=_568_t5};
    goto BB7;
BB2:
    _568_$retval = _568_t2;
    return _568_$retval;
BB4:
    _571_x = _568_t2._0;
    _568_t0 = (struct1) {.tag=0, ._0=_571_x};
    goto BB7;
BB7:
    _568_$retval = _568_t0;
    return _568_$retval;
}

struct1 _573_g(void){
    struct1 _573_$retval;
    _573_$retval = (struct1) {.tag=1};
    return _573_$retval;
}

int main(void) {
  printf("%ld",_566_main());
  return 0;
}
