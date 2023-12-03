/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1202_main(void);
int64_t _1204_a(int64_t _1204_n);
int64_t _1206_b(int64_t _1206_n);
int64_t _1208_c(int64_t _1208_n);

/* Function definitions */
int64_t _1202_main(void) {
    function0 _1202_t0;
    int64_t _1202_t2;
    int64_t _1202_t1;
    int64_t _1202_$retval;
    _1202_t0 = _1204_a;
    _1202_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1202_t1 = _1202_t0(_1202_t2);
    $line_idx--;
    _1202_$retval = _1202_t1;
    return _1202_$retval;
}

int64_t _1204_a(int64_t _1204_n) {
    function0 _1204_t0;
    int64_t _1204_t1;
    int64_t _1204_$retval;
    _1204_t0 = _1206_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1204_t1 = _1204_t0(_1204_n);
    $line_idx--;
    _1204_$retval = _1204_t1;
    return _1204_$retval;
}

int64_t _1206_b(int64_t _1206_n) {
    function0 _1206_t0;
    int64_t _1206_t1;
    int64_t _1206_$retval;
    _1206_t0 = _1208_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1206_t1 = _1206_t0(_1206_n);
    $line_idx--;
    _1206_$retval = _1206_t1;
    return _1206_$retval;
}

int64_t _1208_c(int64_t _1208_n) {
    int64_t _1208_t1;
    uint8_t _1208_t3;
    function0 _1208_t5;
    int64_t _1208_t6;
    int64_t _1208_t0;
    int64_t _1208_$retval;
    _1208_t1 = 47;
    _1208_t3 = _1208_n == _1208_t1;
    if (_1208_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1208_t0 = 47;
    goto BB6;
BB7:
    _1208_t5 = _1204_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1208_t6 = _1208_t5(_1208_n);
    $line_idx--;
    _1208_t0 = _1208_t6;
    goto BB6;
BB6:
    _1208_$retval = _1208_t0;
    return _1208_$retval;
}

int main(void) {
  printf("%ld",_1202_main());
  return 0;
}
