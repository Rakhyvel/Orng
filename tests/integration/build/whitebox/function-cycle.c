/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _36_main(void);
int64_t _38_a(int64_t _38_n);
int64_t _40_b(int64_t _40_n);
int64_t _42_c(int64_t _42_n);

/* Function definitions */
int64_t _36_main(void) {
    function0 _36_t0;
    int64_t _36_t2;
    int64_t _36_t1;
    int64_t _36_$retval;
    _36_t0 = _38_a;
    _36_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _36_t1 = _36_t0(_36_t2);
    $line_idx--;
    _36_$retval = _36_t1;
    return _36_$retval;
}

int64_t _38_a(int64_t _38_n) {
    function0 _38_t0;
    int64_t _38_t1;
    int64_t _38_$retval;
    _38_t0 = _40_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _38_t1 = _38_t0(_38_n);
    $line_idx--;
    _38_$retval = _38_t1;
    return _38_$retval;
}

int64_t _40_b(int64_t _40_n) {
    function0 _40_t0;
    int64_t _40_t1;
    int64_t _40_$retval;
    _40_t0 = _42_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _40_t1 = _40_t0(_40_n);
    $line_idx--;
    _40_$retval = _40_t1;
    return _40_$retval;
}

int64_t _42_c(int64_t _42_n) {
    int64_t _42_t1;
    uint8_t _42_t3;
    uint8_t _42_t2;
    int64_t _42_t0;
    function0 _42_t5;
    int64_t _42_t6;
    int64_t _42_$retval;
    _42_t1 = 47;
    _42_t3 = _42_n == _42_t1;
    if (_42_t3) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _42_t2 = 1;
    goto BB2;
BB9:
    _42_t2 = 0;
    goto BB2;
BB2:
    if (_42_t2) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _42_t0 = 47;
    goto BB6;
BB7:
    _42_t5 = _38_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _42_t6 = _42_t5(_42_n);
    $line_idx--;
    _42_t0 = _42_t6;
    goto BB6;
BB6:
    _42_$retval = _42_t0;
    return _42_$retval;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
