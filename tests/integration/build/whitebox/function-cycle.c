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
int64_t _1674_main(void);
int64_t _1676_a(int64_t _1676_n);
int64_t _1678_b(int64_t _1678_n);
int64_t _1680_c(int64_t _1680_n);


/* Function definitions */
int64_t _1674_main(void){
    function0 _1674_t0;
    int64_t _1674_t2;
    int64_t _1674_t1;
    int64_t _1674_$retval;
    _1674_t0 = _1676_a;
    _1674_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1674_t1 = _1674_t0(_1674_t2);
    $line_idx--;
    _1674_$retval = _1674_t1;
    return _1674_$retval;
}

int64_t _1676_a(int64_t _1676_n){
    function0 _1676_t0;
    int64_t _1676_t1;
    int64_t _1676_$retval;
    _1676_t0 = _1678_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1676_t1 = _1676_t0(_1676_n);
    $line_idx--;
    _1676_$retval = _1676_t1;
    return _1676_$retval;
}

int64_t _1678_b(int64_t _1678_n){
    function0 _1678_t0;
    int64_t _1678_t1;
    int64_t _1678_$retval;
    _1678_t0 = _1680_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1678_t1 = _1678_t0(_1678_n);
    $line_idx--;
    _1678_$retval = _1678_t1;
    return _1678_$retval;
}

int64_t _1680_c(int64_t _1680_n){
    int64_t _1680_t1;
    uint8_t _1680_t3;
    function0 _1680_t5;
    int64_t _1680_t6;
    int64_t _1680_t0;
    int64_t _1680_$retval;
    _1680_t1 = 47;
    _1680_t3 = _1680_n==_1680_t1;
    if (_1680_t3) {
        goto BB1942;
    } else {
        goto BB1946;
    }
BB1942:
    _1680_t0 = 47;
    goto BB1945;
BB1946:
    _1680_t5 = _1676_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1680_t6 = _1680_t5(_1680_n);
    $line_idx--;
    _1680_t0 = _1680_t6;
    goto BB1945;
BB1945:
    _1680_$retval = _1680_t0;
    return _1680_$retval;
}


int main(void) {
  printf("%ld",_1674_main());
  return 0;
}
