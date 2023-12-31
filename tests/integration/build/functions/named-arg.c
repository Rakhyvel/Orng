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
int64_t _974_main(void);
int64_t _976_div(int64_t _976_x, int64_t _976_y);

/* Function definitions */
int64_t _974_main(void){
    function0 _974_t0;
    int64_t _974_t2;
    int64_t _974_t3;
    int64_t _974_t1;
    int64_t _974_$retval;
    _974_t0 = _976_div;
    _974_t2 = 510;
    _974_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _974_t1 = _974_t0(_974_t2, _974_t3);
    $line_idx--;
    _974_$retval = _974_t1;
    return _974_$retval;
}

int64_t _976_div(int64_t _976_x, int64_t _976_y){
    int64_t _976_$retval;
    _976_$retval = $div_int64_t(_976_x, _976_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _976_$retval;
}

int main(void) {
  printf("%ld",_974_main());
  return 0;
}
