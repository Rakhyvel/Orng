/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693365762791687388
#define ORNG_1693365762791687388

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
        int64_t _1;
    };
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_f();

/* Function definitions */
int64_t _2_main() {
    struct0 _2_t0;
    struct0 _3_x;
    int64_t _2_t2;
    int64_t _2_t3;
    uint8_t _2_t4;
    int64_t _2_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:3:15:\n    let x = f()\n             ^";
    _2_t0 = _4_f();
    $line_idx--;
    _3_x = _2_t0;
    _2_t2 = 1;
    _2_t3 = _3_x.tag;
    _2_t4 = _2_t3 != _2_t2;
    if (_2_t4) {
        goto BB1;
    } else {
        goto BB2;
    }
BB2:
    _2_$retval = (&_3_x)->_1;
    return _2_$retval;
BB1:
    $lines[$line_idx++] = "tests/integration/lint/inactive-select.orng:4:8:\n    x.b\n      ^";
    fprintf(stderr, "panic: access of inactive sum field\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB2;
}

struct0 _4_f() {
    int64_t _4_t0;
    struct0 _4_$retval;
BB0:
    _4_t0 = 4;
    _4_$retval = (struct0) {.tag=0, ._0=_4_t0};
    return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
