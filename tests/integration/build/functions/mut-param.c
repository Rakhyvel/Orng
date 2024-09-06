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
int64_t _980_main(void);
int64_t _982_sum_down(int64_t _982_x);


/* Function definitions */
int64_t _980_main(void){
    function0 _980_t0;
    int64_t _980_t2;
    int64_t _980_t1;
    int64_t _980_t3;
    int64_t _980_$retval;
    _980_t0 = (function0) _982_sum_down;
    _980_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _980_t1 = _980_t0(_980_t2);
    $line_idx--;
    _980_t3 = 2;
    _980_$retval = $add_int64_t(_980_t1, _980_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _980_$retval;
}

int64_t _982_sum_down(int64_t _982_x){
    int64_t _984_i;
    int64_t _982_t2;
    uint8_t _982_t3;
    int64_t _982_t5;
    int64_t _982_$retval;
    _984_i = _982_x;
    goto BB1151;
BB1151:
    _982_t2 = 0;
    _982_t3 = _984_i>=_982_t2;
    if (_982_t3) {
        goto BB1152;
    } else {
        goto BB1157;
    }
BB1152:
    _982_x = $add_int64_t(_982_x, _984_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _982_t5 = 1;
    _984_i = $sub_int64_t(_984_i, _982_t5, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1151;
BB1157:
    _982_$retval = _982_x;
    return _982_$retval;
}


int main(void) {
  printf("%ld",_980_main());
  return 0;
}
