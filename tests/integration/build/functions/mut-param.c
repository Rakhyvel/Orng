/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _651_main(void);
int64_t _653_sum_down(int64_t _653_x);

/* Function definitions */
int64_t _651_main(void) {
    function0 _651_t0;
    int64_t _651_t2;
    int64_t _651_t1;
    int64_t _651_t3;
    int64_t _651_$retval;
    _651_t0 = _653_sum_down;
    _651_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _651_t1 = _651_t0(_651_t2);
    $line_idx--;
    _651_t3 = 2;
    _651_$retval = $add_int64_t(_651_t1, _651_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _651_$retval;
}

int64_t _653_sum_down(int64_t _653_x) {
    int64_t _655_i;
    int64_t _653_t1;
    uint8_t _653_t2;
    int64_t _653_t4;
    int64_t _653_$retval;
    _655_i = _653_x;
    goto BB1;
BB1:
    _653_t1 = 0;
    _653_t2 = _655_i >= _653_t1;
    if (_653_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _653_x = $add_int64_t(_653_x, _655_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _653_t4 = 1;
    _655_i = $sub_int64_t(_655_i, _653_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _653_$retval = _653_x;
    return _653_$retval;
}

int main(void) {
  printf("%ld",_651_main());
  return 0;
}
