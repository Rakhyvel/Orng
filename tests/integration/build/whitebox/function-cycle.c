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
int64_t _1630_main(void);
int64_t _1632_a(int64_t _1632_n);
int64_t _1634_b(int64_t _1634_n);
int64_t _1636_c(int64_t _1636_n);

/* Function definitions */
int64_t _1630_main(void){
    function0 _1630_t0;
    int64_t _1630_t2;
    int64_t _1630_t1;
    int64_t _1630_$retval;
    _1630_t0 = _1632_a;
    _1630_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1630_t1 = _1630_t0(_1630_t2);
    $line_idx--;
    _1630_$retval = _1630_t1;
    return _1630_$retval;
}

int64_t _1632_a(int64_t _1632_n){
    function0 _1632_t0;
    int64_t _1632_t1;
    int64_t _1632_$retval;
    _1632_t0 = _1634_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1632_t1 = _1632_t0(_1632_n);
    $line_idx--;
    _1632_$retval = _1632_t1;
    return _1632_$retval;
}

int64_t _1634_b(int64_t _1634_n){
    function0 _1634_t0;
    int64_t _1634_t1;
    int64_t _1634_$retval;
    _1634_t0 = _1636_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1634_t1 = _1634_t0(_1634_n);
    $line_idx--;
    _1634_$retval = _1634_t1;
    return _1634_$retval;
}

int64_t _1636_c(int64_t _1636_n){
    int64_t _1636_t1;
    uint8_t _1636_t3;
    function0 _1636_t5;
    int64_t _1636_t6;
    int64_t _1636_t0;
    int64_t _1636_$retval;
    _1636_t1 = 47;
    _1636_t3 = _1636_n==_1636_t1;
    if (_1636_t3) {
        goto BB1902;
    } else {
        goto BB1906;
    }
BB1902:
    _1636_t0 = 47;
    goto BB1905;
BB1906:
    _1636_t5 = _1632_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1636_t6 = _1636_t5(_1636_n);
    $line_idx--;
    _1636_t0 = _1636_t6;
    goto BB1905;
BB1905:
    _1636_$retval = _1636_t0;
    return _1636_$retval;
}

int main(void) {
  printf("%ld",_1630_main());
  return 0;
}
