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
int64_t _724_main(void);
int64_t _726_fib(int64_t _726_n);
int64_t _731_add(int64_t _731_x,int64_t _731_y);

/* Function definitions */
int64_t _724_main(void) {
    function0 _724_t0;
    int64_t _724_t2;
    int64_t _724_t1;
    int64_t _724_t3;
    int64_t _724_$retval;
    _724_t0 = _726_fib;
    _724_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _724_t1 = _724_t0(_724_t2);
    $line_idx--;
    _724_t3 = 10;
    _724_$retval = $sub_int64_t(_724_t1, _724_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _724_$retval;
}

int64_t _726_fib(int64_t _726_n) {
    function1 _726_t7;
    function0 _726_t9;
    int64_t _726_t11;
    int64_t _726_t12;
    int64_t _726_t10;
    function0 _726_t13;
    int64_t _726_t15;
    int64_t _726_t16;
    int64_t _726_t14;
    int64_t _726_t8;
    int64_t _726_t0;
    int64_t _726_t1;
    uint8_t _726_t2;
    int64_t _726_t3;
    uint8_t _726_t4;
    int64_t _726_$retval;
    _726_t1 = 0;
    _726_t2 = _726_n == _726_t1;
    if (_726_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _726_t0 = 0;
    goto BB5;
BB6:
    _726_t3 = 1;
    _726_t4 = _726_n == _726_t3;
    if (_726_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _726_$retval = _726_t0;
    return _726_$retval;
BB8:
    _726_t0 = 1;
    goto BB5;
BB10:
    _726_t7 = _731_add;
    _726_t9 = _726_fib;
    _726_t11 = 1;
    _726_t12 = $sub_int64_t(_726_n, _726_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _726_t10 = _726_t9(_726_t12);
    $line_idx--;
    _726_t13 = _726_fib;
    _726_t15 = 2;
    _726_t16 = $sub_int64_t(_726_n, _726_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _726_t14 = _726_t13(_726_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _726_t8 = _726_t7(_726_t10, _726_t14);
    $line_idx--;
    _726_t0 = _726_t8;
    goto BB5;
}

int64_t _731_add(int64_t _731_x,int64_t _731_y) {
    int64_t _731_$retval;
    _731_$retval = $add_int64_t(_731_x, _731_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _731_$retval;
}

int main(void) {
  printf("%ld",_724_main());
  return 0;
}
