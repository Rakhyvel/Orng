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
int64_t _1769_main(void);
int64_t _1771_a(int64_t _1771_n);
int64_t _1773_b(int64_t _1773_n);
int64_t _1775_c(int64_t _1775_n);


/* Function definitions */
int64_t _1769_main(void){
    function0 _1769_t0;
    int64_t _1769_t2;
    int64_t _1769_t1;
    int64_t _1769_$retval;
    _1769_t0 = (function0) _1771_a;
    _1769_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1769_t1 = _1769_t0(_1769_t2);
    $line_idx--;
    _1769_$retval = _1769_t1;
    return _1769_$retval;
}

int64_t _1771_a(int64_t _1771_n){
    function0 _1771_t0;
    int64_t _1771_t1;
    int64_t _1771_$retval;
    _1771_t0 = (function0) _1773_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1771_t1 = _1771_t0(_1771_n);
    $line_idx--;
    _1771_$retval = _1771_t1;
    return _1771_$retval;
}

int64_t _1773_b(int64_t _1773_n){
    function0 _1773_t0;
    int64_t _1773_t1;
    int64_t _1773_$retval;
    _1773_t0 = (function0) _1775_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1773_t1 = _1773_t0(_1773_n);
    $line_idx--;
    _1773_$retval = _1773_t1;
    return _1773_$retval;
}

int64_t _1775_c(int64_t _1775_n){
    int64_t _1775_t1;
    uint8_t _1775_t3;
    function0 _1775_t5;
    int64_t _1775_t6;
    int64_t _1775_t0;
    int64_t _1775_$retval;
    _1775_t1 = 47;
    _1775_t3 = _1775_n==_1775_t1;
    if (_1775_t3) {
        goto BB2016;
    } else {
        goto BB2020;
    }
BB2016:
    _1775_t0 = 47;
    goto BB2019;
BB2020:
    _1775_t5 = (function0) _1771_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1775_t6 = _1775_t5(_1775_n);
    $line_idx--;
    _1775_t0 = _1775_t6;
    goto BB2019;
BB2019:
    _1775_$retval = _1775_t0;
    return _1775_$retval;
}


int main(void) {
  printf("%ld",_1769_main());
  return 0;
}
