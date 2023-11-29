/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _884_main(void);
int64_t _886_sum_down(int64_t _886_x);

/* Function definitions */
int64_t _884_main(void) {
    function0 _884_t0;
    int64_t _884_t2;
    int64_t _884_t1;
    int64_t _884_t3;
    int64_t _884_$retval;
    _884_t0 = _886_sum_down;
    _884_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _884_t1 = _884_t0(_884_t2);
    $line_idx--;
    _884_t3 = 2;
    _884_$retval = $add_int64_t(_884_t1, _884_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _884_$retval;
}

int64_t _886_sum_down(int64_t _886_x) {
    int64_t _889_i;
    int64_t _886_t1;
    uint8_t _886_t2;
    int64_t _886_t4;
    int64_t _886_$retval;
    _889_i = _886_x;
    goto BB1;
BB1:
    _886_t1 = 0;
    _886_t2 = _889_i >= _886_t1;
    if (_886_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _886_x = $add_int64_t(_886_x, _889_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _886_t4 = 1;
    _889_i = $sub_int64_t(_889_i, _886_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _886_$retval = _886_x;
    return _886_$retval;
}

int main(void) {
  printf("%ld",_884_main());
  return 0;
}
