/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693027203572244591
#define ORNG_1693027203572244591

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

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

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t0;
    struct0 _2_t1;
    struct1 _3_x;
    int64_t _2_t3;
    struct0 _2_t8;
    int64_t _2_t13;
    int64_t _2_t14;
    uint8_t _2_t15;
    int64_t _2_$retval;
BB0:
    _2_t0 = 4;
    _2_t1 = (struct0) {.tag=0, ._0=_2_t0};
    _3_x = (struct1) {.tag=0, ._0=_2_t1};
    _2_t3 = 104;
    (&((&_3_x)->_0))->_0 = _2_t3;
    _2_t8 = (&_3_x)->_0;
    _2_t13 = 0;
    _2_t14 = _2_t8.tag;
    _2_t15 = _2_t14 != _2_t13;
    if (_2_t15) {
        goto BB5;
    } else {
        goto BB6;
    }
BB6:
    _2_$retval = (&_2_t8)->_0;
    return _2_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/sums/double.orng:5:14:\n    x.sum.int\n            ^";
    fprintf(stderr, "panic: access of inactive sum field\n");
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

#endif
