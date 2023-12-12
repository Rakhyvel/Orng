/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _734_main(void);
int64_t _736_sum_down(int64_t _736_x);

/* Function definitions */
int64_t _734_main(void) {
    function0 _734_t0;
    int64_t _734_t2;
    int64_t _734_t1;
    int64_t _734_t3;
    int64_t _734_$retval;
    _734_t0 = _736_sum_down;
    _734_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _734_t1 = _734_t0(_734_t2);
    $line_idx--;
    _734_t3 = 2;
    _734_$retval = $add_int64_t(_734_t1, _734_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _734_$retval;
}

int64_t _736_sum_down(int64_t _736_x) {
    int64_t _738_i;
    int64_t _736_t1;
    uint8_t _736_t2;
    int64_t _736_t4;
    int64_t _736_$retval;
    _738_i = _736_x;
    goto BB1;
BB1:
    _736_t1 = 0;
    _736_t2 = _738_i >= _736_t1;
    if (_736_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _736_x = $add_int64_t(_736_x, _738_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _736_t4 = 1;
    _738_i = $sub_int64_t(_738_i, _736_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _736_$retval = _736_x;
    return _736_$retval;
}

int main(void) {
  printf("%ld",_734_main());
  return 0;
}
