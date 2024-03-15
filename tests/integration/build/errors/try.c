/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;

/* Struct, union, and function definitions */
struct struct2 {
    uint64_t tag;
};

struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
        struct struct2 _1;
    };
};

typedef struct struct1(*function0)(uint8_t);

typedef struct struct1(*function3)(void);

/* Function forward definitions */
int64_t _608_main(void);
struct struct1 _610_f(uint8_t _610_fail);
struct struct1 _615_g(void);


/* Function definitions */
int64_t _608_main(void){
    function0 _608_t1;
    uint8_t _608_t3;
    struct struct1 _608_t2;
    int64_t _608_t4;
    uint64_t _608_t5;
    int64_t _608_t0;
    function0 _608_t7;
    uint8_t _608_t9;
    struct struct1 _608_t8;
    int64_t _608_t10;
    uint64_t _608_t11;
    int64_t _608_t6;
    int64_t _608_$retval;
    _608_t1 = (function0) _610_f;
    _608_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _608_t2 = _608_t1(_608_t3);
    $line_idx--;
    _608_t4 = 122;
    _608_t5 = _608_t2.tag;
    if (_608_t5) {
        goto BB713;
    } else {
        goto BB719;
    }
BB713:
    _608_t0 = _608_t4;
    goto BB714;
BB719:
    _608_t0 = _608_t2._0;
    goto BB714;
BB714:
    _608_t7 = (function0) _610_f;
    _608_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _608_t8 = _608_t7(_608_t9);
    $line_idx--;
    _608_t10 = 122;
    _608_t11 = _608_t8.tag;
    if (_608_t11) {
        goto BB715;
    } else {
        goto BB718;
    }
BB715:
    _608_t6 = _608_t10;
    goto BB716;
BB718:
    _608_t6 = _608_t8._0;
    goto BB716;
BB716:
    _608_$retval = $add_int64_t(_608_t0, _608_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _608_$retval;
}

struct struct1 _610_f(uint8_t _610_fail){
    function3 _610_t1;
    struct struct1 _610_t2;
    uint64_t _610_t3;
    struct struct1 _610_$retval;
    int64_t _610_t6;
    struct struct1 _610_t0;
    int64_t _613_x;
    if (_610_fail) {
        goto BB703;
    } else {
        goto BB710;
    }
BB703:
    _610_t1 = (function3) _615_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _610_t2 = _610_t1();
    $line_idx--;
    _610_t3 = _610_t2.tag;
    if (_610_t3) {
        goto BB704;
    } else {
        goto BB706;
    }
BB710:
    _610_t6 = 0;
    _610_t0 = (struct struct1) {.tag=0, ._0=_610_t6};
    goto BB709;
BB704:
    _610_$retval = _610_t2;
    return _610_$retval;
BB706:
    _613_x = _610_t2._0;
    _610_t0 = (struct struct1) {.tag=0, ._0=_613_x};
    goto BB709;
BB709:
    _610_$retval = _610_t0;
    return _610_$retval;
}

struct struct1 _615_g(void){
    struct struct2 _615_t0;
    struct struct1 _615_$retval;
    _615_t0 = (struct struct2) {.tag=0};
    _615_$retval = (struct struct1) {.tag=1, ._1=_615_t0};
    return _615_$retval;
}


int main(void) {
  printf("%ld",_608_main());
  return 0;
}
