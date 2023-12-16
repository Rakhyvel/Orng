/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _916_main(void);
int64_t _918_div(int64_t _918_x,int64_t _918_y);

/* Function definitions */
int64_t _916_main(void) {
    function0 _916_t0;
    int64_t _916_t2;
    int64_t _916_t3;
    int64_t _916_t1;
    int64_t _916_$retval;
    _916_t0 = _918_div;
    _916_t2 = 510;
    _916_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _916_t1 = _916_t0(_916_t2, _916_t3);
    $line_idx--;
    _916_$retval = _916_t1;
    return _916_$retval;
}

int64_t _918_div(int64_t _918_x,int64_t _918_y) {
    int64_t _918_$retval;
    _918_$retval = $div_int64_t(_918_x, _918_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _918_$retval;
}

int main(void) {
  printf("%ld",_916_main());
  return 0;
}
