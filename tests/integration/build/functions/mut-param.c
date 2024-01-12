/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _974_main(void);
int64_t _976_sum_down(int64_t _976_x);

/* Function definitions */
int64_t _974_main(void){
    function0 _974_t0;
    int64_t _974_t2;
    int64_t _974_t1;
    int64_t _974_t3;
    int64_t _974_$retval;
    _974_t0 = _976_sum_down;
    _974_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _974_t1 = _974_t0(_974_t2);
    $line_idx--;
    _974_t3 = 2;
    _974_$retval = $add_int64_t(_974_t1, _974_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _974_$retval;
}

int64_t _976_sum_down(int64_t _976_x){
    int64_t _978_i;
    int64_t _976_t1;
    uint8_t _976_t2;
    int64_t _976_t4;
    int64_t _976_$retval;
    _978_i = _976_x;
    goto BB1179;
BB1179:
    _976_t1 = 0;
    _976_t2 = _978_i>=_976_t1;
    if (_976_t2) {
        goto BB1180;
    } else {
        goto BB1185;
    }
BB1180:
    _976_x = $add_int64_t(_976_x, _978_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _976_t4 = 1;
    _978_i = $sub_int64_t(_978_i, _976_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1179;
BB1185:
    _976_$retval = _976_x;
    return _976_$retval;
}

int main(void) {
  printf("%ld",_974_main());
  return 0;
}
