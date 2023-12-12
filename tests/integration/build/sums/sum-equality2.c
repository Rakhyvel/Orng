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
int64_t _1137_main(void);
struct1 _1142_f(void);

/* Function definitions */
int64_t _1137_main(void) {
    function0 _1137_t1;
    struct1 _1137_t2;
    function0 _1137_t3;
    struct1 _1137_t4;
    uint64_t _1137_t7;
    uint64_t _1137_t8;
    uint8_t _1137_t6;
    int64_t _1137_t0;
    int64_t _1137_$retval;
    _1137_t1 = _1142_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1137_t2 = _1137_t1();
    $line_idx--;
    _1137_t3 = _1142_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1137_t4 = _1137_t3();
    $line_idx--;
    _1137_t7 = _1137_t2.tag;
    _1137_t8 = _1137_t4.tag;
    _1137_t6 = _1137_t7 == _1137_t8;
    if (_1137_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1137_t0 = 212;
    goto BB6;
BB7:
    _1137_t0 = -1;
    goto BB6;
BB6:
    _1137_$retval = _1137_t0;
    return _1137_$retval;
}

struct1 _1142_f(void) {
    struct1 _1142_$retval;
    _1142_$retval = (struct1) {.tag=0};
    return _1142_$retval;
}

int main(void) {
  printf("%ld",_1137_main());
  return 0;
}
