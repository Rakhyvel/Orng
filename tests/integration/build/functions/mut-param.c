/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _912_main(void);
int64_t _914_sum_down(int64_t _914_x);

/* Function definitions */
int64_t _912_main(void){
    function0 _912_t0;
    int64_t _912_t2;
    int64_t _912_t1;
    int64_t _912_t3;
    int64_t _912_$retval;
    _912_t0 = _914_sum_down;
    _912_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _912_t1 = _912_t0(_912_t2);
    $line_idx--;
    _912_t3 = 2;
    _912_$retval = $add_int64_t(_912_t1, _912_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _912_$retval;
}

int64_t _914_sum_down(int64_t _914_x){
    int64_t _916_i;
    int64_t _914_t1;
    uint8_t _914_t2;
    int64_t _914_t4;
    int64_t _914_$retval;
    _916_i = _914_x;
    goto BB1;
BB1:
    _914_t1 = 0;
    _914_t2 = _916_i >= _914_t1;
    if (_914_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _914_x = $add_int64_t(_914_x, _916_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _914_t4 = 1;
    _916_i = $sub_int64_t(_916_i, _914_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _914_$retval = _914_x;
    return _914_$retval;
}

int main(void) {
  printf("%ld",_912_main());
  return 0;
}
