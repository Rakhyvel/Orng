/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _36_main(void);
int64_t _38_sum_down(int64_t _38_x);

/* Function definitions */
int64_t _36_main(void) {
    function0 _36_t0;
    int64_t _36_t2;
    int64_t _36_t1;
    int64_t _36_t3;
    int64_t _36_$retval;
    _36_t0 = _38_sum_down;
    _36_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _36_t1 = _36_t0(_36_t2);
    $line_idx--;
    _36_t3 = 2;
    _36_$retval = $add_int64_t(_36_t1, _36_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _36_$retval;
}

int64_t _38_sum_down(int64_t _38_x) {
    int64_t _40_i;
    int64_t _38_t1;
    uint8_t _38_t2;
    int64_t _38_t4;
    int64_t _38_$retval;
    _40_i = _38_x;
    goto BB1;
BB1:
    _38_t1 = 0;
    _38_t2 = _40_i >= _38_t1;
    if (_38_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _38_x = $add_int64_t(_38_x, _40_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _38_t4 = 1;
    _40_i = $sub_int64_t(_40_i, _38_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _38_$retval = _38_x;
    return _38_$retval;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
