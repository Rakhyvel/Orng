/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1564_main(void);
int64_t _1566_a(int64_t _1566_n);
int64_t _1568_b(int64_t _1568_n);
int64_t _1570_c(int64_t _1570_n);

/* Function definitions */
int64_t _1564_main(void){
    function0 _1564_t0;
    int64_t _1564_t2;
    int64_t _1564_t1;
    int64_t _1564_$retval;
    _1564_t0 = _1566_a;
    _1564_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1564_t1 = _1564_t0(_1564_t2);
    $line_idx--;
    _1564_$retval = _1564_t1;
    return _1564_$retval;
}

int64_t _1566_a(int64_t _1566_n){
    function0 _1566_t0;
    int64_t _1566_t1;
    int64_t _1566_$retval;
    _1566_t0 = _1568_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1566_t1 = _1566_t0(_1566_n);
    $line_idx--;
    _1566_$retval = _1566_t1;
    return _1566_$retval;
}

int64_t _1568_b(int64_t _1568_n){
    function0 _1568_t0;
    int64_t _1568_t1;
    int64_t _1568_$retval;
    _1568_t0 = _1570_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1568_t1 = _1568_t0(_1568_n);
    $line_idx--;
    _1568_$retval = _1568_t1;
    return _1568_$retval;
}

int64_t _1570_c(int64_t _1570_n){
    int64_t _1570_t1;
    uint8_t _1570_t3;
    function0 _1570_t5;
    int64_t _1570_t6;
    int64_t _1570_t0;
    int64_t _1570_$retval;
    _1570_t1 = 47;
    _1570_t3 = _1570_n == _1570_t1;
    if (_1570_t3) {
        goto BB1900;
    } else {
        goto BB1904;
    }
BB1900:
    _1570_t0 = 47;
    goto BB1903;
BB1904:
    _1570_t5 = _1566_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1570_t6 = _1570_t5(_1570_n);
    $line_idx--;
    _1570_t0 = _1570_t6;
    goto BB1903;
BB1903:
    _1570_$retval = _1570_t0;
    return _1570_$retval;
}

int main(void) {
  printf("%ld",_1564_main());
  return 0;
}
