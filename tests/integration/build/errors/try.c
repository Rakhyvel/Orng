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
int64_t _369_main(void);
struct1 _371_f(uint8_t _371_fail);
struct1 _376_g(void);

/* Function definitions */
int64_t _369_main(void) {
    function0 _369_t1;
    uint8_t _369_t3;
    struct1 _369_t2;
    uint64_t _369_t4;
    int64_t _369_t0;
    function0 _369_t7;
    uint8_t _369_t9;
    struct1 _369_t8;
    uint64_t _369_t10;
    int64_t _369_t6;
    int64_t _369_$retval;
    _369_t1 = _371_f;
    _369_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _369_t2 = _369_t1(_369_t3);
    $line_idx--;
    _369_t4 = _369_t2.tag;
    if (_369_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _369_t0 = 122;
    goto BB2;
BB7:
    _369_t0 = _369_t2._0;
    goto BB2;
BB2:
    _369_t7 = _371_f;
    _369_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _369_t8 = _369_t7(_369_t9);
    $line_idx--;
    _369_t10 = _369_t8.tag;
    if (_369_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _369_t6 = 122;
    goto BB4;
BB6:
    _369_t6 = _369_t8._0;
    goto BB4;
BB4:
    _369_$retval = $add_int64_t(_369_t0, _369_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _369_$retval;
}

struct1 _371_f(uint8_t _371_fail) {
    function2 _371_t1;
    struct1 _371_t2;
    uint64_t _371_t3;
    struct1 _371_$retval;
    int64_t _371_t5;
    struct1 _371_t0;
    int64_t _374_x;
    if (_371_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _371_t1 = _376_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _371_t2 = _371_t1();
    $line_idx--;
    _371_t3 = _371_t2.tag;
    if (_371_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _371_t5 = 0;
    _371_t0 = (struct1) {.tag=0, ._0=_371_t5};
    goto BB7;
BB2:
    _371_$retval = _371_t2;
    return _371_$retval;
BB4:
    _374_x = _371_t2._0;
    _371_t0 = (struct1) {.tag=0, ._0=_374_x};
    goto BB7;
BB7:
    _371_$retval = _371_t0;
    return _371_$retval;
}

struct1 _376_g(void) {
    struct1 _376_$retval;
    _376_$retval = (struct1) {.tag=1};
    return _376_$retval;
}

int main(void) {
  printf("%ld",_369_main());
  return 0;
}
