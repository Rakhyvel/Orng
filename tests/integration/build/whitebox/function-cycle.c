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
int64_t _1745_main(void);
int64_t _1747_a(int64_t _1747_n);
int64_t _1749_b(int64_t _1749_n);
int64_t _1751_c(int64_t _1751_n);


/* Function definitions */
int64_t _1745_main(void){
    function0 _1745_t0;
    int64_t _1745_t2;
    int64_t _1745_t1;
    int64_t _1745_$retval;
    _1745_t0 = _1747_a;
    _1745_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1745_t1 = _1745_t0(_1745_t2);
    $line_idx--;
    _1745_$retval = _1745_t1;
    return _1745_$retval;
}

int64_t _1747_a(int64_t _1747_n){
    function0 _1747_t0;
    int64_t _1747_t1;
    int64_t _1747_$retval;
    _1747_t0 = _1749_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1747_t1 = _1747_t0(_1747_n);
    $line_idx--;
    _1747_$retval = _1747_t1;
    return _1747_$retval;
}

int64_t _1749_b(int64_t _1749_n){
    function0 _1749_t0;
    int64_t _1749_t1;
    int64_t _1749_$retval;
    _1749_t0 = _1751_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1749_t1 = _1749_t0(_1749_n);
    $line_idx--;
    _1749_$retval = _1749_t1;
    return _1749_$retval;
}

int64_t _1751_c(int64_t _1751_n){
    int64_t _1751_t1;
    uint8_t _1751_t3;
    function0 _1751_t5;
    int64_t _1751_t6;
    int64_t _1751_t0;
    int64_t _1751_$retval;
    _1751_t1 = 47;
    _1751_t3 = _1751_n==_1751_t1;
    if (_1751_t3) {
        goto BB2004;
    } else {
        goto BB2008;
    }
BB2004:
    _1751_t0 = 47;
    goto BB2007;
BB2008:
    _1751_t5 = _1747_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1751_t6 = _1751_t5(_1751_n);
    $line_idx--;
    _1751_t0 = _1751_t6;
    goto BB2007;
BB2007:
    _1751_$retval = _1751_t0;
    return _1751_$retval;
}


int main(void) {
  printf("%ld",_1745_main());
  return 0;
}
