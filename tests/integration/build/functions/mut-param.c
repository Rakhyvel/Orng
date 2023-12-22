/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _949_main(void);
int64_t _951_sum_down(int64_t _951_x);

/* Function definitions */
int64_t _949_main(void){
    function0 _949_t0;
    int64_t _949_t2;
    int64_t _949_t1;
    int64_t _949_t3;
    int64_t _949_$retval;
    _949_t0 = _951_sum_down;
    _949_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _949_t1 = _949_t0(_949_t2);
    $line_idx--;
    _949_t3 = 2;
    _949_$retval = $add_int64_t(_949_t1, _949_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _949_$retval;
}

int64_t _951_sum_down(int64_t _951_x){
    int64_t _953_i;
    int64_t _951_t1;
    uint8_t _951_t2;
    int64_t _951_t4;
    int64_t _951_$retval;
    _953_i = _951_x;
    goto BB1174;
BB1174:
    _951_t1 = 0;
    _951_t2 = _953_i >= _951_t1;
    if (_951_t2) {
        goto BB1175;
    } else {
        goto BB1180;
    }
BB1175:
    _951_x = $add_int64_t(_951_x, _953_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _951_t4 = 1;
    _953_i = $sub_int64_t(_953_i, _951_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1174;
BB1180:
    _951_$retval = _951_x;
    return _951_$retval;
}

int main(void) {
  printf("%ld",_949_main());
  return 0;
}
