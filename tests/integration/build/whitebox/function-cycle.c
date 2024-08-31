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
int64_t _1841_main(void);
int64_t _1843_a(int64_t _1843_n);
int64_t _1845_b(int64_t _1845_n);
int64_t _1847_c(int64_t _1847_n);


/* Function definitions */
int64_t _1841_main(void){
    function0 _1841_t0;
    int64_t _1841_t2;
    int64_t _1841_t1;
    int64_t _1841_$retval;
    _1841_t0 = (function0) _1843_a;
    _1841_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1841_t1 = _1841_t0(_1841_t2);
    $line_idx--;
    _1841_$retval = _1841_t1;
    return _1841_$retval;
}

int64_t _1843_a(int64_t _1843_n){
    function0 _1843_t0;
    int64_t _1843_t1;
    int64_t _1843_$retval;
    _1843_t0 = (function0) _1845_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1843_t1 = _1843_t0(_1843_n);
    $line_idx--;
    _1843_$retval = _1843_t1;
    return _1843_$retval;
}

int64_t _1845_b(int64_t _1845_n){
    function0 _1845_t0;
    int64_t _1845_t1;
    int64_t _1845_$retval;
    _1845_t0 = (function0) _1847_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1845_t1 = _1845_t0(_1845_n);
    $line_idx--;
    _1845_$retval = _1845_t1;
    return _1845_$retval;
}

int64_t _1847_c(int64_t _1847_n){
    int64_t _1847_t1;
    uint8_t _1847_t3;
    function0 _1847_t5;
    int64_t _1847_t6;
    int64_t _1847_t0;
    int64_t _1847_$retval;
    _1847_t1 = 47;
    _1847_t3 = _1847_n==_1847_t1;
    if (_1847_t3) {
        goto BB2048;
    } else {
        goto BB2052;
    }
BB2048:
    _1847_t0 = 47;
    goto BB2051;
BB2052:
    _1847_t5 = (function0) _1843_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1847_t6 = _1847_t5(_1847_n);
    $line_idx--;
    _1847_t0 = _1847_t6;
    goto BB2051;
BB2051:
    _1847_$retval = _1847_t0;
    return _1847_$retval;
}


int main(void) {
  printf("%ld",_1841_main());
  return 0;
}
