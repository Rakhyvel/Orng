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
int64_t _718_main(void);
struct1 _720_f(uint8_t _720_fail);
struct1 _725_g(void);

/* Function definitions */
int64_t _718_main(void){
    function0 _718_t1;
    uint8_t _718_t3;
    struct1 _718_t2;
    uint64_t _718_t4;
    int64_t _718_t0;
    function0 _718_t7;
    uint8_t _718_t9;
    struct1 _718_t8;
    uint64_t _718_t10;
    int64_t _718_t6;
    int64_t _718_$retval;
    _718_t1 = _720_f;
    _718_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _718_t2 = _718_t1(_718_t3);
    $line_idx--;
    _718_t4 = _718_t2.tag;
    if (_718_t4) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _718_t0 = 122;
    goto BB2;
BB7:
    _718_t0 = _718_t2._0;
    goto BB2;
BB2:
    _718_t7 = _720_f;
    _718_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _718_t8 = _718_t7(_718_t9);
    $line_idx--;
    _718_t10 = _718_t8.tag;
    if (_718_t10) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _718_t6 = 122;
    goto BB4;
BB6:
    _718_t6 = _718_t8._0;
    goto BB4;
BB4:
    _718_$retval = $add_int64_t(_718_t0, _718_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _718_$retval;
}

struct1 _720_f(uint8_t _720_fail){
    function2 _720_t1;
    struct1 _720_t2;
    uint64_t _720_t3;
    struct1 _720_$retval;
    int64_t _720_t5;
    struct1 _720_t0;
    int64_t _723_x;
    if (_720_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _720_t1 = _725_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _720_t2 = _720_t1();
    $line_idx--;
    _720_t3 = _720_t2.tag;
    if (_720_t3) {
        goto BB2;
    } else {
        goto BB4;
    }
BB8:
    _720_t5 = 0;
    _720_t0 = (struct1) {.tag=0, ._0=_720_t5};
    goto BB7;
BB2:
    _720_$retval = _720_t2;
    return _720_$retval;
BB4:
    _723_x = _720_t2._0;
    _720_t0 = (struct1) {.tag=0, ._0=_723_x};
    goto BB7;
BB7:
    _720_$retval = _720_t0;
    return _720_$retval;
}

struct1 _725_g(void){
    struct1 _725_$retval;
    _725_$retval = (struct1) {.tag=1};
    return _725_$retval;
}

int main(void) {
  printf("%ld",_718_main());
  return 0;
}
