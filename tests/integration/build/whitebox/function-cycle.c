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
int64_t _1803_main(void);
int64_t _1805_a(int64_t _1805_n);
int64_t _1807_b(int64_t _1807_n);
int64_t _1809_c(int64_t _1809_n);


/* Function definitions */
int64_t _1803_main(void){
    function0 _1803_t0;
    int64_t _1803_t2;
    int64_t _1803_t1;
    int64_t _1803_$retval;
    _1803_t0 = (function0) _1805_a;
    _1803_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1803_t1 = _1803_t0(_1803_t2);
    $line_idx--;
    _1803_$retval = _1803_t1;
    return _1803_$retval;
}

int64_t _1805_a(int64_t _1805_n){
    function0 _1805_t0;
    int64_t _1805_t1;
    int64_t _1805_$retval;
    _1805_t0 = (function0) _1807_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1805_t1 = _1805_t0(_1805_n);
    $line_idx--;
    _1805_$retval = _1805_t1;
    return _1805_$retval;
}

int64_t _1807_b(int64_t _1807_n){
    function0 _1807_t0;
    int64_t _1807_t1;
    int64_t _1807_$retval;
    _1807_t0 = (function0) _1809_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1807_t1 = _1807_t0(_1807_n);
    $line_idx--;
    _1807_$retval = _1807_t1;
    return _1807_$retval;
}

int64_t _1809_c(int64_t _1809_n){
    int64_t _1809_t1;
    uint8_t _1809_t3;
    function0 _1809_t5;
    int64_t _1809_t6;
    int64_t _1809_t0;
    int64_t _1809_$retval;
    _1809_t1 = 47;
    _1809_t3 = _1809_n==_1809_t1;
    if (_1809_t3) {
        goto BB2021;
    } else {
        goto BB2025;
    }
BB2021:
    _1809_t0 = 47;
    goto BB2024;
BB2025:
    _1809_t5 = (function0) _1805_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1809_t6 = _1809_t5(_1809_n);
    $line_idx--;
    _1809_t0 = _1809_t6;
    goto BB2024;
BB2024:
    _1809_$retval = _1809_t0;
    return _1809_$retval;
}


int main(void) {
  printf("%ld",_1803_main());
  return 0;
}
