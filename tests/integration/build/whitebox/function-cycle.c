/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1701_main(void);
int64_t _1703_a(int64_t _1703_n);
int64_t _1705_b(int64_t _1705_n);
int64_t _1707_c(int64_t _1707_n);


/* Function definitions */
int64_t _1701_main(void){
    function0 _1701_t0;
    int64_t _1701_t2;
    int64_t _1701_t1;
    int64_t _1701_$retval;
    _1701_t0 = _1703_a;
    _1701_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1701_t1 = _1701_t0(_1701_t2);
    $line_idx--;
    _1701_$retval = _1701_t1;
    return _1701_$retval;
}

int64_t _1703_a(int64_t _1703_n){
    function0 _1703_t0;
    int64_t _1703_t1;
    int64_t _1703_$retval;
    _1703_t0 = _1705_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1703_t1 = _1703_t0(_1703_n);
    $line_idx--;
    _1703_$retval = _1703_t1;
    return _1703_$retval;
}

int64_t _1705_b(int64_t _1705_n){
    function0 _1705_t0;
    int64_t _1705_t1;
    int64_t _1705_$retval;
    _1705_t0 = _1707_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1705_t1 = _1705_t0(_1705_n);
    $line_idx--;
    _1705_$retval = _1705_t1;
    return _1705_$retval;
}

int64_t _1707_c(int64_t _1707_n){
    int64_t _1707_t1;
    uint8_t _1707_t3;
    function0 _1707_t5;
    int64_t _1707_t6;
    int64_t _1707_t0;
    int64_t _1707_$retval;
    _1707_t1 = 47;
    _1707_t3 = _1707_n==_1707_t1;
    if (_1707_t3) {
        goto BB1964;
    } else {
        goto BB1968;
    }
BB1964:
    _1707_t0 = 47;
    goto BB1967;
BB1968:
    _1707_t5 = _1703_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1707_t6 = _1707_t5(_1707_n);
    $line_idx--;
    _1707_t0 = _1707_t6;
    goto BB1967;
BB1967:
    _1707_$retval = _1707_t0;
    return _1707_$retval;
}


int main(void) {
  printf("%ld",_1701_main());
  return 0;
}
