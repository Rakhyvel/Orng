/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

typedef struct struct1(*function0)(void);

/* Function forward definitions */
int64_t _1539_main(void);
struct struct1 _1544_f(void);


/* Function definitions */
int64_t _1539_main(void){
    function0 _1539_t1;
    struct struct1 _1539_t2;
    function0 _1539_t3;
    struct struct1 _1539_t4;
    uint64_t _1539_t7;
    uint64_t _1539_t8;
    uint8_t _1539_t6;
    int64_t _1539_t0;
    int64_t _1539_$retval;
    _1539_t1 = (function0) _1544_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1539_t2 = _1539_t1();
    $line_idx--;
    _1539_t3 = (function0) _1544_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1539_t4 = _1539_t3();
    $line_idx--;
    _1539_t7 = _1539_t2.tag;
    _1539_t8 = _1539_t4.tag;
    _1539_t6 = _1539_t7==_1539_t8;
    if (_1539_t6) {
        goto BB1775;
    } else {
        goto BB1779;
    }
BB1775:
    _1539_t0 = 212;
    goto BB1778;
BB1779:
    _1539_t0 = -1;
    goto BB1778;
BB1778:
    _1539_$retval = _1539_t0;
    return _1539_$retval;
}

struct struct1 _1544_f(void){
    struct struct1 _1544_$retval;
    _1544_$retval = (struct struct1) {.tag=1};
    return _1544_$retval;
}


int main(void) {
  printf("%ld",_1539_main());
  return 0;
}
