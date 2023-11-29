/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _1451_main(void);
struct1 _1456_f(void);

/* Function definitions */
int64_t _1451_main(void) {
    function0 _1451_t1;
    struct1 _1451_t2;
    function0 _1451_t3;
    struct1 _1451_t4;
    uint64_t _1451_t7;
    uint64_t _1451_t8;
    uint8_t _1451_t6;
    int64_t _1451_t0;
    int64_t _1451_$retval;
    _1451_t1 = _1456_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1451_t2 = _1451_t1();
    $line_idx--;
    _1451_t3 = _1456_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1451_t4 = _1451_t3();
    $line_idx--;
    _1451_t7 = _1451_t2.tag;
    _1451_t8 = _1451_t4.tag;
    _1451_t6 = _1451_t7 == _1451_t8;
    if (_1451_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1451_t0 = 212;
    goto BB6;
BB7:
    _1451_t0 = -1;
    goto BB6;
BB6:
    _1451_$retval = _1451_t0;
    return _1451_$retval;
}

struct1 _1456_f(void) {
    struct1 _1456_$retval;
    _1456_$retval = (struct1) {.tag=0};
    return _1456_$retval;
}

int main(void) {
  printf("%ld",_1451_main());
  return 0;
}
