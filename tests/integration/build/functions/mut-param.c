/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _707_main(void);
int64_t _709_sum_down(int64_t _709_x);

/* Function definitions */
int64_t _707_main(void) {
    function0 _707_t0;
    int64_t _707_t2;
    int64_t _707_t1;
    int64_t _707_t3;
    int64_t _707_$retval;
    _707_t0 = _709_sum_down;
    _707_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _707_t1 = _707_t0(_707_t2);
    $line_idx--;
    _707_t3 = 2;
    _707_$retval = $add_int64_t(_707_t1, _707_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _707_$retval;
}

int64_t _709_sum_down(int64_t _709_x) {
    int64_t _711_i;
    int64_t _709_t1;
    uint8_t _709_t2;
    int64_t _709_t4;
    int64_t _709_$retval;
    _711_i = _709_x;
    goto BB1;
BB1:
    _709_t1 = 0;
    _709_t2 = _711_i >= _709_t1;
    if (_709_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _709_x = $add_int64_t(_709_x, _711_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _709_t4 = 1;
    _711_i = $sub_int64_t(_711_i, _709_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _709_$retval = _709_x;
    return _709_$retval;
}

int main(void) {
  printf("%ld",_707_main());
  return 0;
}
