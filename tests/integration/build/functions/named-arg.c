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
int64_t _1080_main(void);
int64_t _1082_div(int64_t _1082_x,int64_t _1082_y);

/* Function definitions */
int64_t _1080_main(void){
    function0 _1080_t0;
    int64_t _1080_t2;
    int64_t _1080_t3;
    int64_t _1080_t1;
    int64_t _1080_$retval;
    _1080_t0 = _1082_div;
    _1080_t2 = 510;
    _1080_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _1080_t1 = _1080_t0(_1080_t2, _1080_t3);
    $line_idx--;
    _1080_$retval = _1080_t1;
    return _1080_$retval;
}

int64_t _1082_div(int64_t _1082_x,int64_t _1082_y){
    int64_t _1082_$retval;
    _1082_$retval = $div_int64_t(_1082_x, _1082_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _1082_$retval;
}

int main(void) {
  printf("%ld",_1080_main());
  return 0;
}
