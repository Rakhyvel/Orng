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
int64_t _1500_main(void);
struct struct1 _1505_f(void);


/* Function definitions */
int64_t _1500_main(void){
    function0 _1500_t1;
    struct struct1 _1500_t2;
    function0 _1500_t3;
    struct struct1 _1500_t4;
    uint64_t _1500_t7;
    uint64_t _1500_t8;
    uint8_t _1500_t6;
    int64_t _1500_t0;
    int64_t _1500_$retval;
    _1500_t1 = (function0) _1505_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:10:\n    if f() == f() {\n        ^";
    _1500_t2 = _1500_t1();
    $line_idx--;
    _1500_t3 = (function0) _1505_f;
    $lines[$line_idx++] = "tests/integration/sums/sum-equality2.orng:3:17:\n    if f() == f() {\n               ^";
    _1500_t4 = _1500_t3();
    $line_idx--;
    _1500_t7 = _1500_t2.tag;
    _1500_t8 = _1500_t4.tag;
    _1500_t6 = _1500_t7==_1500_t8;
    if (_1500_t6) {
        goto BB1727;
    } else {
        goto BB1731;
    }
BB1727:
    _1500_t0 = 212;
    goto BB1730;
BB1731:
    _1500_t0 = -1;
    goto BB1730;
BB1730:
    _1500_$retval = _1500_t0;
    return _1500_$retval;
}

struct struct1 _1505_f(void){
    struct struct1 _1505_$retval;
    _1505_$retval = (struct struct1) {.tag=1};
    return _1505_$retval;
}


int main(void) {
  printf("%ld",_1500_main());
  return 0;
}
