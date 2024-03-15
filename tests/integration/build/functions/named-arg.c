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
int64_t _985_main(void);
int64_t _987_div(int64_t _987_x, int64_t _987_y);


/* Function definitions */
int64_t _985_main(void){
    function0 _985_t0;
    int64_t _985_t2;
    int64_t _985_t3;
    int64_t _985_t1;
    int64_t _985_$retval;
    _985_t0 = (function0) _987_div;
    _985_t2 = 510;
    _985_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _985_t1 = _985_t0(_985_t2, _985_t3);
    $line_idx--;
    _985_$retval = _985_t1;
    return _985_$retval;
}

int64_t _987_div(int64_t _987_x, int64_t _987_y){
    int64_t _987_$retval;
    _987_$retval = $div_int64_t(_987_x, _987_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _987_$retval;
}


int main(void) {
  printf("%ld",_985_main());
  return 0;
}
