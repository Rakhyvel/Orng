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
int64_t _1594_main(void);
int64_t _1596_a(int64_t _1596_n);
int64_t _1598_b(int64_t _1598_n);
int64_t _1600_c(int64_t _1600_n);

/* Function definitions */
int64_t _1594_main(void){
    function0 _1594_t0;
    int64_t _1594_t2;
    int64_t _1594_t1;
    int64_t _1594_$retval;
    _1594_t0 = _1596_a;
    _1594_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1594_t1 = _1594_t0(_1594_t2);
    $line_idx--;
    _1594_$retval = _1594_t1;
    return _1594_$retval;
}

int64_t _1596_a(int64_t _1596_n){
    function0 _1596_t0;
    int64_t _1596_t1;
    int64_t _1596_$retval;
    _1596_t0 = _1598_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1596_t1 = _1596_t0(_1596_n);
    $line_idx--;
    _1596_$retval = _1596_t1;
    return _1596_$retval;
}

int64_t _1598_b(int64_t _1598_n){
    function0 _1598_t0;
    int64_t _1598_t1;
    int64_t _1598_$retval;
    _1598_t0 = _1600_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1598_t1 = _1598_t0(_1598_n);
    $line_idx--;
    _1598_$retval = _1598_t1;
    return _1598_$retval;
}

int64_t _1600_c(int64_t _1600_n){
    int64_t _1600_t1;
    uint8_t _1600_t3;
    function0 _1600_t5;
    int64_t _1600_t6;
    int64_t _1600_t0;
    int64_t _1600_$retval;
    _1600_t1 = 47;
    _1600_t3 = _1600_n==_1600_t1;
    if (_1600_t3) {
        goto BB1887;
    } else {
        goto BB1891;
    }
BB1887:
    _1600_t0 = 47;
    goto BB1890;
BB1891:
    _1600_t5 = _1596_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1600_t6 = _1600_t5(_1600_n);
    $line_idx--;
    _1600_t0 = _1600_t6;
    goto BB1890;
BB1890:
    _1600_$retval = _1600_t0;
    return _1600_$retval;
}

int main(void) {
  printf("%ld",_1594_main());
  return 0;
}
