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
    int64_t _2;
    int64_t _3;
    int64_t _4;
    int64_t _5;
} struct0;
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();
int64_t _4_sum_up(struct1 _4_xs);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    int64_t _2_t5;
    int64_t _2_t6;
    struct0 _3_x;
    int64_t _2_t8;
    int64_t* _2_t14;
    int64_t _2_t15;
    struct1 _3_y;
    int64_t _2_t16;
    int64_t _2_t17;
    uint8_t _2_t18;
    int64_t _2_t19;
    int64_t* _2_t20;
    int64_t* _2_t21;
    struct1 _3_z;
    int64_t _2_t23;
    int64_t _2_$retval;
    _2_t1 = 34;
    _2_t2 = 25;
    _2_t3 = 34;
    _2_t4 = 100;
    _2_t5 = 8;
    _2_t6 = 3;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4, _2_t5, _2_t6};
    _2_t8 = 0;
    _2_t14 = (((int64_t*)(&_3_x))+_2_t8);
    _2_t15 = 6;
    _3_y = (struct1) {_2_t14, _2_t15};
    _2_t16 = 3;
    _2_t17 = (&_3_y)->_1;
    _2_t18 = _2_t16 > _2_t17;
    if (_2_t18) {
        goto BB5;
    } else {
        goto BB6;
    }
BB6:
    _2_t19 = _2_t17 - _2_t16;
    _2_t20 = (&_3_y)->_0;
    _2_t21 = _2_t20 + _2_t16;
    _3_z = (struct1) {_2_t21, _2_t19};
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _2_t23 = _4_sum_up(_3_z);
    $line_idx--;
    _2_$retval = _2_t23;
    return _2_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    fprintf(stderr, "panic: subslice lower bound is greater than upper bound\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB6;
}

int64_t _4_sum_up(struct1 _4_xs) {
    int64_t _5_sum;
    int64_t _6_i;
    int64_t _4_t4;
    uint8_t _4_t3;
    int64_t _4_t6;
    uint8_t _4_t7;
    int64_t _4_t8;
    uint8_t _4_t9;
    int64_t _4_t5;
    int64_t _4_t11;
    int64_t _4_$retval;
    _5_sum = 0;
    _6_i = 0;
    goto BB1;
BB1:
    _4_t4 = (&_4_xs)->_1;
    _4_t3 = _6_i < _4_t4;
    if (_4_t3) {
        goto BB2;
    } else {
        goto BB14;
    }
BB14:
    _4_$retval = _5_sum;
    return _4_$retval;
BB2:
    _4_t6 = 0;
    _4_t7 = _6_i < _4_t6;
    if (_4_t7) {
        goto BB5;
    } else {
        goto BB6;
    }
BB6:
    _4_t8 = (&_4_xs)->_1;
    _4_t9 = _6_i >= _4_t8;
    if (_4_t9) {
        goto BB7;
    } else {
        goto BB8;
    }
BB8:
    _4_t5 = *(((int64_t*)((&_4_xs)->_0))+_6_i);
    _5_sum = _5_sum + _4_t5;
    _4_t11 = 1;
    _6_i = _6_i + _4_t11;
    goto BB1;
BB7:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:12:19:\n        sum += xs[i]\n                 ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB8;
BB5:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:12:19:\n        sum += xs[i]\n                 ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB6;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
