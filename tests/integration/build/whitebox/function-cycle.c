/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1842_main(void);
int64_t _1844_a(int64_t _1844_n);
int64_t _1846_b(int64_t _1846_n);
int64_t _1848_c(int64_t _1848_n);

/* Function definitions */
int64_t _1842_main(void){
    function0 _1842_t0;
    int64_t _1842_t2;
    int64_t _1842_t1;
    int64_t _1842_$retval;
    _1842_t0 = _1844_a;
    _1842_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1842_t1 = _1842_t0(_1842_t2);
    $line_idx--;
    _1842_$retval = _1842_t1;
    return _1842_$retval;
}

int64_t _1844_a(int64_t _1844_n){
    function0 _1844_t0;
    int64_t _1844_t1;
    int64_t _1844_$retval;
    _1844_t0 = _1846_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1844_t1 = _1844_t0(_1844_n);
    $line_idx--;
    _1844_$retval = _1844_t1;
    return _1844_$retval;
}

int64_t _1846_b(int64_t _1846_n){
    function0 _1846_t0;
    int64_t _1846_t1;
    int64_t _1846_$retval;
    _1846_t0 = _1848_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1846_t1 = _1846_t0(_1846_n);
    $line_idx--;
    _1846_$retval = _1846_t1;
    return _1846_$retval;
}

int64_t _1848_c(int64_t _1848_n){
    int64_t _1848_t1;
    uint8_t _1848_t3;
    function0 _1848_t5;
    int64_t _1848_t6;
    int64_t _1848_t0;
    int64_t _1848_$retval;
    _1848_t1 = 47;
    _1848_t3 = _1848_n == _1848_t1;
    if (_1848_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1848_t0 = 47;
    goto BB6;
BB7:
    _1848_t5 = _1844_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1848_t6 = _1848_t5(_1848_n);
    $line_idx--;
    _1848_t0 = _1848_t6;
    goto BB6;
BB6:
    _1848_$retval = _1848_t0;
    return _1848_$retval;
}

int main(void) {
  printf("%ld",_1842_main());
  return 0;
}
