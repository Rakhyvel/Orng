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
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _2_t0 = _4_fib(10);
    $line_idx--;
    _2_$retval = _2_t0 - 10;
    return _2_$retval;
}

int64_t _4_fib(int64_t _4_n) {
    int64_t _4_t8;
    int64_t _4_t11;
    int64_t _4_t7;
    int64_t _4_t0;
    int64_t _4_$retval;
    if (_4_n) {
        goto BB6;
    } else {
        goto BB3;
    }
BB6:
    if (_4_n == 1) {
        goto BB8;
    } else {
        goto BB10;
    }
BB3:
    _4_t0 = 0;
    goto BB5;
BB8:
    _4_t0 = 1;
    goto BB5;
BB10:
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _4_t8 = _4_fib(_4_n - 1);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _4_t11 = _4_fib(_4_n - 2);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _4_t7 = _9_add(_4_t8, _4_t11);
    $line_idx--;
    _4_t0 = _4_t7;
BB5:
    _4_$retval = _4_t0;
    return _4_$retval;
}

int64_t _9_add(int64_t _9_x,int64_t _9_y) {
    int64_t _9_$retval;
    _9_$retval = _9_x + _9_y;
    return _9_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
