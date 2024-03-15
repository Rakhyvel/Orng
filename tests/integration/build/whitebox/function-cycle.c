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
int64_t _1791_main(void);
int64_t _1793_a(int64_t _1793_n);
int64_t _1795_b(int64_t _1795_n);
int64_t _1797_c(int64_t _1797_n);


/* Function definitions */
int64_t _1791_main(void){
    function0 _1791_t0;
    int64_t _1791_t2;
    int64_t _1791_t1;
    int64_t _1791_$retval;
    _1791_t0 = (function0) _1793_a;
    _1791_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1791_t1 = _1791_t0(_1791_t2);
    $line_idx--;
    _1791_$retval = _1791_t1;
    return _1791_$retval;
}

int64_t _1793_a(int64_t _1793_n){
    function0 _1793_t0;
    int64_t _1793_t1;
    int64_t _1793_$retval;
    _1793_t0 = (function0) _1795_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1793_t1 = _1793_t0(_1793_n);
    $line_idx--;
    _1793_$retval = _1793_t1;
    return _1793_$retval;
}

int64_t _1795_b(int64_t _1795_n){
    function0 _1795_t0;
    int64_t _1795_t1;
    int64_t _1795_$retval;
    _1795_t0 = (function0) _1797_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1795_t1 = _1795_t0(_1795_n);
    $line_idx--;
    _1795_$retval = _1795_t1;
    return _1795_$retval;
}

int64_t _1797_c(int64_t _1797_n){
    int64_t _1797_t1;
    uint8_t _1797_t3;
    function0 _1797_t5;
    int64_t _1797_t6;
    int64_t _1797_t0;
    int64_t _1797_$retval;
    _1797_t1 = 47;
    _1797_t3 = _1797_n==_1797_t1;
    if (_1797_t3) {
        goto BB2015;
    } else {
        goto BB2019;
    }
BB2015:
    _1797_t0 = 47;
    goto BB2018;
BB2019:
    _1797_t5 = (function0) _1793_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1797_t6 = _1797_t5(_1797_n);
    $line_idx--;
    _1797_t0 = _1797_t6;
    goto BB2018;
BB2018:
    _1797_$retval = _1797_t0;
    return _1797_$retval;
}


int main(void) {
  printf("%ld",_1791_main());
  return 0;
}
