/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1630_main(void);
int64_t _1632_a(int64_t _1632_n);
int64_t _1635_b(int64_t _1635_n);
int64_t _1638_c(int64_t _1638_n);

/* Function definitions */
int64_t _1630_main(void) {
    function0 _1630_t0;
    int64_t _1630_t2;
    int64_t _1630_t1;
    int64_t _1630_$retval;
    _1630_t0 = _1632_a;
    _1630_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1630_t1 = _1630_t0(_1630_t2);
    $line_idx--;
    _1630_$retval = _1630_t1;
    return _1630_$retval;
}

int64_t _1632_a(int64_t _1632_n) {
    function0 _1632_t0;
    int64_t _1632_t1;
    int64_t _1632_$retval;
    _1632_t0 = _1635_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1632_t1 = _1632_t0(_1632_n);
    $line_idx--;
    _1632_$retval = _1632_t1;
    return _1632_$retval;
}

int64_t _1635_b(int64_t _1635_n) {
    function0 _1635_t0;
    int64_t _1635_t1;
    int64_t _1635_$retval;
    _1635_t0 = _1638_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1635_t1 = _1635_t0(_1635_n);
    $line_idx--;
    _1635_$retval = _1635_t1;
    return _1635_$retval;
}

int64_t _1638_c(int64_t _1638_n) {
    int64_t _1638_t1;
    uint8_t _1638_t3;
    function0 _1638_t5;
    int64_t _1638_t6;
    int64_t _1638_t0;
    int64_t _1638_$retval;
    _1638_t1 = 47;
    _1638_t3 = _1638_n == _1638_t1;
    if (_1638_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1638_t0 = 47;
    goto BB6;
BB7:
    _1638_t5 = _1632_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1638_t6 = _1638_t5(_1638_n);
    $line_idx--;
    _1638_t0 = _1638_t6;
    goto BB6;
BB6:
    _1638_$retval = _1638_t0;
    return _1638_$retval;
}

int main(void) {
  printf("%ld",_1630_main());
  return 0;
}
