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
int64_t _613_main(void);
struct struct1 _615_f(uint8_t _615_fail);
struct struct1 _620_g(void);


/* Function definitions */
int64_t _613_main(void){
    function0 _613_t1;
    uint8_t _613_t3;
    struct struct1 _613_t2;
    int64_t _613_t4;
    uint64_t _613_t5;
    int64_t _613_t0;
    function0 _613_t7;
    uint8_t _613_t9;
    struct struct1 _613_t8;
    int64_t _613_t10;
    uint64_t _613_t11;
    int64_t _613_t6;
    int64_t _613_$retval;
    _613_t1 = (function0) _615_f;
    _613_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _613_t2 = _613_t1(_613_t3);
    $line_idx--;
    _613_t4 = 122;
    _613_t5 = _613_t2.tag;
    if (_613_t5) {
        goto BB716;
    } else {
        goto BB722;
    }
BB716:
    _613_t0 = _613_t4;
    goto BB717;
BB722:
    _613_t0 = _613_t2._0;
    goto BB717;
BB717:
    _613_t7 = (function0) _615_f;
    _613_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _613_t8 = _613_t7(_613_t9);
    $line_idx--;
    _613_t10 = 122;
    _613_t11 = _613_t8.tag;
    if (_613_t11) {
        goto BB718;
    } else {
        goto BB721;
    }
BB718:
    _613_t6 = _613_t10;
    goto BB719;
BB721:
    _613_t6 = _613_t8._0;
    goto BB719;
BB719:
    _613_$retval = $add_int64_t(_613_t0, _613_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _613_$retval;
}

struct struct1 _615_f(uint8_t _615_fail){
    function2 _615_t1;
    struct struct1 _615_t2;
    uint64_t _615_t3;
    struct struct1 _615_$retval;
    int64_t _615_t6;
    struct struct1 _615_t0;
    int64_t _618_x;
    if (_615_fail) {
        goto BB706;
    } else {
        goto BB713;
    }
BB706:
    _615_t1 = (function2) _620_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _615_t2 = _615_t1();
    $line_idx--;
    _615_t3 = _615_t2.tag;
    if (_615_t3) {
        goto BB707;
    } else {
        goto BB709;
    }
BB713:
    _615_t6 = 0;
    _615_t0 = (struct struct1) {.tag=0, ._0=_615_t6};
    goto BB712;
BB707:
    _615_$retval = _615_t2;
    return _615_$retval;
BB709:
    _618_x = _615_t2._0;
    _615_t0 = (struct struct1) {.tag=0, ._0=_618_x};
    goto BB712;
BB712:
    _615_$retval = _615_t0;
    return _615_$retval;
}

struct struct1 _620_g(void){
    struct struct1 _620_$retval;
    _620_$retval = (struct struct1) {.tag=1};
    return _620_$retval;
}


int main(void) {
  printf("%ld",_613_main());
  return 0;
}
