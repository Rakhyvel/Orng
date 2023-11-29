/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1651_main(void);
int64_t _1653_a(int64_t _1653_n);
int64_t _1656_b(int64_t _1656_n);
int64_t _1659_c(int64_t _1659_n);

/* Function definitions */
int64_t _1651_main(void) {
    function0 _1651_t0;
    int64_t _1651_t2;
    int64_t _1651_t1;
    int64_t _1651_$retval;
    _1651_t0 = _1653_a;
    _1651_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1651_t1 = _1651_t0(_1651_t2);
    $line_idx--;
    _1651_$retval = _1651_t1;
    return _1651_$retval;
}

int64_t _1653_a(int64_t _1653_n) {
    function0 _1653_t0;
    int64_t _1653_t1;
    int64_t _1653_$retval;
    _1653_t0 = _1656_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1653_t1 = _1653_t0(_1653_n);
    $line_idx--;
    _1653_$retval = _1653_t1;
    return _1653_$retval;
}

int64_t _1656_b(int64_t _1656_n) {
    function0 _1656_t0;
    int64_t _1656_t1;
    int64_t _1656_$retval;
    _1656_t0 = _1659_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1656_t1 = _1656_t0(_1656_n);
    $line_idx--;
    _1656_$retval = _1656_t1;
    return _1656_$retval;
}

int64_t _1659_c(int64_t _1659_n) {
    int64_t _1659_t1;
    uint8_t _1659_t3;
    function0 _1659_t5;
    int64_t _1659_t6;
    int64_t _1659_t0;
    int64_t _1659_$retval;
    _1659_t1 = 47;
    _1659_t3 = _1659_n == _1659_t1;
    if (_1659_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1659_t0 = 47;
    goto BB6;
BB7:
    _1659_t5 = _1653_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1659_t6 = _1659_t5(_1659_n);
    $line_idx--;
    _1659_t0 = _1659_t6;
    goto BB6;
BB6:
    _1659_$retval = _1659_t0;
    return _1659_$retval;
}

int main(void) {
  printf("%ld",_1651_main());
  return 0;
}
