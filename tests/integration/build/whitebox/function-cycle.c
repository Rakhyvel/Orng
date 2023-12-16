/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1668_main(void);
int64_t _1670_a(int64_t _1670_n);
int64_t _1672_b(int64_t _1672_n);
int64_t _1674_c(int64_t _1674_n);

/* Function definitions */
int64_t _1668_main(void){
    function0 _1668_t0;
    int64_t _1668_t2;
    int64_t _1668_t1;
    int64_t _1668_$retval;
    _1668_t0 = _1670_a;
    _1668_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1668_t1 = _1668_t0(_1668_t2);
    $line_idx--;
    _1668_$retval = _1668_t1;
    return _1668_$retval;
}

int64_t _1670_a(int64_t _1670_n){
    function0 _1670_t0;
    int64_t _1670_t1;
    int64_t _1670_$retval;
    _1670_t0 = _1672_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1670_t1 = _1670_t0(_1670_n);
    $line_idx--;
    _1670_$retval = _1670_t1;
    return _1670_$retval;
}

int64_t _1672_b(int64_t _1672_n){
    function0 _1672_t0;
    int64_t _1672_t1;
    int64_t _1672_$retval;
    _1672_t0 = _1674_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1672_t1 = _1672_t0(_1672_n);
    $line_idx--;
    _1672_$retval = _1672_t1;
    return _1672_$retval;
}

int64_t _1674_c(int64_t _1674_n){
    int64_t _1674_t1;
    uint8_t _1674_t3;
    function0 _1674_t5;
    int64_t _1674_t6;
    int64_t _1674_t0;
    int64_t _1674_$retval;
    _1674_t1 = 47;
    _1674_t3 = _1674_n == _1674_t1;
    if (_1674_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1674_t0 = 47;
    goto BB6;
BB7:
    _1674_t5 = _1670_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1674_t6 = _1674_t5(_1674_n);
    $line_idx--;
    _1674_t0 = _1674_t6;
    goto BB6;
BB6:
    _1674_$retval = _1674_t0;
    return _1674_$retval;
}

int main(void) {
  printf("%ld",_1668_main());
  return 0;
}
