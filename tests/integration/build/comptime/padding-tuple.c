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
int64_t _148_main(void);
int64_t _150_f(struct0 _150_m);

/* Function definitions */
int64_t _148_main(void) {
    int8_t _148_t1;
    int16_t _148_t2;
    int8_t _148_t3;
    struct0 _149_m;
    function1 _148_t4;
    int64_t _148_t5;
    int64_t _148_t6;
    int64_t _148_$retval;
    _148_t1 = 100;
    _148_t2 = 50;
    _148_t3 = 7;
    _149_m = (struct0) {_148_t1, _148_t2, _148_t3};
    _148_t4 = _150_f;
    $lines[$line_idx++] = "tests/integration/comptime/padding-tuple.orng:10:7:\n    f(m) + @sizeof(@typeof(m))\n     ^";
    _148_t5 = _148_t4(_149_m);
    $line_idx--;
    _148_t6 = 5;
    _148_$retval = $add_int64_t(_148_t5, _148_t6, "tests/integration/comptime/padding-tuple.orng:10:11:\n    f(m) + @sizeof(@typeof(m))\n         ^");
    return _148_$retval;
}

int64_t _150_f(struct0 _150_m) {
    int8_t _150_t3;
    uint8_t _150_t5;
    uint8_t _150_t7;
    int16_t _150_t6;
    uint8_t _150_t8;
    uint8_t _150_t2;
    int8_t _150_t9;
    uint8_t _150_t11;
    uint8_t _150_t10;
    uint8_t _150_t1;
    int64_t _150_$retval;
    _150_t3 = 100;
    _150_t5 = _150_m._0 == _150_t3;
    if (_150_t5) {
        goto BB3;
    } else {
        goto BB19;
    }
BB3:
    _150_t6 = 50;
    _150_t8 = _150_m._1 == _150_t6;
    if (_150_t8) {
        goto BB4;
    } else {
        goto BB18;
    }
BB19:
    _150_t2 = 0;
    goto BB17;
BB4:
    _150_t7 = 1;
    goto BB5;
BB18:
    _150_t7 = 0;
    goto BB5;
BB17:
    _150_t1 = 0;
    goto BB15;
BB5:
    _150_t2 = _150_t7;
    goto BB6;
BB15:
    $lines[$line_idx++] = "tests/integration/comptime/padding-tuple.orng:17:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
BB6:
    if (_150_t2) {
        goto BB7;
    } else {
        goto BB17;
    }
BB7:
    _150_t9 = 7;
    _150_t11 = _150_m._2 == _150_t9;
    if (_150_t11) {
        goto BB8;
    } else {
        goto BB16;
    }
BB8:
    _150_t10 = 1;
    goto BB9;
BB16:
    _150_t10 = 0;
    goto BB9;
BB9:
    _150_t1 = _150_t10;
    goto BB10;
BB10:
    if (_150_t1) {
        goto BB11;
    } else {
        goto BB15;
    }
BB11:
    _150_$retval = 252;
    return _150_$retval;
}

int main(void) {
  printf("%ld",_148_main());
  return 0;
}
