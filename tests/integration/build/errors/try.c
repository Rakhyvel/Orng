/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

typedef struct struct1(*function0)(uint8_t);

typedef struct struct1(*function2)(void);

/* Function forward definitions */
int64_t _24_main(void);
struct struct1 _26_f(uint8_t _26_fail);
struct struct1 _31_g(void);


/* Function definitions */
int64_t _24_main(void){
    function0 _24_t1;
    uint8_t _24_t3;
    struct struct1 _24_t2;
    int64_t _24_t4;
    uint64_t _24_t5;
    int64_t _24_t0;
    function0 _24_t7;
    uint8_t _24_t9;
    struct struct1 _24_t8;
    int64_t _24_t10;
    uint64_t _24_t11;
    int64_t _24_t6;
    int64_t _24_$retval;
    _24_t1 = (function0) _26_f;
    _24_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _24_t2 = _24_t1(_24_t3);
    $line_idx--;
    _24_t4 = 122;
    _24_t5 = _24_t2.tag;
    if (_24_t5) {
        goto BB42;
    } else {
        goto BB48;
    }
BB42:
    _24_t0 = _24_t4;
    goto BB43;
BB48:
    _24_t0 = _24_t2._0;
    goto BB43;
BB43:
    _24_t7 = (function0) _26_f;
    _24_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _24_t8 = _24_t7(_24_t9);
    $line_idx--;
    _24_t10 = 122;
    _24_t11 = _24_t8.tag;
    if (_24_t11) {
        goto BB44;
    } else {
        goto BB47;
    }
BB44:
    _24_t6 = _24_t10;
    goto BB45;
BB47:
    _24_t6 = _24_t8._0;
    goto BB45;
BB45:
    _24_$retval = $add_int64_t(_24_t0, _24_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _24_$retval;
}

struct struct1 _26_f(uint8_t _26_fail){
    function2 _26_t1;
    struct struct1 _26_t2;
    uint64_t _26_t3;
    struct struct1 _26_$retval;
    int64_t _26_t6;
    struct struct1 _26_t0;
    int64_t _29_x;
    if (_26_fail) {
        goto BB32;
    } else {
        goto BB39;
    }
BB32:
    _26_t1 = (function2) _31_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _26_t2 = _26_t1();
    $line_idx--;
    _26_t3 = _26_t2.tag;
    if (_26_t3) {
        goto BB33;
    } else {
        goto BB35;
    }
BB39:
    _26_t6 = 0;
    _26_t0 = (struct struct1) {.tag=0, ._0=_26_t6};
    goto BB38;
BB33:
    _26_$retval = _26_t2;
    return _26_$retval;
BB35:
    _29_x = _26_t2._0;
    _26_t0 = (struct struct1) {.tag=0, ._0=_29_x};
    goto BB38;
BB38:
    _26_$retval = _26_t0;
    return _26_$retval;
}

struct struct1 _31_g(void){
    struct struct1 _31_$retval;
    _31_$retval = (struct struct1) {.tag=1};
    return _31_$retval;
}


int main(void) {
  printf("%ld",_24_main());
  return 0;
}
