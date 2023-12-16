/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _923_main(void);
int64_t _925_sum_down(int64_t _925_x);

/* Function definitions */
int64_t _923_main(void){
    function0 _923_t0;
    int64_t _923_t2;
    int64_t _923_t1;
    int64_t _923_t3;
    int64_t _923_$retval;
    _923_t0 = _925_sum_down;
    _923_t2 = 8;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _923_t1 = _923_t0(_923_t2);
    $line_idx--;
    _923_t3 = 2;
    _923_$retval = $add_int64_t(_923_t1, _923_t3, "tests/integration/functions/mut-param.orng:2:32:\nfn main() -> Int {sum_down(8) + 2}\n                              ^");
    return _923_$retval;
}

int64_t _925_sum_down(int64_t _925_x){
    int64_t _927_i;
    int64_t _925_t1;
    uint8_t _925_t2;
    int64_t _925_t4;
    int64_t _925_$retval;
    _927_i = _925_x;
    goto BB1;
BB1:
    _925_t1 = 0;
    _925_t2 = _927_i >= _925_t1;
    if (_925_t2) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _925_x = $add_int64_t(_925_x, _927_i, "tests/integration/functions/mut-param.orng:6:13:\n        x += i\n           ^");
    _925_t4 = 1;
    _927_i = $sub_int64_t(_927_i, _925_t4, "tests/integration/functions/mut-param.orng:5:38:\n    while let mut i = x; i >= 0; i -= 1 {\n                                    ^");
    goto BB1;
BB7:
    _925_$retval = _925_x;
    return _925_$retval;
}

int main(void) {
  printf("%ld",_923_main());
  return 0;
}
