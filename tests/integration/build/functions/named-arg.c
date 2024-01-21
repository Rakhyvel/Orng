/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _992_main(void);
int64_t _994_div(int64_t _994_x, int64_t _994_y);

/* Function definitions */
int64_t _992_main(void){
    function0 _992_t0;
    int64_t _992_t2;
    int64_t _992_t3;
    int64_t _992_t1;
    int64_t _992_$retval;
    _992_t0 = _994_div;
    _992_t2 = 510;
    _992_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _992_t1 = _992_t0(_992_t2, _992_t3);
    $line_idx--;
    _992_$retval = _992_t1;
    return _992_$retval;
}

int64_t _994_div(int64_t _994_x, int64_t _994_y){
    int64_t _994_$retval;
    _994_$retval = $div_int64_t(_994_x, _994_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _994_$retval;
}

int main(void) {
  printf("%ld",_992_main());
  return 0;
}
