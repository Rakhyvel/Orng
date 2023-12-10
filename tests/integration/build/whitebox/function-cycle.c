/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1226_main(void);
int64_t _1228_a(int64_t _1228_n);
int64_t _1230_b(int64_t _1230_n);
int64_t _1232_c(int64_t _1232_n);

/* Function definitions */
int64_t _1226_main(void) {
    function0 _1226_t0;
    int64_t _1226_t2;
    int64_t _1226_t1;
    int64_t _1226_$retval;
    _1226_t0 = _1228_a;
    _1226_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1226_t1 = _1226_t0(_1226_t2);
    $line_idx--;
    _1226_$retval = _1226_t1;
    return _1226_$retval;
}

int64_t _1228_a(int64_t _1228_n) {
    function0 _1228_t0;
    int64_t _1228_t1;
    int64_t _1228_$retval;
    _1228_t0 = _1230_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1228_t1 = _1228_t0(_1228_n);
    $line_idx--;
    _1228_$retval = _1228_t1;
    return _1228_$retval;
}

int64_t _1230_b(int64_t _1230_n) {
    function0 _1230_t0;
    int64_t _1230_t1;
    int64_t _1230_$retval;
    _1230_t0 = _1232_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1230_t1 = _1230_t0(_1230_n);
    $line_idx--;
    _1230_$retval = _1230_t1;
    return _1230_$retval;
}

int64_t _1232_c(int64_t _1232_n) {
    int64_t _1232_t1;
    uint8_t _1232_t3;
    function0 _1232_t5;
    int64_t _1232_t6;
    int64_t _1232_t0;
    int64_t _1232_$retval;
    _1232_t1 = 47;
    _1232_t3 = _1232_n == _1232_t1;
    if (_1232_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1232_t0 = 47;
    goto BB6;
BB7:
    _1232_t5 = _1228_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1232_t6 = _1232_t5(_1232_n);
    $line_idx--;
    _1232_t0 = _1232_t6;
    goto BB6;
BB6:
    _1232_$retval = _1232_t0;
    return _1232_$retval;
}

int main(void) {
  printf("%ld",_1226_main());
  return 0;
}
