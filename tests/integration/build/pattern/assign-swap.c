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

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t0;
    int64_t _3_x;
    int64_t _3_y;
    struct0 _2_t5;
    int64_t _2_$retval;
    _2_t0 = (struct0) {1, 2};
    _3_x = _2_t0._0;
    _3_y = _2_t0._1;
    _2_t5 = (struct0) {_3_x, _3_y};
    _3_y = _2_t5._0;
    _3_x = _2_t5._1;
    if (_3_y == 1) {
        goto BB1;
    } else {
        goto BB11;
    }
BB11:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB1:
    if (_3_x == 2) {
        goto BB4;
    } else {
        goto BB11;
    }
BB4:
    _2_$retval = 159;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
