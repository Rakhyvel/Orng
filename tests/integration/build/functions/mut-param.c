/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1068_main(void);
int64_t _1070_sum_down(int64_t _1070_x);

/* Function definitions */
int64_t _1068_main(void){
    function0 _1068_t0;
    int64_t _1068_t2;
    int64_t _1068_t1;
    int64_t _1068_t3;
    int64_t _1068_$retval;
    _1068_t0 = _1070_sum_down;
    _1068_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _1068_t1 = _1068_t0(_1068_t2);
    $line_idx--;
    _1068_t3 = 2;
    _1068_$retval = $add_int64_t(_1068_t1, _1068_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _1068_$retval;
}

int64_t _1070_sum_down(int64_t _1070_x){
    int64_t _1072_i;
    int64_t _1070_t1;
    uint8_t _1070_t2;
    int64_t _1070_t4;
    int64_t _1070_$retval;
    _1072_i = _1070_x;
    goto BB1;
BB1:
    _1070_t1 = 0;
    _1070_t2 = _1072_i >= _1070_t1;
    if (_1070_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1070_x = $add_int64_t(_1070_x, _1072_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _1070_t4 = 1;
    _1072_i = $sub_int64_t(_1072_i, _1070_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _1070_$retval = _1070_x;
    return _1070_$retval;
}

int main(void) {
  printf("%ld",_1068_main());
  return 0;
}
