/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1075_main(void);
int64_t _1077_sum_down(int64_t _1077_x);

/* Function definitions */
int64_t _1075_main(void){
    function0 _1075_t0;
    int64_t _1075_t2;
    int64_t _1075_t1;
    int64_t _1075_t3;
    int64_t _1075_$retval;
    _1075_t0 = _1077_sum_down;
    _1075_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _1075_t1 = _1075_t0(_1075_t2);
    $line_idx--;
    _1075_t3 = 2;
    _1075_$retval = $add_int64_t(_1075_t1, _1075_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _1075_$retval;
}

int64_t _1077_sum_down(int64_t _1077_x){
    int64_t _1079_i;
    int64_t _1077_t1;
    uint8_t _1077_t2;
    int64_t _1077_t4;
    int64_t _1077_$retval;
    _1079_i = _1077_x;
    goto BB1;
BB1:
    _1077_t1 = 0;
    _1077_t2 = _1079_i >= _1077_t1;
    if (_1077_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1077_x = $add_int64_t(_1077_x, _1079_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _1077_t4 = 1;
    _1079_i = $sub_int64_t(_1079_i, _1077_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _1077_$retval = _1077_x;
    return _1077_$retval;
}

int main(void) {
  printf("%ld",_1075_main());
  return 0;
}
