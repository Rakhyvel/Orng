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
int64_t _695_main(void);
int64_t _697_div(int64_t _697_x,int64_t _697_y);

/* Function definitions */
int64_t _695_main(void) {
    function0 _695_t0;
    int64_t _695_t2;
    int64_t _695_t3;
    int64_t _695_t1;
    int64_t _695_$retval;
    _695_t0 = _697_div;
    _695_t2 = 510;
    _695_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _695_t1 = _695_t0(_695_t2, _695_t3);
    $line_idx--;
    _695_$retval = _695_t1;
    return _695_$retval;
}

int64_t _697_div(int64_t _697_x,int64_t _697_y) {
    int64_t _697_$retval;
    _697_$retval = $div_int64_t(_697_x, _697_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _697_$retval;
}

int main(void) {
  printf("%ld",_695_main());
  return 0;
}
