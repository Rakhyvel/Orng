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
int64_t _663_main(void);
int64_t _665_div(int64_t _665_x,int64_t _665_y);

/* Function definitions */
int64_t _663_main(void) {
    function0 _663_t0;
    int64_t _663_t2;
    int64_t _663_t3;
    int64_t _663_t1;
    int64_t _663_$retval;
    _663_t0 = _665_div;
    _663_t2 = 510;
    _663_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _663_t1 = _663_t0(_663_t2, _663_t3);
    $line_idx--;
    _663_$retval = _663_t1;
    return _663_$retval;
}

int64_t _665_div(int64_t _665_x,int64_t _665_y) {
    int64_t _665_$retval;
    _665_$retval = $div_int64_t(_665_x, _665_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _665_$retval;
}

int main(void) {
  printf("%ld",_663_main());
  return 0;
}
