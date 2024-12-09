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
int64_t _1971_main(void);
int64_t _1973_a(int64_t _1973_n);
int64_t _1975_b(int64_t _1975_n);
int64_t _1977_c(int64_t _1977_n);


/* Function definitions */
int64_t _1971_main(void){
    function0 _1971_t0;
    int64_t _1971_t2;
    int64_t _1971_t1;
    int64_t _1971_$retval;
    _1971_t0 = (function0) _1973_a;
    _1971_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1971_t1 = _1971_t0(_1971_t2);
    $line_idx--;
    _1971_$retval = _1971_t1;
    return _1971_$retval;
}

int64_t _1973_a(int64_t _1973_n){
    function0 _1973_t0;
    int64_t _1973_t1;
    int64_t _1973_$retval;
    _1973_t0 = (function0) _1975_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1973_t1 = _1973_t0(_1973_n);
    $line_idx--;
    _1973_$retval = _1973_t1;
    return _1973_$retval;
}

int64_t _1975_b(int64_t _1975_n){
    function0 _1975_t0;
    int64_t _1975_t1;
    int64_t _1975_$retval;
    _1975_t0 = (function0) _1977_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1975_t1 = _1975_t0(_1975_n);
    $line_idx--;
    _1975_$retval = _1975_t1;
    return _1975_$retval;
}

int64_t _1977_c(int64_t _1977_n){
    int64_t _1977_t1;
    uint8_t _1977_t3;
    function0 _1977_t5;
    int64_t _1977_t6;
    int64_t _1977_t0;
    int64_t _1977_$retval;
    _1977_t1 = 47;
    _1977_t3 = _1977_n==_1977_t1;
    if (_1977_t3) {
        goto BB2154;
    } else {
        goto BB2158;
    }
BB2154:
    _1977_t0 = 47;
    goto BB2157;
BB2158:
    _1977_t5 = (function0) _1973_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1977_t6 = _1977_t5(_1977_n);
    $line_idx--;
    _1977_t0 = _1977_t6;
    goto BB2157;
BB2157:
    _1977_$retval = _1977_t0;
    return _1977_$retval;
}


int main(void) {
  printf("%ld",_1971_main());
  return 0;
}
