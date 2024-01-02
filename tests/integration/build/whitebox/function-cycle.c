/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1597_main(void);
int64_t _1599_a(int64_t _1599_n);
int64_t _1601_b(int64_t _1601_n);
int64_t _1603_c(int64_t _1603_n);

/* Function definitions */
int64_t _1597_main(void){
    function0 _1597_t0;
    int64_t _1597_t2;
    int64_t _1597_t1;
    int64_t _1597_$retval;
    _1597_t0 = _1599_a;
    _1597_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1597_t1 = _1597_t0(_1597_t2);
    $line_idx--;
    _1597_$retval = _1597_t1;
    return _1597_$retval;
}

int64_t _1599_a(int64_t _1599_n){
    function0 _1599_t0;
    int64_t _1599_t1;
    int64_t _1599_$retval;
    _1599_t0 = _1601_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1599_t1 = _1599_t0(_1599_n);
    $line_idx--;
    _1599_$retval = _1599_t1;
    return _1599_$retval;
}

int64_t _1601_b(int64_t _1601_n){
    function0 _1601_t0;
    int64_t _1601_t1;
    int64_t _1601_$retval;
    _1601_t0 = _1603_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1601_t1 = _1601_t0(_1601_n);
    $line_idx--;
    _1601_$retval = _1601_t1;
    return _1601_$retval;
}

int64_t _1603_c(int64_t _1603_n){
    int64_t _1603_t1;
    uint8_t _1603_t3;
    function0 _1603_t5;
    int64_t _1603_t6;
    int64_t _1603_t0;
    int64_t _1603_$retval;
    _1603_t1 = 47;
    _1603_t3 = _1603_n==_1603_t1;
    if (_1603_t3) {
        goto BB1879;
    } else {
        goto BB1883;
    }
BB1879:
    _1603_t0 = 47;
    goto BB1882;
BB1883:
    _1603_t5 = _1599_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1603_t6 = _1603_t5(_1603_n);
    $line_idx--;
    _1603_t0 = _1603_t6;
    goto BB1882;
BB1882:
    _1603_$retval = _1603_t0;
    return _1603_$retval;
}

int main(void) {
  printf("%ld",_1597_main());
  return 0;
}
