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
        int64_t _0;
    };
} struct1;

typedef struct1(*function0)(void);

/* Function forward definitions */
int64_t _1462_main(void);
struct1 _1467_f(void);

/* Function definitions */
int64_t _1462_main(void){
    function0 _1462_t1;
    struct1 _1462_t2;
    function0 _1462_t3;
    struct1 _1462_t4;
    uint64_t _1462_t7;
    uint64_t _1462_t8;
    uint8_t _1462_t6;
    int64_t _1462_t0;
    int64_t _1462_$retval;
    _1462_t1 = _1467_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1462_t2 = _1462_t1();
    $line_idx--;
    _1462_t3 = _1467_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1462_t4 = _1462_t3();
    $line_idx--;
    _1462_t7 = _1462_t2.tag;
    _1462_t8 = _1462_t4.tag;
    _1462_t6 = _1462_t7==_1462_t8;
    if (_1462_t6) {
        goto BB1738;
    } else {
        goto BB1742;
    }
BB1738:
    _1462_t0 = 212;
    goto BB1741;
BB1742:
    _1462_t0 = -1;
    goto BB1741;
BB1741:
    _1462_$retval = _1462_t0;
    return _1462_$retval;
}

struct1 _1467_f(void){
    struct1 _1467_$retval;
    _1467_$retval = (struct1) {.tag=1};
    return _1467_$retval;
}

int main(void) {
  printf("%ld",_1462_main());
  return 0;
}
