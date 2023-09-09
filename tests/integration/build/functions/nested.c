/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Function forward definitions */
int64_t _2_main();
int64_t _4_fib(int64_t _4_n);
int64_t _9_add(int64_t _9_x,int64_t _9_y);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t0;
    int64_t _2_t2;
    int64_t _2_$retval;
BB0:
    _2_t1 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _2_t0 = _4_fib(_2_t1);
    $line_idx--;
    _2_t2 = 10;
    _2_$retval = _2_t0 - _2_t2;
    return _2_$retval;
}

int64_t _4_fib(int64_t _4_n) {
    int64_t _4_t1;
    uint8_t _4_t2;
    int64_t _4_t0;
    int64_t _4_$retval;
    int64_t _4_t3;
    uint8_t _4_t4;
    int64_t _4_t9;
    int64_t _4_t10;
    int64_t _4_t8;
    int64_t _4_t12;
    int64_t _4_t13;
    int64_t _4_t11;
    int64_t _4_t7;
BB1:
    _4_t1 = 0;
    _4_t2 = _4_n == _4_t1;
    if (_4_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB6:
    _4_t3 = 1;
    _4_t4 = _4_n == _4_t3;
    if (_4_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB10:
    _4_t9 = 1;
    _4_t10 = _4_n - _4_t9;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _4_t8 = _4_fib(_4_t10);
    $line_idx--;
    _4_t12 = 2;
    _4_t13 = _4_n - _4_t12;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _4_t11 = _4_fib(_4_t13);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _4_t7 = _9_add(_4_t8, _4_t11);
    $line_idx--;
    _4_t0 = _4_t7;
    goto BB5;
BB5:
    _4_$retval = _4_t0;
    return _4_$retval;
BB8:
    _4_t0 = 1;
    goto BB5;
BB3:
    _4_t0 = 0;
    goto BB5;
}

int64_t _9_add(int64_t _9_x,int64_t _9_y) {
    int64_t _9_$retval;
BB0:
    _9_$retval = _9_x + _9_y;
    return _9_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
