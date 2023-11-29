/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1287_main(void);
int64_t _1289_a(int64_t _1289_n);
int64_t _1291_b(int64_t _1291_n);
int64_t _1293_c(int64_t _1293_n);

/* Function definitions */
int64_t _1287_main(void) {
    function0 _1287_t0;
    int64_t _1287_t2;
    int64_t _1287_t1;
    int64_t _1287_$retval;
    _1287_t0 = _1289_a;
    _1287_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1287_t1 = _1287_t0(_1287_t2);
    $line_idx--;
    _1287_$retval = _1287_t1;
    return _1287_$retval;
}

int64_t _1289_a(int64_t _1289_n) {
    function0 _1289_t0;
    int64_t _1289_t1;
    int64_t _1289_$retval;
    _1289_t0 = _1291_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1289_t1 = _1289_t0(_1289_n);
    $line_idx--;
    _1289_$retval = _1289_t1;
    return _1289_$retval;
}

int64_t _1291_b(int64_t _1291_n) {
    function0 _1291_t0;
    int64_t _1291_t1;
    int64_t _1291_$retval;
    _1291_t0 = _1293_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1291_t1 = _1291_t0(_1291_n);
    $line_idx--;
    _1291_$retval = _1291_t1;
    return _1291_$retval;
}

int64_t _1293_c(int64_t _1293_n) {
    int64_t _1293_t1;
    uint8_t _1293_t3;
    function0 _1293_t5;
    int64_t _1293_t6;
    int64_t _1293_t0;
    int64_t _1293_$retval;
    _1293_t1 = 47;
    _1293_t3 = _1293_n == _1293_t1;
    if (_1293_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1293_t0 = 47;
    goto BB6;
BB7:
    _1293_t5 = _1289_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1293_t6 = _1293_t5(_1293_n);
    $line_idx--;
    _1293_t0 = _1293_t6;
    goto BB6;
BB6:
    _1293_$retval = _1293_t0;
    return _1293_$retval;
}

int main(void) {
  printf("%ld",_1287_main());
  return 0;
}
