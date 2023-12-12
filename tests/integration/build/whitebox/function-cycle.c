/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1253_main(void);
int64_t _1255_a(int64_t _1255_n);
int64_t _1257_b(int64_t _1257_n);
int64_t _1259_c(int64_t _1259_n);

/* Function definitions */
int64_t _1253_main(void) {
    function0 _1253_t0;
    int64_t _1253_t2;
    int64_t _1253_t1;
    int64_t _1253_$retval;
    _1253_t0 = _1255_a;
    _1253_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1253_t1 = _1253_t0(_1253_t2);
    $line_idx--;
    _1253_$retval = _1253_t1;
    return _1253_$retval;
}

int64_t _1255_a(int64_t _1255_n) {
    function0 _1255_t0;
    int64_t _1255_t1;
    int64_t _1255_$retval;
    _1255_t0 = _1257_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1255_t1 = _1255_t0(_1255_n);
    $line_idx--;
    _1255_$retval = _1255_t1;
    return _1255_$retval;
}

int64_t _1257_b(int64_t _1257_n) {
    function0 _1257_t0;
    int64_t _1257_t1;
    int64_t _1257_$retval;
    _1257_t0 = _1259_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1257_t1 = _1257_t0(_1257_n);
    $line_idx--;
    _1257_$retval = _1257_t1;
    return _1257_$retval;
}

int64_t _1259_c(int64_t _1259_n) {
    int64_t _1259_t1;
    uint8_t _1259_t3;
    function0 _1259_t5;
    int64_t _1259_t6;
    int64_t _1259_t0;
    int64_t _1259_$retval;
    _1259_t1 = 47;
    _1259_t3 = _1259_n == _1259_t1;
    if (_1259_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1259_t0 = 47;
    goto BB6;
BB7:
    _1259_t5 = _1255_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1259_t6 = _1259_t5(_1259_n);
    $line_idx--;
    _1259_t0 = _1259_t6;
    goto BB6;
BB6:
    _1259_$retval = _1259_t0;
    return _1259_$retval;
}

int main(void) {
  printf("%ld",_1253_main());
  return 0;
}
