/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int8_t _0;
    int16_t _1;
    int8_t _2;
} struct0;

typedef int64_t(*function1)(struct0);

/* Function forward definitions */
int64_t _65_main(void);
int64_t _67_f(struct0 _67_m);

/* Function definitions */
int64_t _65_main(void) {
    int8_t _65_t1;
    int16_t _65_t2;
    int8_t _65_t3;
    struct0 _66_m;
    function1 _65_t4;
    int64_t _65_t5;
    int64_t _65_t6;
    int64_t _65_$retval;
    _65_t1 = 100;
    _65_t2 = 50;
    _65_t3 = 7;
    _66_m = (struct0) {_65_t1, _65_t2, _65_t3};
    _65_t4 = _67_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-tuple.orng:10:7:\n    f(m) + sizeof typeof m\n     ^";
    _65_t5 = _65_t4(_66_m);
    $line_idx--;
    _65_t6 = 5;
    _65_$retval = $add_int64_t(_65_t5, _65_t6, "tests/integration/comptime/padding-tuple.orng:10:11:\n    f(m) + sizeof typeof m\n         ^");
    return _65_$retval;
}

int64_t _67_f(struct0 _67_m) {
    int8_t _67_t3;
    uint8_t _67_t5;
    uint8_t _67_t7;
    int16_t _67_t6;
    uint8_t _67_t8;
    uint8_t _67_t2;
    int8_t _67_t9;
    uint8_t _67_t11;
    uint8_t _67_t10;
    uint8_t _67_t1;
    int64_t _67_$retval;
    _67_t3 = 100;
    _67_t5 = _67_m._0 == _67_t3;
    if (_67_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _67_t6 = 50;
    _67_t8 = _67_m._1 == _67_t6;
    if (_67_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _67_t2 = 0;
    goto BB17;
BB4:
    _67_t7 = 1;
    goto BB5;
BB18:
    _67_t7 = 0;
    goto BB5;
BB17:
    _67_t1 = 0;
    goto BB15;
BB5:
    _67_t2 = _67_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-tuple.orng:17:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_67_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _67_t9 = 7;
    _67_t11 = _67_m._2 == _67_t9;
    if (_67_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _67_t10 = 1;
    goto BB9;
BB16:
    _67_t10 = 0;
    goto BB9;
BB9:
    _67_t1 = _67_t10;
    goto BB10;
BB10:
    if (_67_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _67_$retval = 252;
    return _67_$retval;
}

int main(void) {
  printf("%ld",_65_main());
  return 0;
}
