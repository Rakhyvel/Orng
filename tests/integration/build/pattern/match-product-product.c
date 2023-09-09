/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;
typedef struct {
    struct0 _0;
    struct0 _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _2_t2;
    int64_t _2_t6;
    int64_t _2_t7;
    struct0 _2_t5;
    struct1 _2_t1;
    struct0 _2_t8;
    int64_t _2_t9;
    int64_t _2_t10;
    uint8_t _2_t11;
    int64_t _2_t12;
    int64_t _2_t13;
    uint8_t _2_t14;
    int64_t _2_t0;
    int64_t _2_$retval;
    struct0 _2_t16;
    int64_t _2_t17;
    int64_t _2_t18;
    uint8_t _2_t19;
    int64_t _2_t20;
    int64_t _2_t21;
    uint8_t _2_t22;
BB0:
    _2_t3 = 100;
    _2_t4 = 100;
    _2_t2 = (struct0) {_2_t3, _2_t4};
    _2_t6 = 200;
    _2_t7 = 200;
    _2_t5 = (struct0) {_2_t6, _2_t7};
    _2_t1 = (struct1) {_2_t2, _2_t5};
    _2_t8 = (&_2_t1)->_0;
    _2_t9 = (&((&_2_t1)->_0))->_0;
    _2_t10 = 100;
    _2_t11 = _2_t9 == _2_t10;
    if (_2_t11) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    _2_t16 = (&_2_t1)->_0;
    _2_t17 = (&((&_2_t1)->_0))->_0;
    _2_t18 = 100;
    _2_t19 = _2_t17 == _2_t18;
    if (_2_t19) {
        goto BB8;
    } else {
        goto BB12;
    }
BB12:
    $lines[$line_idx++] = "tests/integration/pattern/match-product-product.orng:6:28:\n        else => unreachable\n                          ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB6;
BB6:
    _2_$retval = _2_t0;
    return _2_$retval;
BB8:
    _2_t20 = (&_2_t16)->_1;
    _2_t21 = 100;
    _2_t22 = _2_t20 == _2_t21;
    if (_2_t22) {
        goto BB9;
    } else {
        goto BB12;
    }
BB9:
    _2_t0 = 170;
    goto BB6;
BB2:
    _2_t12 = (&_2_t8)->_1;
    _2_t13 = 130;
    _2_t14 = _2_t12 == _2_t13;
    if (_2_t14) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _2_t0 = 4;
    goto BB6;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
