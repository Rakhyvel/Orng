/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1465_main(void);
struct struct1 _1470_f(void);

/* Function definitions */
int64_t _1465_main(void){
    function0 _1465_t1;
    struct struct1 _1465_t2;
    function0 _1465_t3;
    struct struct1 _1465_t4;
    uint64_t _1465_t7;
    uint64_t _1465_t8;
    uint8_t _1465_t6;
    int64_t _1465_t0;
    int64_t _1465_$retval;
    _1465_t1 = _1470_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1465_t2 = _1465_t1();
    $line_idx--;
    _1465_t3 = _1470_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1465_t4 = _1465_t3();
    $line_idx--;
    _1465_t7 = _1465_t2.tag;
    _1465_t8 = _1465_t4.tag;
    _1465_t6 = _1465_t7==_1465_t8;
    if (_1465_t6) {
        goto BB1730;
    } else {
        goto BB1734;
    }
BB1730:
    _1465_t0 = 212;
    goto BB1733;
BB1734:
    _1465_t0 = -1;
    goto BB1733;
BB1733:
    _1465_$retval = _1465_t0;
    return _1465_$retval;
}

struct struct1 _1470_f(void){
    struct struct1 _1470_$retval;
    _1470_$retval = (struct struct1) {.tag=1};
    return _1470_$retval;
}

int main(void) {
  printf("%ld",_1465_main());
  return 0;
}
