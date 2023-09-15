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

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t _2_t5;
    int64_t _2_$retval;
    _3_x = (struct0) {0, 0, 0, 0};
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _2_t5 = _4_f();
    $line_idx--;
    if (_2_t5 < 0) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:7:\n    x[f()]\n     ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB2:
    if (_2_t5 >= 4) {
        goto BB3;
    } else {
        goto BB4;
    }
BB3:
    $lines[$line_idx++] = "tests/integration/lint/array-pos-bounds-check.orng:4:7:\n    x[f()]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB4:
    _2_$retval = *((int64_t*)&_3_x + _2_t5);
    return _2_$retval;
}

int64_t _4_f() {
    int64_t _4_$retval;
    _4_$retval = 100;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
