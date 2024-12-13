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
int64_t _1008_main(void);
int64_t _1010_sum_down(int64_t _1010_x);


/* Function definitions */
int64_t _1008_main(void){
    function0 _1008_t0;
    int64_t _1008_t2;
    int64_t _1008_t1;
    int64_t _1008_t3;
    int64_t _1008_$retval;
    _1008_t0 = (function0) _1010_sum_down;
    _1008_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _1008_t1 = _1008_t0(_1008_t2);
    $line_idx--;
    _1008_t3 = 2;
    _1008_$retval = $add_int64_t(_1008_t1, _1008_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _1008_$retval;
}

int64_t _1010_sum_down(int64_t _1010_x){
    int64_t _1012_i;
    int64_t _1010_t2;
    uint8_t _1010_t3;
    int64_t _1010_t5;
    int64_t _1010_$retval;
    _1012_i = _1010_x;
    goto BB1185;
BB1185:
    _1010_t2 = 0;
    _1010_t3 = _1012_i>=_1010_t2;
    if (_1010_t3) {
        goto BB1186;
    } else {
        goto BB1191;
    }
BB1186:
    _1010_x = $add_int64_t(_1010_x, _1012_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _1010_t5 = 1;
    _1012_i = $sub_int64_t(_1012_i, _1010_t5, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1185;
BB1191:
    _1010_$retval = _1010_x;
    return _1010_$retval;
}


int main(void) {
  printf("%ld",_1008_main());
  return 0;
}
