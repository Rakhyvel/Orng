/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _1004_main(void);
int64_t _1006_div(int64_t _1006_x, int64_t _1006_y);


/* Function definitions */
int64_t _1004_main(void){
    function0 _1004_t0;
    int64_t _1004_t2;
    int64_t _1004_t3;
    int64_t _1004_t1;
    int64_t _1004_$retval;
    _1004_t0 = (function0) _1006_div;
    _1004_t2 = 510;
    _1004_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _1004_t1 = _1004_t0(_1004_t2, _1004_t3);
    $line_idx--;
    _1004_$retval = _1004_t1;
    return _1004_$retval;
}

int64_t _1006_div(int64_t _1006_x, int64_t _1006_y){
    int64_t _1006_$retval;
    _1006_$retval = $div_int64_t(_1006_x, _1006_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _1006_$retval;
}


int main(void) {
  printf("%ld",_1004_main());
  return 0;
}
