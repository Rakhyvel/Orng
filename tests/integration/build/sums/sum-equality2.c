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
int64_t _1589_main(void);
struct1 _1594_f(void);

/* Function definitions */
int64_t _1589_main(void){
    function0 _1589_t1;
    struct1 _1589_t2;
    function0 _1589_t3;
    struct1 _1589_t4;
    uint64_t _1589_t7;
    uint64_t _1589_t8;
    uint8_t _1589_t6;
    int64_t _1589_t0;
    int64_t _1589_$retval;
    _1589_t1 = _1594_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1589_t2 = _1589_t1();
    $line_idx--;
    _1589_t3 = _1594_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1589_t4 = _1589_t3();
    $line_idx--;
    _1589_t7 = _1589_t2.tag;
    _1589_t8 = _1589_t4.tag;
    _1589_t6 = _1589_t7 == _1589_t8;
    if (_1589_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1589_t0 = 212;
    goto BB6;
BB7:
    _1589_t0 = -1;
    goto BB6;
BB6:
    _1589_$retval = _1589_t0;
    return _1589_$retval;
}

struct1 _1594_f(void){
    struct1 _1594_$retval;
    _1594_$retval = (struct1) {.tag=0};
    return _1594_$retval;
}

int main(void) {
  printf("%ld",_1589_main());
  return 0;
}
