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
    struct0 _3_x;
    int64_t* _2_t21;
    struct1 _3_z;
    int64_t _2_t23;
    int64_t _2_$retval;
    _3_x = (struct0) {100, 8, 2, 4, 35, 6};
    _2_t21 = (int64_t*)&_3_x;
    _3_z = (struct1) {_2_t21, 3};
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _2_t23 = _4_sum_up(_3_z);
    $line_idx--;
    _2_$retval = _2_t23;
    return _2_$retval;
}

int64_t _4_sum_up(struct1 _4_xs) {
    int64_t _5_sum;
    int64_t _6_i;
    int64_t _4_$retval;
    _5_sum = 0;
    _6_i = 0;
BB1:
    if (_6_i < _4_xs._1) {
        goto BB4;
    } else {
        goto BB13;
    }
BB4:
    if (_6_i < 0) {
        goto BB5;
    } else {
        goto BB6;
    }
BB13:
    _4_$retval = _5_sum;
    return _4_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:12:19:\n        sum += xs[i]\n                 ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB6:
    if (_6_i >= _4_xs._1) {
        goto BB7;
    } else {
        goto BB8;
    }
BB7:
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:12:19:\n        sum += xs[i]\n                 ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB8:
    _5_sum = _5_sum + *((int64_t*)_4_xs._0 + _6_i);
    _6_i = _6_i + 1;
    goto BB1;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
