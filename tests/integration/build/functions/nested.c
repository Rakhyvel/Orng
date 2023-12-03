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

typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _700_main(void);
int64_t _702_fib(int64_t _702_n);
int64_t _707_add(int64_t _707_x,int64_t _707_y);

/* Function definitions */
int64_t _700_main(void) {
    function0 _700_t0;
    int64_t _700_t2;
    int64_t _700_t1;
    int64_t _700_t3;
    int64_t _700_$retval;
    _700_t0 = _702_fib;
    _700_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _700_t1 = _700_t0(_700_t2);
    $line_idx--;
    _700_t3 = 10;
    _700_$retval = $sub_int64_t(_700_t1, _700_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _700_$retval;
}

int64_t _702_fib(int64_t _702_n) {
    function1 _702_t7;
    function0 _702_t9;
    int64_t _702_t11;
    int64_t _702_t12;
    int64_t _702_t10;
    function0 _702_t13;
    int64_t _702_t15;
    int64_t _702_t16;
    int64_t _702_t14;
    int64_t _702_t8;
    int64_t _702_t0;
    int64_t _702_t1;
    uint8_t _702_t2;
    int64_t _702_t3;
    uint8_t _702_t4;
    int64_t _702_$retval;
    _702_t1 = 0;
    _702_t2 = _702_n == _702_t1;
    if (_702_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _702_t0 = 0;
    goto BB5;
BB6:
    _702_t3 = 1;
    _702_t4 = _702_n == _702_t3;
    if (_702_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _702_$retval = _702_t0;
    return _702_$retval;
BB8:
    _702_t0 = 1;
    goto BB5;
BB10:
    _702_t7 = _707_add;
    _702_t9 = _702_fib;
    _702_t11 = 1;
    _702_t12 = $sub_int64_t(_702_n, _702_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _702_t10 = _702_t9(_702_t12);
    $line_idx--;
    _702_t13 = _702_fib;
    _702_t15 = 2;
    _702_t16 = $sub_int64_t(_702_n, _702_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _702_t14 = _702_t13(_702_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _702_t8 = _702_t7(_702_t10, _702_t14);
    $line_idx--;
    _702_t0 = _702_t8;
    goto BB5;
}

int64_t _707_add(int64_t _707_x,int64_t _707_y) {
    int64_t _707_$retval;
    _707_$retval = $add_int64_t(_707_x, _707_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _707_$retval;
}

int main(void) {
  printf("%ld",_700_main());
  return 0;
}
