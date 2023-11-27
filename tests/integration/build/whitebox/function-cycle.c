/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1164_main(void);
int64_t _1166_a(int64_t _1166_n);
int64_t _1168_b(int64_t _1168_n);
int64_t _1170_c(int64_t _1170_n);

/* Function definitions */
int64_t _1164_main(void) {
    function0 _1164_t0;
    int64_t _1164_t2;
    int64_t _1164_t1;
    int64_t _1164_$retval;
    _1164_t0 = _1166_a;
    _1164_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1164_t1 = _1164_t0(_1164_t2);
    $line_idx--;
    _1164_$retval = _1164_t1;
    return _1164_$retval;
}

int64_t _1166_a(int64_t _1166_n) {
    function0 _1166_t0;
    int64_t _1166_t1;
    int64_t _1166_$retval;
    _1166_t0 = _1168_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1166_t1 = _1166_t0(_1166_n);
    $line_idx--;
    _1166_$retval = _1166_t1;
    return _1166_$retval;
}

int64_t _1168_b(int64_t _1168_n) {
    function0 _1168_t0;
    int64_t _1168_t1;
    int64_t _1168_$retval;
    _1168_t0 = _1170_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1168_t1 = _1168_t0(_1168_n);
    $line_idx--;
    _1168_$retval = _1168_t1;
    return _1168_$retval;
}

int64_t _1170_c(int64_t _1170_n) {
    int64_t _1170_t1;
    uint8_t _1170_t3;
    function0 _1170_t5;
    int64_t _1170_t6;
    int64_t _1170_t0;
    int64_t _1170_$retval;
    _1170_t1 = 47;
    _1170_t3 = _1170_n == _1170_t1;
    if (_1170_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1170_t0 = 47;
    goto BB6;
BB7:
    _1170_t5 = _1166_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1170_t6 = _1170_t5(_1170_n);
    $line_idx--;
    _1170_t0 = _1170_t6;
    goto BB6;
BB6:
    _1170_$retval = _1170_t0;
    return _1170_$retval;
}

int main(void) {
  printf("%ld",_1164_main());
  return 0;
}
