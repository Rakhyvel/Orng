/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _886_main(void);
int64_t _888_sum_down(int64_t _888_x);

/* Function definitions */
int64_t _886_main(void) {
    function0 _886_t0;
    int64_t _886_t2;
    int64_t _886_t1;
    int64_t _886_t3;
    int64_t _886_$retval;
    _886_t0 = _888_sum_down;
    _886_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _886_t1 = _886_t0(_886_t2);
    $line_idx--;
    _886_t3 = 2;
    _886_$retval = $add_int64_t(_886_t1, _886_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _886_$retval;
}

int64_t _888_sum_down(int64_t _888_x) {
    int64_t _891_i;
    int64_t _888_t1;
    uint8_t _888_t2;
    int64_t _888_t4;
    int64_t _888_$retval;
    _891_i = _888_x;
    goto BB1;
BB1:
    _888_t1 = 0;
    _888_t2 = _891_i >= _888_t1;
    if (_888_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _888_x = $add_int64_t(_888_x, _891_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _888_t4 = 1;
    _891_i = $sub_int64_t(_891_i, _888_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _888_$retval = _888_x;
    return _888_$retval;
}

int main(void) {
  printf("%ld",_886_main());
  return 0;
}
