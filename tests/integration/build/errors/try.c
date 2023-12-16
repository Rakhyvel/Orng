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
int64_t _626_main(void);
struct1 _628_f(uint8_t _628_fail);
struct1 _633_g(void);

/* Function definitions */
int64_t _626_main(void){
    function0 _626_t1;
    uint8_t _626_t3;
    struct1 _626_t2;
    uint64_t _626_t4;
    int64_t _626_t0;
    function0 _626_t7;
    uint8_t _626_t9;
    struct1 _626_t8;
    uint64_t _626_t10;
    int64_t _626_t6;
    int64_t _626_$retval;
    _626_t1 = _628_f;
    _626_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _626_t2 = _626_t1(_626_t3);
    $line_idx--;
    _626_t4 = _626_t2.tag;
    if (_626_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _626_t0 = 122;
    goto BB2;
BB7:
    _626_t0 = _626_t2._0;
    goto BB2;
BB2:
    _626_t7 = _628_f;
    _626_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _626_t8 = _626_t7(_626_t9);
    $line_idx--;
    _626_t10 = _626_t8.tag;
    if (_626_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _626_t6 = 122;
    goto BB4;
BB6:
    _626_t6 = _626_t8._0;
    goto BB4;
BB4:
    _626_$retval = $add_int64_t(_626_t0, _626_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _626_$retval;
}

struct1 _628_f(uint8_t _628_fail){
    function2 _628_t1;
    struct1 _628_t2;
    uint64_t _628_t3;
    struct1 _628_$retval;
    int64_t _628_t5;
    struct1 _628_t0;
    int64_t _631_x;
    if (_628_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _628_t1 = _633_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _628_t2 = _628_t1();
    $line_idx--;
    _628_t3 = _628_t2.tag;
    if (_628_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _628_t5 = 0;
    _628_t0 = (struct1) {.tag=0, ._0=_628_t5};
    goto BB7;
BB2:
    _628_$retval = _628_t2;
    return _628_$retval;
BB4:
    _631_x = _628_t2._0;
    _628_t0 = (struct1) {.tag=0, ._0=_631_x};
    goto BB7;
BB7:
    _628_$retval = _628_t0;
    return _628_$retval;
}

struct1 _633_g(void){
    struct1 _633_$retval;
    _633_$retval = (struct1) {.tag=1};
    return _633_$retval;
}

int main(void) {
  printf("%ld",_626_main());
  return 0;
}
