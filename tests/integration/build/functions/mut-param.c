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
int64_t _1006_main(void);
int64_t _1008_sum_down(int64_t _1008_x);


/* Function definitions */
int64_t _1006_main(void){
    function0 _1006_t0;
    int64_t _1006_t2;
    int64_t _1006_t1;
    int64_t _1006_t3;
    int64_t _1006_$retval;
    _1006_t0 = _1008_sum_down;
    _1006_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _1006_t1 = _1006_t0(_1006_t2);
    $line_idx--;
    _1006_t3 = 2;
    _1006_$retval = $add_int64_t(_1006_t1, _1006_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _1006_$retval;
}

int64_t _1008_sum_down(int64_t _1008_x){
    int64_t _1010_i;
    int64_t _1008_t1;
    uint8_t _1008_t2;
    int64_t _1008_t4;
    int64_t _1008_$retval;
    _1010_i = _1008_x;
    goto BB1205;
BB1205:
    _1008_t1 = 0;
    _1008_t2 = _1010_i>=_1008_t1;
    if (_1008_t2) {
        goto BB1206;
    } else {
        goto BB1211;
    }
BB1206:
    _1008_x = $add_int64_t(_1008_x, _1010_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _1008_t4 = 1;
    _1010_i = $sub_int64_t(_1010_i, _1008_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1205;
BB1211:
    _1008_$retval = _1008_x;
    return _1008_$retval;
}


int main(void) {
  printf("%ld",_1006_main());
  return 0;
}
