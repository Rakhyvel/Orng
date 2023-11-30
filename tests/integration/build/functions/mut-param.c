/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _863_main(void);
int64_t _865_sum_down(int64_t _865_x);

/* Function definitions */
int64_t _863_main(void) {
    function0 _863_t0;
    int64_t _863_t2;
    int64_t _863_t1;
    int64_t _863_t3;
    int64_t _863_$retval;
    _863_t0 = _865_sum_down;
    _863_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _863_t1 = _863_t0(_863_t2);
    $line_idx--;
    _863_t3 = 2;
    _863_$retval = $add_int64_t(_863_t1, _863_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _863_$retval;
}

int64_t _865_sum_down(int64_t _865_x) {
    int64_t _868_i;
    int64_t _865_t1;
    uint8_t _865_t2;
    int64_t _865_t4;
    int64_t _865_$retval;
    _868_i = _865_x;
    goto BB1;
BB1:
    _865_t1 = 0;
    _865_t2 = _868_i >= _865_t1;
    if (_865_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _865_x = $add_int64_t(_865_x, _868_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _865_t4 = 1;
    _868_i = $sub_int64_t(_868_i, _865_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _865_$retval = _865_x;
    return _865_$retval;
}

int main(void) {
  printf("%ld",_863_main());
  return 0;
}
