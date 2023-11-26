/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _620_main(void);
int64_t _622_sum_down(int64_t _622_x);

/* Function definitions */
int64_t _620_main(void) {
    function0 _620_t0;
    int64_t _620_t2;
    int64_t _620_t1;
    int64_t _620_t3;
    int64_t _620_$retval;
    _620_t0 = _622_sum_down;
    _620_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _620_t1 = _620_t0(_620_t2);
    $line_idx--;
    _620_t3 = 2;
    _620_$retval = $add_int64_t(_620_t1, _620_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _620_$retval;
}

int64_t _622_sum_down(int64_t _622_x) {
    int64_t _624_i;
    int64_t _622_t1;
    uint8_t _622_t2;
    int64_t _622_t4;
    int64_t _622_$retval;
    _624_i = _622_x;
    goto BB1;
BB1:
    _622_t1 = 0;
    _622_t2 = _624_i >= _622_t1;
    if (_622_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _622_x = $add_int64_t(_622_x, _624_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _622_t4 = 1;
    _624_i = $sub_int64_t(_624_i, _622_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _622_$retval = _622_x;
    return _622_$retval;
}

int main(void) {
  printf("%ld",_620_main());
  return 0;
}
