/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1861_main(void);
int64_t _1863_a(int64_t _1863_n);
int64_t _1865_b(int64_t _1865_n);
int64_t _1867_c(int64_t _1867_n);

/* Function definitions */
int64_t _1861_main(void){
    function0 _1861_t0;
    int64_t _1861_t2;
    int64_t _1861_t1;
    int64_t _1861_$retval;
    _1861_t0 = _1863_a;
    _1861_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1861_t1 = _1861_t0(_1861_t2);
    $line_idx--;
    _1861_$retval = _1861_t1;
    return _1861_$retval;
}

int64_t _1863_a(int64_t _1863_n){
    function0 _1863_t0;
    int64_t _1863_t1;
    int64_t _1863_$retval;
    _1863_t0 = _1865_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1863_t1 = _1863_t0(_1863_n);
    $line_idx--;
    _1863_$retval = _1863_t1;
    return _1863_$retval;
}

int64_t _1865_b(int64_t _1865_n){
    function0 _1865_t0;
    int64_t _1865_t1;
    int64_t _1865_$retval;
    _1865_t0 = _1867_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1865_t1 = _1865_t0(_1865_n);
    $line_idx--;
    _1865_$retval = _1865_t1;
    return _1865_$retval;
}

int64_t _1867_c(int64_t _1867_n){
    int64_t _1867_t1;
    uint8_t _1867_t3;
    function0 _1867_t5;
    int64_t _1867_t6;
    int64_t _1867_t0;
    int64_t _1867_$retval;
    _1867_t1 = 47;
    _1867_t3 = _1867_n == _1867_t1;
    if (_1867_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1867_t0 = 47;
    goto BB6;
BB7:
    _1867_t5 = _1863_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1867_t6 = _1867_t5(_1867_n);
    $line_idx--;
    _1867_t0 = _1867_t6;
    goto BB6;
BB6:
    _1867_$retval = _1867_t0;
    return _1867_$retval;
}

int main(void) {
  printf("%ld",_1861_main());
  return 0;
}
