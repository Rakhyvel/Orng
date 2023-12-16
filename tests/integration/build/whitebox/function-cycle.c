/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1589_main(void);
int64_t _1591_a(int64_t _1591_n);
int64_t _1593_b(int64_t _1593_n);
int64_t _1595_c(int64_t _1595_n);

/* Function definitions */
int64_t _1589_main(void) {
    function0 _1589_t0;
    int64_t _1589_t2;
    int64_t _1589_t1;
    int64_t _1589_$retval;
    _1589_t0 = _1591_a;
    _1589_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1589_t1 = _1589_t0(_1589_t2);
    $line_idx--;
    _1589_$retval = _1589_t1;
    return _1589_$retval;
}

int64_t _1591_a(int64_t _1591_n) {
    function0 _1591_t0;
    int64_t _1591_t1;
    int64_t _1591_$retval;
    _1591_t0 = _1593_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1591_t1 = _1591_t0(_1591_n);
    $line_idx--;
    _1591_$retval = _1591_t1;
    return _1591_$retval;
}

int64_t _1593_b(int64_t _1593_n) {
    function0 _1593_t0;
    int64_t _1593_t1;
    int64_t _1593_$retval;
    _1593_t0 = _1595_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1593_t1 = _1593_t0(_1593_n);
    $line_idx--;
    _1593_$retval = _1593_t1;
    return _1593_$retval;
}

int64_t _1595_c(int64_t _1595_n) {
    int64_t _1595_t1;
    uint8_t _1595_t3;
    function0 _1595_t5;
    int64_t _1595_t6;
    int64_t _1595_t0;
    int64_t _1595_$retval;
    _1595_t1 = 47;
    _1595_t3 = _1595_n == _1595_t1;
    if (_1595_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1595_t0 = 47;
    goto BB6;
BB7:
    _1595_t5 = _1591_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1595_t6 = _1595_t5(_1595_n);
    $line_idx--;
    _1595_t0 = _1595_t6;
    goto BB6;
BB6:
    _1595_$retval = _1595_t0;
    return _1595_$retval;
}

int main(void) {
  printf("%ld",_1589_main());
  return 0;
}
