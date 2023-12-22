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
int64_t _1437_main(void);
struct1 _1442_f(void);

/* Function definitions */
int64_t _1437_main(void){
    function0 _1437_t1;
    struct1 _1437_t2;
    function0 _1437_t3;
    struct1 _1437_t4;
    uint64_t _1437_t7;
    uint64_t _1437_t8;
    uint8_t _1437_t6;
    int64_t _1437_t0;
    int64_t _1437_$retval;
    _1437_t1 = _1442_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1437_t2 = _1437_t1();
    $line_idx--;
    _1437_t3 = _1442_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1437_t4 = _1437_t3();
    $line_idx--;
    _1437_t7 = _1437_t2.tag;
    _1437_t8 = _1437_t4.tag;
    _1437_t6 = _1437_t7 == _1437_t8;
    if (_1437_t6) {
        goto BB1758;
    } else {
        goto BB1762;
    }
BB1758:
    _1437_t0 = 212;
    goto BB1761;
BB1762:
    _1437_t0 = -1;
    goto BB1761;
BB1761:
    _1437_$retval = _1437_t0;
    return _1437_$retval;
}

struct1 _1442_f(void){
    struct1 _1442_$retval;
    _1442_$retval = (struct1) {.tag=0};
    return _1442_$retval;
}

int main(void) {
  printf("%ld",_1437_main());
  return 0;
}
