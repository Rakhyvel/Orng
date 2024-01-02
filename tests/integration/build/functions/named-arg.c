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
int64_t _977_main(void);
int64_t _979_div(int64_t _979_x, int64_t _979_y);

/* Function definitions */
int64_t _977_main(void){
    function0 _977_t0;
    int64_t _977_t2;
    int64_t _977_t3;
    int64_t _977_t1;
    int64_t _977_$retval;
    _977_t0 = _979_div;
    _977_t2 = 510;
    _977_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _977_t1 = _977_t0(_977_t2, _977_t3);
    $line_idx--;
    _977_$retval = _977_t1;
    return _977_$retval;
}

int64_t _979_div(int64_t _979_x, int64_t _979_y){
    int64_t _979_$retval;
    _979_$retval = $div_int64_t(_979_x, _979_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _979_$retval;
}

int main(void) {
  printf("%ld",_977_main());
  return 0;
}
