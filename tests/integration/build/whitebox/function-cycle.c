/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1608_main(void);
int64_t _1610_a(int64_t _1610_n);
int64_t _1612_b(int64_t _1612_n);
int64_t _1614_c(int64_t _1614_n);

/* Function definitions */
int64_t _1608_main(void){
    function0 _1608_t0;
    int64_t _1608_t2;
    int64_t _1608_t1;
    int64_t _1608_$retval;
    _1608_t0 = _1610_a;
    _1608_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1608_t1 = _1608_t0(_1608_t2);
    $line_idx--;
    _1608_$retval = _1608_t1;
    return _1608_$retval;
}

int64_t _1610_a(int64_t _1610_n){
    function0 _1610_t0;
    int64_t _1610_t1;
    int64_t _1610_$retval;
    _1610_t0 = _1612_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1610_t1 = _1610_t0(_1610_n);
    $line_idx--;
    _1610_$retval = _1610_t1;
    return _1610_$retval;
}

int64_t _1612_b(int64_t _1612_n){
    function0 _1612_t0;
    int64_t _1612_t1;
    int64_t _1612_$retval;
    _1612_t0 = _1614_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1612_t1 = _1612_t0(_1612_n);
    $line_idx--;
    _1612_$retval = _1612_t1;
    return _1612_$retval;
}

int64_t _1614_c(int64_t _1614_n){
    int64_t _1614_t1;
    uint8_t _1614_t3;
    function0 _1614_t5;
    int64_t _1614_t6;
    int64_t _1614_t0;
    int64_t _1614_$retval;
    _1614_t1 = 47;
    _1614_t3 = _1614_n == _1614_t1;
    if (_1614_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1614_t0 = 47;
    goto BB6;
BB7:
    _1614_t5 = _1610_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1614_t6 = _1614_t5(_1614_n);
    $line_idx--;
    _1614_t0 = _1614_t6;
    goto BB6;
BB6:
    _1614_$retval = _1614_t0;
    return _1614_$retval;
}

int main(void) {
  printf("%ld",_1608_main());
  return 0;
}
