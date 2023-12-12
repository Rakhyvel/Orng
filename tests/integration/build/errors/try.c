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
int64_t _388_main(void);
struct1 _390_f(uint8_t _390_fail);
struct1 _395_g(void);

/* Function definitions */
int64_t _388_main(void) {
    function0 _388_t1;
    uint8_t _388_t3;
    struct1 _388_t2;
    uint64_t _388_t4;
    int64_t _388_t0;
    function0 _388_t7;
    uint8_t _388_t9;
    struct1 _388_t8;
    uint64_t _388_t10;
    int64_t _388_t6;
    int64_t _388_$retval;
    _388_t1 = _390_f;
    _388_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _388_t2 = _388_t1(_388_t3);
    $line_idx--;
    _388_t4 = _388_t2.tag;
    if (_388_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _388_t0 = 122;
    goto BB2;
BB7:
    _388_t0 = _388_t2._0;
    goto BB2;
BB2:
    _388_t7 = _390_f;
    _388_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _388_t8 = _388_t7(_388_t9);
    $line_idx--;
    _388_t10 = _388_t8.tag;
    if (_388_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _388_t6 = 122;
    goto BB4;
BB6:
    _388_t6 = _388_t8._0;
    goto BB4;
BB4:
    _388_$retval = $add_int64_t(_388_t0, _388_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _388_$retval;
}

struct1 _390_f(uint8_t _390_fail) {
    function2 _390_t1;
    struct1 _390_t2;
    uint64_t _390_t3;
    struct1 _390_$retval;
    int64_t _390_t5;
    struct1 _390_t0;
    int64_t _393_x;
    if (_390_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _390_t1 = _395_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _390_t2 = _390_t1();
    $line_idx--;
    _390_t3 = _390_t2.tag;
    if (_390_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _390_t5 = 0;
    _390_t0 = (struct1) {.tag=0, ._0=_390_t5};
    goto BB7;
BB2:
    _390_$retval = _390_t2;
    return _390_$retval;
BB4:
    _393_x = _390_t2._0;
    _390_t0 = (struct1) {.tag=0, ._0=_393_x};
    goto BB7;
BB7:
    _390_$retval = _390_t0;
    return _390_$retval;
}

struct1 _395_g(void) {
    struct1 _395_$retval;
    _395_$retval = (struct1) {.tag=1};
    return _395_$retval;
}

int main(void) {
  printf("%ld",_388_main());
  return 0;
}
