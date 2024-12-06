/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _978_main(void);
int64_t _980_sum_down(int64_t _980_x);


/* Function definitions */
int64_t _978_main(void){
    function0 _978_t0;
    int64_t _978_t2;
    int64_t _978_t1;
    int64_t _978_t3;
    int64_t _978_$retval;
    _978_t0 = (function0) _980_sum_down;
    _978_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _978_t1 = _978_t0(_978_t2);
    $line_idx--;
    _978_t3 = 2;
    _978_$retval = $add_int64_t(_978_t1, _978_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _978_$retval;
}

int64_t _980_sum_down(int64_t _980_x){
    int64_t _982_i;
    int64_t _980_t2;
    uint8_t _980_t3;
    int64_t _980_t5;
    int64_t _980_$retval;
    _982_i = _980_x;
    goto BB1154;
BB1154:
    _980_t2 = 0;
    _980_t3 = _982_i>=_980_t2;
    if (_980_t3) {
        goto BB1155;
    } else {
        goto BB1160;
    }
BB1155:
    _980_x = $add_int64_t(_980_x, _982_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _980_t5 = 1;
    _982_i = $sub_int64_t(_982_i, _980_t5, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1154;
BB1160:
    _980_$retval = _980_x;
    return _980_$retval;
}


int main(void) {
  printf("%ld",_978_main());
  return 0;
}
