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
int64_t _615_main(void);
struct1 _617_f(uint8_t _617_fail);
struct1 _622_g(void);

/* Function definitions */
int64_t _615_main(void){
    function0 _615_t1;
    uint8_t _615_t3;
    struct1 _615_t2;
    uint64_t _615_t4;
    int64_t _615_t0;
    function0 _615_t7;
    uint8_t _615_t9;
    struct1 _615_t8;
    uint64_t _615_t10;
    int64_t _615_t6;
    int64_t _615_$retval;
    _615_t1 = _617_f;
    _615_t3 = 1;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _615_t2 = _615_t1(_615_t3);
    $line_idx--;
    _615_t4 = _615_t2.tag;
    if (_615_t4) {
        goto BB761;
    } else {
        goto BB767;
    }
BB761:
    _615_t0 = 122;
    goto BB762;
BB767:
    _615_t0 = _615_t2._0;
    goto BB762;
BB762:
    _615_t7 = _617_f;
    _615_t9 = 0;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _615_t8 = _615_t7(_615_t9);
    $line_idx--;
    _615_t10 = _615_t8.tag;
    if (_615_t10) {
        goto BB763;
    } else {
        goto BB766;
    }
BB763:
    _615_t6 = 122;
    goto BB764;
BB766:
    _615_t6 = _615_t8._0;
    goto BB764;
BB764:
    _615_$retval = $add_int64_t(_615_t0, _615_t6, "tests/integration/errors/try.orng:3:26:\n    (f(true) catch 122) + (f(false) catch 122)\n                        ^");
    return _615_$retval;
}

struct1 _617_f(uint8_t _617_fail){
    function2 _617_t1;
    struct1 _617_t2;
    uint64_t _617_t3;
    struct1 _617_$retval;
    int64_t _617_t5;
    struct1 _617_t0;
    int64_t _620_x;
    if (_617_fail) {
        goto BB751;
    } else {
        goto BB758;
    }
BB751:
    _617_t1 = _622_g;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _617_t2 = _617_t1();
    $line_idx--;
    _617_t3 = _617_t2.tag;
    if (_617_t3) {
        goto BB752;
    } else {
        goto BB754;
    }
BB758:
    _617_t5 = 0;
    _617_t0 = (struct1) {.tag=0, ._0=_617_t5};
    goto BB757;
BB752:
    _617_$retval = _617_t2;
    return _617_$retval;
BB754:
    _620_x = _617_t2._0;
    _617_t0 = (struct1) {.tag=0, ._0=_620_x};
    goto BB757;
BB757:
    _617_$retval = _617_t0;
    return _617_$retval;
}

struct1 _622_g(void){
    struct1 _622_$retval;
    _622_$retval = (struct1) {.tag=1};
    return _622_$retval;
}

int main(void) {
  printf("%ld",_615_main());
  return 0;
}
