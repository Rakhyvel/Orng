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
int64_t _740_main(void);
int64_t _742_fib(int64_t _742_n);
int64_t _747_add(int64_t _747_x,int64_t _747_y);

/* Function definitions */
int64_t _740_main(void) {
    function0 _740_t0;
    int64_t _740_t2;
    int64_t _740_t1;
    int64_t _740_t3;
    int64_t _740_$retval;
    _740_t0 = _742_fib;
    _740_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _740_t1 = _740_t0(_740_t2);
    $line_idx--;
    _740_t3 = 10;
    _740_$retval = $sub_int64_t(_740_t1, _740_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _740_$retval;
}

int64_t _742_fib(int64_t _742_n) {
    function1 _742_t7;
    function0 _742_t9;
    int64_t _742_t11;
    int64_t _742_t12;
    int64_t _742_t10;
    function0 _742_t13;
    int64_t _742_t15;
    int64_t _742_t16;
    int64_t _742_t14;
    int64_t _742_t8;
    int64_t _742_t0;
    int64_t _742_t1;
    uint8_t _742_t2;
    int64_t _742_t3;
    uint8_t _742_t4;
    int64_t _742_$retval;
    _742_t1 = 0;
    _742_t2 = _742_n == _742_t1;
    if (_742_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _742_t0 = 0;
    goto BB5;
BB6:
    _742_t3 = 1;
    _742_t4 = _742_n == _742_t3;
    if (_742_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _742_$retval = _742_t0;
    return _742_$retval;
BB8:
    _742_t0 = 1;
    goto BB5;
BB10:
    _742_t7 = _747_add;
    _742_t9 = _742_fib;
    _742_t11 = 1;
    _742_t12 = $sub_int64_t(_742_n, _742_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _742_t10 = _742_t9(_742_t12);
    $line_idx--;
    _742_t13 = _742_fib;
    _742_t15 = 2;
    _742_t16 = $sub_int64_t(_742_n, _742_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _742_t14 = _742_t13(_742_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _742_t8 = _742_t7(_742_t10, _742_t14);
    $line_idx--;
    _742_t0 = _742_t8;
    goto BB5;
}

int64_t _747_add(int64_t _747_x,int64_t _747_y) {
    int64_t _747_$retval;
    _747_$retval = $add_int64_t(_747_x, _747_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _747_$retval;
}

int main(void) {
  printf("%ld",_740_main());
  return 0;
}
