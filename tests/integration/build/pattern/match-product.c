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
} struct0;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    int64_t _5_x;
    int64_t _5_y;
    int64_t _2_$retval;
    _2_t1 = (struct0) {100, 60, 8};
    if (_2_t1._0 == 100) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _5_x = _2_t1._1;
    _5_y = _2_t1._2;
    _2_$retval = 100 + _5_x + _5_y;
    return _2_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
