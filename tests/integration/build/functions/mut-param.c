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
int64_t _991_main(void);
int64_t _993_sum_down(int64_t _993_x);


/* Function definitions */
int64_t _991_main(void){
    function0 _991_t0;
    int64_t _991_t2;
    int64_t _991_t1;
    int64_t _991_t3;
    int64_t _991_$retval;
    _991_t0 = (function0) _993_sum_down;
    _991_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _991_t1 = _991_t0(_991_t2);
    $line_idx--;
    _991_t3 = 2;
    _991_$retval = $add_int64_t(_991_t1, _991_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _991_$retval;
}

int64_t _993_sum_down(int64_t _993_x){
    int64_t _995_i;
    int64_t _993_t2;
    uint8_t _993_t3;
    int64_t _993_t5;
    int64_t _993_$retval;
    _995_i = _993_x;
    goto BB1167;
BB1167:
    _993_t2 = 0;
    _993_t3 = _995_i>=_993_t2;
    if (_993_t3) {
        goto BB1168;
    } else {
        goto BB1173;
    }
BB1168:
    _993_x = $add_int64_t(_993_x, _995_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _993_t5 = 1;
    _995_i = $sub_int64_t(_995_i, _993_t5, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1167;
BB1173:
    _993_$retval = _993_x;
    return _993_$retval;
}


int main(void) {
  printf("%ld",_991_main());
  return 0;
}
