/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1133_main(void);
int64_t _1135_a(int64_t _1135_n);
int64_t _1137_b(int64_t _1137_n);
int64_t _1139_c(int64_t _1139_n);

/* Function definitions */
int64_t _1133_main(void) {
    function0 _1133_t0;
    int64_t _1133_t2;
    int64_t _1133_t1;
    int64_t _1133_$retval;
    _1133_t0 = _1135_a;
    _1133_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1133_t1 = _1133_t0(_1133_t2);
    $line_idx--;
    _1133_$retval = _1133_t1;
    return _1133_$retval;
}

int64_t _1135_a(int64_t _1135_n) {
    function0 _1135_t0;
    int64_t _1135_t1;
    int64_t _1135_$retval;
    _1135_t0 = _1137_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1135_t1 = _1135_t0(_1135_n);
    $line_idx--;
    _1135_$retval = _1135_t1;
    return _1135_$retval;
}

int64_t _1137_b(int64_t _1137_n) {
    function0 _1137_t0;
    int64_t _1137_t1;
    int64_t _1137_$retval;
    _1137_t0 = _1139_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1137_t1 = _1137_t0(_1137_n);
    $line_idx--;
    _1137_$retval = _1137_t1;
    return _1137_$retval;
}

int64_t _1139_c(int64_t _1139_n) {
    int64_t _1139_t1;
    uint8_t _1139_t3;
    uint8_t _1139_t2;
    int64_t _1139_t0;
    function0 _1139_t5;
    int64_t _1139_t6;
    int64_t _1139_$retval;
    _1139_t1 = 47;
    _1139_t3 = _1139_n == _1139_t1;
    if (_1139_t3) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1139_t2 = 1;
    goto BB2;
BB9:
    _1139_t2 = 0;
    goto BB2;
BB2:
    if (_1139_t2) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1139_t0 = 47;
    goto BB6;
BB7:
    _1139_t5 = _1135_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1139_t6 = _1139_t5(_1139_n);
    $line_idx--;
    _1139_t0 = _1139_t6;
    goto BB6;
BB6:
    _1139_$retval = _1139_t0;
    return _1139_$retval;
}

int main(void) {
  printf("%ld",_1133_main());
  return 0;
}
