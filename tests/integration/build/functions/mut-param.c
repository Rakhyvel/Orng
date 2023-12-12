/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _715_main(void);
int64_t _717_sum_down(int64_t _717_x);

/* Function definitions */
int64_t _715_main(void) {
    function0 _715_t0;
    int64_t _715_t2;
    int64_t _715_t1;
    int64_t _715_t3;
    int64_t _715_$retval;
    _715_t0 = _717_sum_down;
    _715_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _715_t1 = _715_t0(_715_t2);
    $line_idx--;
    _715_t3 = 2;
    _715_$retval = $add_int64_t(_715_t1, _715_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _715_$retval;
}

int64_t _717_sum_down(int64_t _717_x) {
    int64_t _719_i;
    int64_t _717_t1;
    uint8_t _717_t2;
    int64_t _717_t4;
    int64_t _717_$retval;
    _719_i = _717_x;
    goto BB1;
BB1:
    _717_t1 = 0;
    _717_t2 = _719_i >= _717_t1;
    if (_717_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _717_x = $add_int64_t(_717_x, _719_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _717_t4 = 1;
    _719_i = $sub_int64_t(_719_i, _717_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _717_$retval = _717_x;
    return _717_$retval;
}

int main(void) {
  printf("%ld",_715_main());
  return 0;
}
