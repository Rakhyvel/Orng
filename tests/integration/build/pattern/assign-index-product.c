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
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    struct1 _2_t4;
    int64_t _2_$retval;
    _3_x = (struct0) {0, 1, 2};
    _2_t4 = (struct1) {(*((int64_t*)&_3_x + 1)), (*(int64_t*)&_3_x)};
    *(int64_t*)&_3_x = _2_t4._0;
    *((int64_t*)&_3_x + 1) = _2_t4._1;
    if (*(int64_t*)&_3_x > *((int64_t*)&_3_x + 1)) {
        goto BB33;
    } else {
        goto BB40;
    }
BB33:
    _2_$retval = 162;
    return _2_$retval;
BB40:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
