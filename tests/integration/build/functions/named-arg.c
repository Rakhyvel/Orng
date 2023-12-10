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
int64_t _719_main(void);
int64_t _721_div(int64_t _721_x,int64_t _721_y);

/* Function definitions */
int64_t _719_main(void) {
    function0 _719_t0;
    int64_t _719_t2;
    int64_t _719_t3;
    int64_t _719_t1;
    int64_t _719_$retval;
    _719_t0 = _721_div;
    _719_t2 = 510;
    _719_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _719_t1 = _719_t0(_719_t2, _719_t3);
    $line_idx--;
    _719_$retval = _719_t1;
    return _719_$retval;
}

int64_t _721_div(int64_t _721_x,int64_t _721_y) {
    int64_t _721_$retval;
    _721_$retval = $div_int64_t(_721_x, _721_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _721_$retval;
}

int main(void) {
  printf("%ld",_719_main());
  return 0;
}
