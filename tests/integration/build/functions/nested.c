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
int64_t _884_main(void);
int64_t _886_fib(int64_t _886_n);
int64_t _892_add(int64_t _892_x,int64_t _892_y);

/* Function definitions */
int64_t _884_main(void) {
    function0 _884_t0;
    int64_t _884_t2;
    int64_t _884_t1;
    int64_t _884_t3;
    int64_t _884_$retval;
    _884_t0 = _886_fib;
    _884_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _884_t1 = _884_t0(_884_t2);
    $line_idx--;
    _884_t3 = 10;
    _884_$retval = $sub_int64_t(_884_t1, _884_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _884_$retval;
}

int64_t _886_fib(int64_t _886_n) {
    function1 _886_t7;
    function0 _886_t9;
    int64_t _886_t11;
    int64_t _886_t12;
    int64_t _886_t10;
    function0 _886_t13;
    int64_t _886_t15;
    int64_t _886_t16;
    int64_t _886_t14;
    int64_t _886_t8;
    int64_t _886_t0;
    int64_t _886_t1;
    uint8_t _886_t2;
    int64_t _886_t3;
    uint8_t _886_t4;
    int64_t _886_$retval;
    _886_t1 = 0;
    _886_t2 = _886_n == _886_t1;
    if (_886_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _886_t0 = 0;
    goto BB5;
BB6:
    _886_t3 = 1;
    _886_t4 = _886_n == _886_t3;
    if (_886_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _886_$retval = _886_t0;
    return _886_$retval;
BB8:
    _886_t0 = 1;
    goto BB5;
BB10:
    _886_t7 = _892_add;
    _886_t9 = _886_fib;
    _886_t11 = 1;
    _886_t12 = $sub_int64_t(_886_n, _886_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _886_t10 = _886_t9(_886_t12);
    $line_idx--;
    _886_t13 = _886_fib;
    _886_t15 = 2;
    _886_t16 = $sub_int64_t(_886_n, _886_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _886_t14 = _886_t13(_886_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _886_t8 = _886_t7(_886_t10, _886_t14);
    $line_idx--;
    _886_t0 = _886_t8;
    goto BB5;
}

int64_t _892_add(int64_t _892_x,int64_t _892_y) {
    int64_t _892_$retval;
    _892_$retval = $add_int64_t(_892_x, _892_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _892_$retval;
}

int main(void) {
  printf("%ld",_884_main());
  return 0;
}
