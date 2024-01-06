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
int64_t _1602_main(void);
int64_t _1604_a(int64_t _1604_n);
int64_t _1606_b(int64_t _1606_n);
int64_t _1608_c(int64_t _1608_n);

/* Function definitions */
int64_t _1602_main(void){
    function0 _1602_t0;
    int64_t _1602_t2;
    int64_t _1602_t1;
    int64_t _1602_$retval;
    _1602_t0 = _1604_a;
    _1602_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1602_t1 = _1602_t0(_1602_t2);
    $line_idx--;
    _1602_$retval = _1602_t1;
    return _1602_$retval;
}

int64_t _1604_a(int64_t _1604_n){
    function0 _1604_t0;
    int64_t _1604_t1;
    int64_t _1604_$retval;
    _1604_t0 = _1606_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1604_t1 = _1604_t0(_1604_n);
    $line_idx--;
    _1604_$retval = _1604_t1;
    return _1604_$retval;
}

int64_t _1606_b(int64_t _1606_n){
    function0 _1606_t0;
    int64_t _1606_t1;
    int64_t _1606_$retval;
    _1606_t0 = _1608_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1606_t1 = _1606_t0(_1606_n);
    $line_idx--;
    _1606_$retval = _1606_t1;
    return _1606_$retval;
}

int64_t _1608_c(int64_t _1608_n){
    int64_t _1608_t1;
    uint8_t _1608_t3;
    function0 _1608_t5;
    int64_t _1608_t6;
    int64_t _1608_t0;
    int64_t _1608_$retval;
    _1608_t1 = 47;
    _1608_t3 = _1608_n==_1608_t1;
    if (_1608_t3) {
        goto BB1883;
    } else {
        goto BB1887;
    }
BB1883:
    _1608_t0 = 47;
    goto BB1886;
BB1887:
    _1608_t5 = _1604_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1608_t6 = _1608_t5(_1608_n);
    $line_idx--;
    _1608_t0 = _1608_t6;
    goto BB1886;
BB1886:
    _1608_$retval = _1608_t0;
    return _1608_$retval;
}

int main(void) {
  printf("%ld",_1602_main());
  return 0;
}
