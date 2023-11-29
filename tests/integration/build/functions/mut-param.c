/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _723_main(void);
int64_t _725_sum_down(int64_t _725_x);

/* Function definitions */
int64_t _723_main(void) {
    function0 _723_t0;
    int64_t _723_t2;
    int64_t _723_t1;
    int64_t _723_t3;
    int64_t _723_$retval;
    _723_t0 = _725_sum_down;
    _723_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _723_t1 = _723_t0(_723_t2);
    $line_idx--;
    _723_t3 = 2;
    _723_$retval = $add_int64_t(_723_t1, _723_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _723_$retval;
}

int64_t _725_sum_down(int64_t _725_x) {
    int64_t _727_i;
    int64_t _725_t1;
    uint8_t _725_t2;
    int64_t _725_t4;
    int64_t _725_$retval;
    _727_i = _725_x;
    goto BB1;
BB1:
    _725_t1 = 0;
    _725_t2 = _727_i >= _725_t1;
    if (_725_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _725_x = $add_int64_t(_725_x, _727_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _725_t4 = 1;
    _727_i = $sub_int64_t(_727_i, _725_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _725_$retval = _725_x;
    return _725_$retval;
}

int main(void) {
  printf("%ld",_723_main());
  return 0;
}
