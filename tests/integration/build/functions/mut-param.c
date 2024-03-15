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
int64_t _972_main(void);
int64_t _974_sum_down(int64_t _974_x);


/* Function definitions */
int64_t _972_main(void){
    function0 _972_t0;
    int64_t _972_t2;
    int64_t _972_t1;
    int64_t _972_t3;
    int64_t _972_$retval;
    _972_t0 = (function0) _974_sum_down;
    _972_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _972_t1 = _972_t0(_972_t2);
    $line_idx--;
    _972_t3 = 2;
    _972_$retval = $add_int64_t(_972_t1, _972_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _972_$retval;
}

int64_t _974_sum_down(int64_t _974_x){
    int64_t _976_i;
    int64_t _974_t2;
    uint8_t _974_t3;
    int64_t _974_t5;
    int64_t _974_$retval;
    _976_i = _974_x;
    goto BB1145;
BB1145:
    _974_t2 = 0;
    _974_t3 = _976_i>=_974_t2;
    if (_974_t3) {
        goto BB1146;
    } else {
        goto BB1151;
    }
BB1146:
    _974_x = $add_int64_t(_974_x, _976_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _974_t5 = 1;
    _976_i = $sub_int64_t(_976_i, _974_t5, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1145;
BB1151:
    _974_$retval = _974_x;
    return _974_$retval;
}


int main(void) {
  printf("%ld",_972_main());
  return 0;
}
