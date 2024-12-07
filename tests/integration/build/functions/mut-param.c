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
int64_t _986_main(void);
int64_t _988_sum_down(int64_t _988_x);


/* Function definitions */
int64_t _986_main(void){
    function0 _986_t0;
    int64_t _986_t2;
    int64_t _986_t1;
    int64_t _986_t3;
    int64_t _986_$retval;
    _986_t0 = (function0) _988_sum_down;
    _986_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _986_t1 = _986_t0(_986_t2);
    $line_idx--;
    _986_t3 = 2;
    _986_$retval = $add_int64_t(_986_t1, _986_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _986_$retval;
}

int64_t _988_sum_down(int64_t _988_x){
    int64_t _990_i;
    int64_t _988_t2;
    uint8_t _988_t3;
    int64_t _988_t5;
    int64_t _988_$retval;
    _990_i = _988_x;
    goto BB1164;
BB1164:
    _988_t2 = 0;
    _988_t3 = _990_i>=_988_t2;
    if (_988_t3) {
        goto BB1165;
    } else {
        goto BB1170;
    }
BB1165:
    _988_x = $add_int64_t(_988_x, _990_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _988_t5 = 1;
    _990_i = $sub_int64_t(_990_i, _988_t5, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1164;
BB1170:
    _988_$retval = _988_x;
    return _988_$retval;
}


int main(void) {
  printf("%ld",_986_main());
  return 0;
}
