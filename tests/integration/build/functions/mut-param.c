/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _904_main(void);
int64_t _906_sum_down(int64_t _906_x);

/* Function definitions */
int64_t _904_main(void) {
    function0 _904_t0;
    int64_t _904_t2;
    int64_t _904_t1;
    int64_t _904_t3;
    int64_t _904_$retval;
    _904_t0 = _906_sum_down;
    _904_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _904_t1 = _904_t0(_904_t2);
    $line_idx--;
    _904_t3 = 2;
    _904_$retval = $add_int64_t(_904_t1, _904_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _904_$retval;
}

int64_t _906_sum_down(int64_t _906_x) {
    int64_t _908_i;
    int64_t _906_t1;
    uint8_t _906_t2;
    int64_t _906_t4;
    int64_t _906_$retval;
    _908_i = _906_x;
    goto BB1;
BB1:
    _906_t1 = 0;
    _906_t2 = _908_i >= _906_t1;
    if (_906_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _906_x = $add_int64_t(_906_x, _908_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _906_t4 = 1;
    _908_i = $sub_int64_t(_908_i, _906_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _906_$retval = _906_x;
    return _906_$retval;
}

int main(void) {
  printf("%ld",_904_main());
  return 0;
}
