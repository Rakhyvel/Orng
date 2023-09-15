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
} struct0;
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t12;
    struct1 _3_y;
    int64_t _2_t15;
    int64_t _2_$retval;
    _3_x = (struct0) {0, 0, 0, 0};
    _2_t12 = (int64_t*)&_3_x;
    _3_y = (struct1) {_2_t12, 4};
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _2_t15 = _4_f();
    $line_idx--;
    if (_2_t15 < 0) {
        goto BB5;
    } else {
        goto BB6;
    }
BB5:
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:7:\n    y[f()] = 0\n     ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB6:
    if (_2_t15 >= _3_y._1) {
        goto BB7;
    } else {
        goto BB8;
    }
BB7:
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:7:\n    y[f()] = 0\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB8:
    *((int64_t*)_3_y._0 + _2_t15) = 0;
    _2_$retval = 0;
    return _2_$retval;
}

int64_t _4_f() {
    int64_t _4_$retval;
    _4_$retval = -100;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
