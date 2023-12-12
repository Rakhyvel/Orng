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
int64_t _746_main(void);
int64_t _748_div(int64_t _748_x,int64_t _748_y);

/* Function definitions */
int64_t _746_main(void) {
    function0 _746_t0;
    int64_t _746_t2;
    int64_t _746_t3;
    int64_t _746_t1;
    int64_t _746_$retval;
    _746_t0 = _748_div;
    _746_t2 = 510;
    _746_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _746_t1 = _746_t0(_746_t2, _746_t3);
    $line_idx--;
    _746_$retval = _746_t1;
    return _746_$retval;
}

int64_t _748_div(int64_t _748_x,int64_t _748_y) {
    int64_t _748_$retval;
    _748_$retval = $div_int64_t(_748_x, _748_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _748_$retval;
}

int main(void) {
  printf("%ld",_746_main());
  return 0;
}
