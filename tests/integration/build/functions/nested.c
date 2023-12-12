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
int64_t _751_main(void);
int64_t _753_fib(int64_t _753_n);
int64_t _758_add(int64_t _758_x,int64_t _758_y);

/* Function definitions */
int64_t _751_main(void) {
    function0 _751_t0;
    int64_t _751_t2;
    int64_t _751_t1;
    int64_t _751_t3;
    int64_t _751_$retval;
    _751_t0 = _753_fib;
    _751_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _751_t1 = _751_t0(_751_t2);
    $line_idx--;
    _751_t3 = 10;
    _751_$retval = $sub_int64_t(_751_t1, _751_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _751_$retval;
}

int64_t _753_fib(int64_t _753_n) {
    function1 _753_t7;
    function0 _753_t9;
    int64_t _753_t11;
    int64_t _753_t12;
    int64_t _753_t10;
    function0 _753_t13;
    int64_t _753_t15;
    int64_t _753_t16;
    int64_t _753_t14;
    int64_t _753_t8;
    int64_t _753_t0;
    int64_t _753_t1;
    uint8_t _753_t2;
    int64_t _753_t3;
    uint8_t _753_t4;
    int64_t _753_$retval;
    _753_t1 = 0;
    _753_t2 = _753_n == _753_t1;
    if (_753_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _753_t0 = 0;
    goto BB5;
BB6:
    _753_t3 = 1;
    _753_t4 = _753_n == _753_t3;
    if (_753_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _753_$retval = _753_t0;
    return _753_$retval;
BB8:
    _753_t0 = 1;
    goto BB5;
BB10:
    _753_t7 = _758_add;
    _753_t9 = _753_fib;
    _753_t11 = 1;
    _753_t12 = $sub_int64_t(_753_n, _753_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _753_t10 = _753_t9(_753_t12);
    $line_idx--;
    _753_t13 = _753_fib;
    _753_t15 = 2;
    _753_t16 = $sub_int64_t(_753_n, _753_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _753_t14 = _753_t13(_753_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _753_t8 = _753_t7(_753_t10, _753_t14);
    $line_idx--;
    _753_t0 = _753_t8;
    goto BB5;
}

int64_t _758_add(int64_t _758_x,int64_t _758_y) {
    int64_t _758_$retval;
    _758_$retval = $add_int64_t(_758_x, _758_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _758_$retval;
}

int main(void) {
  printf("%ld",_751_main());
  return 0;
}
