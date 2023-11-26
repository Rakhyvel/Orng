/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

typedef struct {
    int64_t _0;
    int64_t _1;
} struct2;

typedef int64_t(*function1)(    int64_t,     int64_t);

/* Function forward definitions */
int64_t _53_main(void);
int64_t _55_fib(int64_t _55_n);
int64_t _60_add(int64_t _60_x,int64_t _60_y);

/* Function definitions */
int64_t _53_main(void) {
    function0 _53_t0;
    int64_t _53_t2;
    int64_t _53_t1;
    int64_t _53_t3;
    int64_t _53_$retval;
    _53_t0 = _55_fib;
    _53_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _53_t1 = _53_t0(_53_t2);
    $line_idx--;
    _53_t3 = 10;
    _53_$retval = $sub_int64_t(_53_t1, _53_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _53_$retval;
}

int64_t _55_fib(int64_t _55_n) {
    function1 _55_t7;
    function0 _55_t9;
    int64_t _55_t11;
    int64_t _55_t12;
    int64_t _55_t10;
    function0 _55_t13;
    int64_t _55_t15;
    int64_t _55_t16;
    int64_t _55_t14;
    int64_t _55_t8;
    int64_t _55_t0;
    int64_t _55_t1;
    uint8_t _55_t2;
    int64_t _55_t3;
    uint8_t _55_t4;
    int64_t _55_$retval;
    _55_t1 = 0;
    _55_t2 = _55_n == _55_t1;
    if (_55_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _55_t0 = 0;
    goto BB5;
BB6:
    _55_t3 = 1;
    _55_t4 = _55_n == _55_t3;
    if (_55_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _55_$retval = _55_t0;
    return _55_$retval;
BB8:
    _55_t0 = 1;
    goto BB5;
BB10:
    _55_t7 = _60_add;
    _55_t9 = _55_fib;
    _55_t11 = 1;
    _55_t12 = $sub_int64_t(_55_n, _55_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _55_t10 = _55_t9(_55_t12);
    $line_idx--;
    _55_t13 = _55_fib;
    _55_t15 = 2;
    _55_t16 = $sub_int64_t(_55_n, _55_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _55_t14 = _55_t13(_55_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _55_t8 = _55_t7(_55_t10, _55_t14);
    $line_idx--;
    _55_t0 = _55_t8;
    goto BB5;
}

int64_t _60_add(int64_t _60_x,int64_t _60_y) {
    int64_t _60_$retval;
    _60_$retval = $add_int64_t(_60_x, _60_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _60_$retval;
}

int main(void) {
  printf("%ld",_53_main());
  return 0;
}
