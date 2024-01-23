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
int64_t _979_main(void);
int64_t _981_sum_down(int64_t _981_x);


/* Function definitions */
int64_t _979_main(void){
    function0 _979_t0;
    int64_t _979_t2;
    int64_t _979_t1;
    int64_t _979_t3;
    int64_t _979_$retval;
    _979_t0 = _981_sum_down;
    _979_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _979_t1 = _979_t0(_979_t2);
    $line_idx--;
    _979_t3 = 2;
    _979_$retval = $add_int64_t(_979_t1, _979_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _979_$retval;
}

int64_t _981_sum_down(int64_t _981_x){
    int64_t _983_i;
    int64_t _981_t1;
    uint8_t _981_t2;
    int64_t _981_t4;
    int64_t _981_$retval;
    _983_i = _981_x;
    goto BB1183;
BB1183:
    _981_t1 = 0;
    _981_t2 = _983_i>=_981_t1;
    if (_981_t2) {
        goto BB1184;
    } else {
        goto BB1189;
    }
BB1184:
    _981_x = $add_int64_t(_981_x, _983_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _981_t4 = 1;
    _983_i = $sub_int64_t(_983_i, _981_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1183;
BB1189:
    _981_$retval = _981_x;
    return _981_$retval;
}


int main(void) {
  printf("%ld",_979_main());
  return 0;
}
