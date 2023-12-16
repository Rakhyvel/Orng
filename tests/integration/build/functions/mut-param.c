/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _983_main(void);
int64_t _985_sum_down(int64_t _985_x);

/* Function definitions */
int64_t _983_main(void){
    function0 _983_t0;
    int64_t _983_t2;
    int64_t _983_t1;
    int64_t _983_t3;
    int64_t _983_$retval;
    _983_t0 = _985_sum_down;
    _983_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _983_t1 = _983_t0(_983_t2);
    $line_idx--;
    _983_t3 = 2;
    _983_$retval = $add_int64_t(_983_t1, _983_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _983_$retval;
}

int64_t _985_sum_down(int64_t _985_x){
    int64_t _987_i;
    int64_t _985_t1;
    uint8_t _985_t2;
    int64_t _985_t4;
    int64_t _985_$retval;
    _987_i = _985_x;
    goto BB1;
BB1:
    _985_t1 = 0;
    _985_t2 = _987_i >= _985_t1;
    if (_985_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _985_x = $add_int64_t(_985_x, _987_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _985_t4 = 1;
    _987_i = $sub_int64_t(_987_i, _985_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _985_$retval = _985_x;
    return _985_$retval;
}

int main(void) {
  printf("%ld",_983_main());
  return 0;
}
