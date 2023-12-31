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
int64_t _961_main(void);
int64_t _963_sum_down(int64_t _963_x);

/* Function definitions */
int64_t _961_main(void){
    function0 _961_t0;
    int64_t _961_t2;
    int64_t _961_t1;
    int64_t _961_t3;
    int64_t _961_$retval;
    _961_t0 = _963_sum_down;
    _961_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _961_t1 = _961_t0(_961_t2);
    $line_idx--;
    _961_t3 = 2;
    _961_$retval = $add_int64_t(_961_t1, _961_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _961_$retval;
}

int64_t _963_sum_down(int64_t _963_x){
    int64_t _965_i;
    int64_t _963_t1;
    uint8_t _963_t2;
    int64_t _963_t4;
    int64_t _963_$retval;
    _965_i = _963_x;
    goto BB1175;
BB1175:
    _963_t1 = 0;
    _963_t2 = _965_i>=_963_t1;
    if (_963_t2) {
        goto BB1176;
    } else {
        goto BB1181;
    }
BB1176:
    _963_x = $add_int64_t(_963_x, _965_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _963_t4 = 1;
    _965_i = $sub_int64_t(_965_i, _963_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1175;
BB1181:
    _963_$retval = _963_x;
    return _963_$retval;
}

int main(void) {
  printf("%ld",_961_main());
  return 0;
}
