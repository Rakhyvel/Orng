/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _964_main(void);
int64_t _966_sum_down(int64_t _966_x);

/* Function definitions */
int64_t _964_main(void){
    function0 _964_t0;
    int64_t _964_t2;
    int64_t _964_t1;
    int64_t _964_t3;
    int64_t _964_$retval;
    _964_t0 = _966_sum_down;
    _964_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _964_t1 = _964_t0(_964_t2);
    $line_idx--;
    _964_t3 = 2;
    _964_$retval = $add_int64_t(_964_t1, _964_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _964_$retval;
}

int64_t _966_sum_down(int64_t _966_x){
    int64_t _968_i;
    int64_t _966_t1;
    uint8_t _966_t2;
    int64_t _966_t4;
    int64_t _966_$retval;
    _968_i = _966_x;
    goto BB1167;
BB1167:
    _966_t1 = 0;
    _966_t2 = _968_i>=_966_t1;
    if (_966_t2) {
        goto BB1168;
    } else {
        goto BB1173;
    }
BB1168:
    _966_x = $add_int64_t(_966_x, _968_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _966_t4 = 1;
    _968_i = $sub_int64_t(_968_i, _966_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1167;
BB1173:
    _966_$retval = _966_x;
    return _966_$retval;
}

int main(void) {
  printf("%ld",_964_main());
  return 0;
}
