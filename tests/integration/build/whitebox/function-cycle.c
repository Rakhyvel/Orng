/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1612_main(void);
int64_t _1614_a(int64_t _1614_n);
int64_t _1616_b(int64_t _1616_n);
int64_t _1618_c(int64_t _1618_n);

/* Function definitions */
int64_t _1612_main(void){
    function0 _1612_t0;
    int64_t _1612_t2;
    int64_t _1612_t1;
    int64_t _1612_$retval;
    _1612_t0 = _1614_a;
    _1612_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1612_t1 = _1612_t0(_1612_t2);
    $line_idx--;
    _1612_$retval = _1612_t1;
    return _1612_$retval;
}

int64_t _1614_a(int64_t _1614_n){
    function0 _1614_t0;
    int64_t _1614_t1;
    int64_t _1614_$retval;
    _1614_t0 = _1616_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1614_t1 = _1614_t0(_1614_n);
    $line_idx--;
    _1614_$retval = _1614_t1;
    return _1614_$retval;
}

int64_t _1616_b(int64_t _1616_n){
    function0 _1616_t0;
    int64_t _1616_t1;
    int64_t _1616_$retval;
    _1616_t0 = _1618_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1616_t1 = _1616_t0(_1616_n);
    $line_idx--;
    _1616_$retval = _1616_t1;
    return _1616_$retval;
}

int64_t _1618_c(int64_t _1618_n){
    int64_t _1618_t1;
    uint8_t _1618_t3;
    function0 _1618_t5;
    int64_t _1618_t6;
    int64_t _1618_t0;
    int64_t _1618_$retval;
    _1618_t1 = 47;
    _1618_t3 = _1618_n==_1618_t1;
    if (_1618_t3) {
        goto BB1895;
    } else {
        goto BB1899;
    }
BB1895:
    _1618_t0 = 47;
    goto BB1898;
BB1899:
    _1618_t5 = _1614_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1618_t6 = _1618_t5(_1618_n);
    $line_idx--;
    _1618_t0 = _1618_t6;
    goto BB1898;
BB1898:
    _1618_$retval = _1618_t0;
    return _1618_$retval;
}

int main(void) {
  printf("%ld",_1612_main());
  return 0;
}
