/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

typedef struct {
    int64_t _0;
    struct0 _1;
    uint32_t _2;
} struct1;

typedef struct {
    struct1 _0;
    struct1 _1;
} struct3;

typedef uint8_t(*function2)(struct1, struct1);

/* Function forward definitions */
int64_t _127_main(void);
uint8_t _132_f(struct1 _132_x,struct1 _132_y);

/* Function definitions */
int64_t _127_main(void) {
    int64_t _127_t1;
    int64_t _127_t3;
    double _127_t4;
    struct0 _127_t2;
    uint32_t _127_t5;
    struct1 _128_x;
    int64_t _127_t7;
    int64_t _127_t9;
    double _127_t10;
    struct0 _127_t8;
    uint32_t _127_t11;
    struct1 _128_y;
    function2 _127_t13;
    uint8_t _127_t14;
    int64_t _127_t12;
    int64_t _127_$retval;
    _127_t1 = 1;
    _127_t3 = 2;
    _127_t4 = 3.4e+00;
    _127_t2 = (struct0) {_127_t3, _127_t4};
    _127_t5 = 114;
    _128_x = (struct1) {_127_t1, _127_t2, _127_t5};
    _127_t7 = 1;
    _127_t9 = 2;
    _127_t10 = 3.4e+00;
    _127_t8 = (struct0) {_127_t9, _127_t10};
    _127_t11 = 114;
    _128_y = (struct1) {_127_t7, _127_t8, _127_t11};
    _127_t13 = _132_f;
    $lines[$line_idx++] = "tests/integration/tuples/tuple-equality.orng:5:10:\n    if f(x, y) {\n        ^";
    _127_t14 = _127_t13(_128_x, _128_y);
    $line_idx--;
    if (_127_t14) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _127_t12 = 238;
    goto BB4;
BB5:
    _127_t12 = 832;
    goto BB4;
BB4:
    _127_$retval = _127_t12;
    return _127_$retval;
}

uint8_t _132_f(struct1 _132_x,struct1 _132_y) {
    uint8_t _132_t2;
    uint8_t _132_t4;
    uint8_t _132_t5;
    uint8_t _132_t6;
    uint8_t _132_t0;
    uint8_t _132_$retval;
    _132_t2 = _132_x._0 == _132_y._0;
    if (_132_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _132_t4 = _132_x._1._0 == _132_y._1._0;
    if (_132_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _132_t0 = 0;
    goto BB6;
BB2:
    _132_t5 = _132_x._1._1 == _132_y._1._1;
    if (_132_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB6:
    _132_$retval = _132_t0;
    return _132_$retval;
BB3:
    _132_t6 = _132_x._2 == _132_y._2;
    if (_132_t6) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _132_t0 = 1;
    goto BB6;
}

int main(void) {
  printf("%ld",_127_main());
  return 0;
}
