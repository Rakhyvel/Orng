/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _683_main(void);
int64_t _685_sum_down(int64_t _685_x);

/* Function definitions */
int64_t _683_main(void) {
    function0 _683_t0;
    int64_t _683_t2;
    int64_t _683_t1;
    int64_t _683_t3;
    int64_t _683_$retval;
    _683_t0 = _685_sum_down;
    _683_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _683_t1 = _683_t0(_683_t2);
    $line_idx--;
    _683_t3 = 2;
    _683_$retval = $add_int64_t(_683_t1, _683_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _683_$retval;
}

int64_t _685_sum_down(int64_t _685_x) {
    int64_t _687_i;
    int64_t _685_t1;
    uint8_t _685_t2;
    int64_t _685_t4;
    int64_t _685_$retval;
    _687_i = _685_x;
    goto BB1;
BB1:
    _685_t1 = 0;
    _685_t2 = _687_i >= _685_t1;
    if (_685_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _685_x = $add_int64_t(_685_x, _687_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _685_t4 = 1;
    _687_i = $sub_int64_t(_687_i, _685_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _685_$retval = _685_x;
    return _685_$retval;
}

int main(void) {
  printf("%ld",_683_main());
  return 0;
}
