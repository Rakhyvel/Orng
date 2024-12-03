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
int64_t _1946_main(void);
int64_t _1948_a(int64_t _1948_n);
int64_t _1950_b(int64_t _1950_n);
int64_t _1952_c(int64_t _1952_n);


/* Function definitions */
int64_t _1946_main(void){
    function0 _1946_t0;
    int64_t _1946_t2;
    int64_t _1946_t1;
    int64_t _1946_$retval;
    _1946_t0 = (function0) _1948_a;
    _1946_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1946_t1 = _1946_t0(_1946_t2);
    $line_idx--;
    _1946_$retval = _1946_t1;
    return _1946_$retval;
}

int64_t _1948_a(int64_t _1948_n){
    function0 _1948_t0;
    int64_t _1948_t1;
    int64_t _1948_$retval;
    _1948_t0 = (function0) _1950_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1948_t1 = _1948_t0(_1948_n);
    $line_idx--;
    _1948_$retval = _1948_t1;
    return _1948_$retval;
}

int64_t _1950_b(int64_t _1950_n){
    function0 _1950_t0;
    int64_t _1950_t1;
    int64_t _1950_$retval;
    _1950_t0 = (function0) _1952_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1950_t1 = _1950_t0(_1950_n);
    $line_idx--;
    _1950_$retval = _1950_t1;
    return _1950_$retval;
}

int64_t _1952_c(int64_t _1952_n){
    int64_t _1952_t1;
    uint8_t _1952_t3;
    function0 _1952_t5;
    int64_t _1952_t6;
    int64_t _1952_t0;
    int64_t _1952_$retval;
    _1952_t1 = 47;
    _1952_t3 = _1952_n==_1952_t1;
    if (_1952_t3) {
        goto BB2129;
    } else {
        goto BB2133;
    }
BB2129:
    _1952_t0 = 47;
    goto BB2132;
BB2133:
    _1952_t5 = (function0) _1948_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1952_t6 = _1952_t5(_1952_n);
    $line_idx--;
    _1952_t0 = _1952_t6;
    goto BB2132;
BB2132:
    _1952_$retval = _1952_t0;
    return _1952_$retval;
}


int main(void) {
  printf("%ld",_1946_main());
  return 0;
}
