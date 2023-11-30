/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1653_main(void);
int64_t _1655_a(int64_t _1655_n);
int64_t _1658_b(int64_t _1658_n);
int64_t _1661_c(int64_t _1661_n);

/* Function definitions */
int64_t _1653_main(void) {
    function0 _1653_t0;
    int64_t _1653_t2;
    int64_t _1653_t1;
    int64_t _1653_$retval;
    _1653_t0 = _1655_a;
    _1653_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1653_t1 = _1653_t0(_1653_t2);
    $line_idx--;
    _1653_$retval = _1653_t1;
    return _1653_$retval;
}

int64_t _1655_a(int64_t _1655_n) {
    function0 _1655_t0;
    int64_t _1655_t1;
    int64_t _1655_$retval;
    _1655_t0 = _1658_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1655_t1 = _1655_t0(_1655_n);
    $line_idx--;
    _1655_$retval = _1655_t1;
    return _1655_$retval;
}

int64_t _1658_b(int64_t _1658_n) {
    function0 _1658_t0;
    int64_t _1658_t1;
    int64_t _1658_$retval;
    _1658_t0 = _1661_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1658_t1 = _1658_t0(_1658_n);
    $line_idx--;
    _1658_$retval = _1658_t1;
    return _1658_$retval;
}

int64_t _1661_c(int64_t _1661_n) {
    int64_t _1661_t1;
    uint8_t _1661_t3;
    function0 _1661_t5;
    int64_t _1661_t6;
    int64_t _1661_t0;
    int64_t _1661_$retval;
    _1661_t1 = 47;
    _1661_t3 = _1661_n == _1661_t1;
    if (_1661_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1661_t0 = 47;
    goto BB6;
BB7:
    _1661_t5 = _1655_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1661_t6 = _1661_t5(_1661_n);
    $line_idx--;
    _1661_t0 = _1661_t6;
    goto BB6;
BB6:
    _1661_$retval = _1661_t0;
    return _1661_$retval;
}

int main(void) {
  printf("%ld",_1653_main());
  return 0;
}
