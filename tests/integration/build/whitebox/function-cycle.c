/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1753_main(void);
int64_t _1755_a(int64_t _1755_n);
int64_t _1757_b(int64_t _1757_n);
int64_t _1759_c(int64_t _1759_n);

/* Function definitions */
int64_t _1753_main(void){
    function0 _1753_t0;
    int64_t _1753_t2;
    int64_t _1753_t1;
    int64_t _1753_$retval;
    _1753_t0 = _1755_a;
    _1753_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1753_t1 = _1753_t0(_1753_t2);
    $line_idx--;
    _1753_$retval = _1753_t1;
    return _1753_$retval;
}

int64_t _1755_a(int64_t _1755_n){
    function0 _1755_t0;
    int64_t _1755_t1;
    int64_t _1755_$retval;
    _1755_t0 = _1757_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1755_t1 = _1755_t0(_1755_n);
    $line_idx--;
    _1755_$retval = _1755_t1;
    return _1755_$retval;
}

int64_t _1757_b(int64_t _1757_n){
    function0 _1757_t0;
    int64_t _1757_t1;
    int64_t _1757_$retval;
    _1757_t0 = _1759_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1757_t1 = _1757_t0(_1757_n);
    $line_idx--;
    _1757_$retval = _1757_t1;
    return _1757_$retval;
}

int64_t _1759_c(int64_t _1759_n){
    int64_t _1759_t1;
    uint8_t _1759_t3;
    function0 _1759_t5;
    int64_t _1759_t6;
    int64_t _1759_t0;
    int64_t _1759_$retval;
    _1759_t1 = 47;
    _1759_t3 = _1759_n == _1759_t1;
    if (_1759_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1759_t0 = 47;
    goto BB6;
BB7:
    _1759_t5 = _1755_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1759_t6 = _1759_t5(_1759_n);
    $line_idx--;
    _1759_t0 = _1759_t6;
    goto BB6;
BB6:
    _1759_$retval = _1759_t0;
    return _1759_$retval;
}

int main(void) {
  printf("%ld",_1753_main());
  return 0;
}
