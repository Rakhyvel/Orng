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
int64_t _637_main(void);
int64_t _639_fib(int64_t _639_n);
int64_t _644_add(int64_t _644_x,int64_t _644_y);

/* Function definitions */
int64_t _637_main(void) {
    function0 _637_t0;
    int64_t _637_t2;
    int64_t _637_t1;
    int64_t _637_t3;
    int64_t _637_$retval;
    _637_t0 = _639_fib;
    _637_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _637_t1 = _637_t0(_637_t2);
    $line_idx--;
    _637_t3 = 10;
    _637_$retval = $sub_int64_t(_637_t1, _637_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _637_$retval;
}

int64_t _639_fib(int64_t _639_n) {
    function1 _639_t7;
    function0 _639_t9;
    int64_t _639_t11;
    int64_t _639_t12;
    int64_t _639_t10;
    function0 _639_t13;
    int64_t _639_t15;
    int64_t _639_t16;
    int64_t _639_t14;
    int64_t _639_t8;
    int64_t _639_t0;
    int64_t _639_t1;
    uint8_t _639_t2;
    int64_t _639_t3;
    uint8_t _639_t4;
    int64_t _639_$retval;
    _639_t1 = 0;
    _639_t2 = _639_n == _639_t1;
    if (_639_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _639_t0 = 0;
    goto BB5;
BB6:
    _639_t3 = 1;
    _639_t4 = _639_n == _639_t3;
    if (_639_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _639_$retval = _639_t0;
    return _639_$retval;
BB8:
    _639_t0 = 1;
    goto BB5;
BB10:
    _639_t7 = _644_add;
    _639_t9 = _639_fib;
    _639_t11 = 1;
    _639_t12 = $sub_int64_t(_639_n, _639_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _639_t10 = _639_t9(_639_t12);
    $line_idx--;
    _639_t13 = _639_fib;
    _639_t15 = 2;
    _639_t16 = $sub_int64_t(_639_n, _639_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _639_t14 = _639_t13(_639_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _639_t8 = _639_t7(_639_t10, _639_t14);
    $line_idx--;
    _639_t0 = _639_t8;
    goto BB5;
}

int64_t _644_add(int64_t _644_x,int64_t _644_y) {
    int64_t _644_$retval;
    _644_$retval = $add_int64_t(_644_x, _644_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _644_$retval;
}

int main(void) {
  printf("%ld",_637_main());
  return 0;
}
