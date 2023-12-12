/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1234_main(void);
int64_t _1236_a(int64_t _1236_n);
int64_t _1238_b(int64_t _1238_n);
int64_t _1240_c(int64_t _1240_n);

/* Function definitions */
int64_t _1234_main(void) {
    function0 _1234_t0;
    int64_t _1234_t2;
    int64_t _1234_t1;
    int64_t _1234_$retval;
    _1234_t0 = _1236_a;
    _1234_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1234_t1 = _1234_t0(_1234_t2);
    $line_idx--;
    _1234_$retval = _1234_t1;
    return _1234_$retval;
}

int64_t _1236_a(int64_t _1236_n) {
    function0 _1236_t0;
    int64_t _1236_t1;
    int64_t _1236_$retval;
    _1236_t0 = _1238_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1236_t1 = _1236_t0(_1236_n);
    $line_idx--;
    _1236_$retval = _1236_t1;
    return _1236_$retval;
}

int64_t _1238_b(int64_t _1238_n) {
    function0 _1238_t0;
    int64_t _1238_t1;
    int64_t _1238_$retval;
    _1238_t0 = _1240_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1238_t1 = _1238_t0(_1238_n);
    $line_idx--;
    _1238_$retval = _1238_t1;
    return _1238_$retval;
}

int64_t _1240_c(int64_t _1240_n) {
    int64_t _1240_t1;
    uint8_t _1240_t3;
    function0 _1240_t5;
    int64_t _1240_t6;
    int64_t _1240_t0;
    int64_t _1240_$retval;
    _1240_t1 = 47;
    _1240_t3 = _1240_n == _1240_t1;
    if (_1240_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1240_t0 = 47;
    goto BB6;
BB7:
    _1240_t5 = _1236_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1240_t6 = _1240_t5(_1240_n);
    $line_idx--;
    _1240_t0 = _1240_t6;
    goto BB6;
BB6:
    _1240_$retval = _1240_t0;
    return _1240_$retval;
}

int main(void) {
  printf("%ld",_1234_main());
  return 0;
}
