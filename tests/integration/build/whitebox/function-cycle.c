/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1836_main(void);
int64_t _1838_a(int64_t _1838_n);
int64_t _1840_b(int64_t _1840_n);
int64_t _1842_c(int64_t _1842_n);


/* Function definitions */
int64_t _1836_main(void){
    function0 _1836_t0;
    int64_t _1836_t2;
    int64_t _1836_t1;
    int64_t _1836_$retval;
    _1836_t0 = (function0) _1838_a;
    _1836_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1836_t1 = _1836_t0(_1836_t2);
    $line_idx--;
    _1836_$retval = _1836_t1;
    return _1836_$retval;
}

int64_t _1838_a(int64_t _1838_n){
    function0 _1838_t0;
    int64_t _1838_t1;
    int64_t _1838_$retval;
    _1838_t0 = (function0) _1840_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1838_t1 = _1838_t0(_1838_n);
    $line_idx--;
    _1838_$retval = _1838_t1;
    return _1838_$retval;
}

int64_t _1840_b(int64_t _1840_n){
    function0 _1840_t0;
    int64_t _1840_t1;
    int64_t _1840_$retval;
    _1840_t0 = (function0) _1842_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1840_t1 = _1840_t0(_1840_n);
    $line_idx--;
    _1840_$retval = _1840_t1;
    return _1840_$retval;
}

int64_t _1842_c(int64_t _1842_n){
    int64_t _1842_t1;
    uint8_t _1842_t3;
    function0 _1842_t5;
    int64_t _1842_t6;
    int64_t _1842_t0;
    int64_t _1842_$retval;
    _1842_t1 = 47;
    _1842_t3 = _1842_n==_1842_t1;
    if (_1842_t3) {
        goto BB2044;
    } else {
        goto BB2048;
    }
BB2044:
    _1842_t0 = 47;
    goto BB2047;
BB2048:
    _1842_t5 = (function0) _1838_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1842_t6 = _1842_t5(_1842_n);
    $line_idx--;
    _1842_t0 = _1842_t6;
    goto BB2047;
BB2047:
    _1842_$retval = _1842_t0;
    return _1842_$retval;
}


int main(void) {
  printf("%ld",_1836_main());
  return 0;
}
