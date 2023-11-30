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
int64_t _877_main(void);
int64_t _879_div(int64_t _879_x,int64_t _879_y);

/* Function definitions */
int64_t _877_main(void) {
    function0 _877_t0;
    int64_t _877_t2;
    int64_t _877_t3;
    int64_t _877_t1;
    int64_t _877_$retval;
    _877_t0 = _879_div;
    _877_t2 = 510;
    _877_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _877_t1 = _877_t0(_877_t2, _877_t3);
    $line_idx--;
    _877_$retval = _877_t1;
    return _877_$retval;
}

int64_t _879_div(int64_t _879_x,int64_t _879_y) {
    int64_t _879_$retval;
    _879_$retval = $div_int64_t(_879_x, _879_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _879_$retval;
}

int main(void) {
  printf("%ld",_877_main());
  return 0;
}
