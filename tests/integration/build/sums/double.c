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
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
} struct0;
typedef struct {
    uint64_t tag;
    union {
        struct0 _0;
    };
} struct1;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t1;
    struct1 _3_x;
    struct0 _2_t8;
    int64_t _2_$retval;
    _2_t1 = (struct0) {.tag=0, ._0=4};
    _3_x = (struct1) {.tag=0, ._0=_2_t1};
    _3_x._0._0 = 104;
    _2_t8 = _3_x._0;
    if (_2_t8.tag != 0) {
        goto BB5;
    } else {
        goto BB6;
    }
BB5:
    $lines[$line_idx++] = "tests/integration/sums/double.orng:5:14:\n    x.sum.int\n            ^";
    fprintf(stderr, "panic: access of inactive sum field\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB6:
    _2_$retval = _2_t8._0;
    return _2_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
