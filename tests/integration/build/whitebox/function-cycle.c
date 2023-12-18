/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1854_main(void);
int64_t _1856_a(int64_t _1856_n);
int64_t _1858_b(int64_t _1858_n);
int64_t _1860_c(int64_t _1860_n);

/* Function definitions */
int64_t _1854_main(void){
    function0 _1854_t0;
    int64_t _1854_t2;
    int64_t _1854_t1;
    int64_t _1854_$retval;
    _1854_t0 = _1856_a;
    _1854_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1854_t1 = _1854_t0(_1854_t2);
    $line_idx--;
    _1854_$retval = _1854_t1;
    return _1854_$retval;
}

int64_t _1856_a(int64_t _1856_n){
    function0 _1856_t0;
    int64_t _1856_t1;
    int64_t _1856_$retval;
    _1856_t0 = _1858_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1856_t1 = _1856_t0(_1856_n);
    $line_idx--;
    _1856_$retval = _1856_t1;
    return _1856_$retval;
}

int64_t _1858_b(int64_t _1858_n){
    function0 _1858_t0;
    int64_t _1858_t1;
    int64_t _1858_$retval;
    _1858_t0 = _1860_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1858_t1 = _1858_t0(_1858_n);
    $line_idx--;
    _1858_$retval = _1858_t1;
    return _1858_$retval;
}

int64_t _1860_c(int64_t _1860_n){
    int64_t _1860_t1;
    uint8_t _1860_t3;
    function0 _1860_t5;
    int64_t _1860_t6;
    int64_t _1860_t0;
    int64_t _1860_$retval;
    _1860_t1 = 47;
    _1860_t3 = _1860_n == _1860_t1;
    if (_1860_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1860_t0 = 47;
    goto BB6;
BB7:
    _1860_t5 = _1856_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1860_t6 = _1860_t5(_1860_n);
    $line_idx--;
    _1860_t0 = _1860_t6;
    goto BB6;
BB6:
    _1860_$retval = _1860_t0;
    return _1860_$retval;
}

int main(void) {
  printf("%ld",_1854_main());
  return 0;
}
