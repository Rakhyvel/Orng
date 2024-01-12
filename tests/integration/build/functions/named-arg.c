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
int64_t _987_main(void);
int64_t _989_div(int64_t _989_x, int64_t _989_y);

/* Function definitions */
int64_t _987_main(void){
    function0 _987_t0;
    int64_t _987_t2;
    int64_t _987_t3;
    int64_t _987_t1;
    int64_t _987_$retval;
    _987_t0 = _989_div;
    _987_t2 = 510;
    _987_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _987_t1 = _987_t0(_987_t2, _987_t3);
    $line_idx--;
    _987_$retval = _987_t1;
    return _987_$retval;
}

int64_t _989_div(int64_t _989_x, int64_t _989_y){
    int64_t _989_$retval;
    _989_$retval = $div_int64_t(_989_x, _989_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _989_$retval;
}

int main(void) {
  printf("%ld",_987_main());
  return 0;
}
