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
int64_t _727_main(void);
int64_t _729_div(int64_t _729_x,int64_t _729_y);

/* Function definitions */
int64_t _727_main(void) {
    function0 _727_t0;
    int64_t _727_t2;
    int64_t _727_t3;
    int64_t _727_t1;
    int64_t _727_$retval;
    _727_t0 = _729_div;
    _727_t2 = 510;
    _727_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _727_t1 = _727_t0(_727_t2, _727_t3);
    $line_idx--;
    _727_$retval = _727_t1;
    return _727_$retval;
}

int64_t _729_div(int64_t _729_x,int64_t _729_y) {
    int64_t _729_$retval;
    _729_$retval = $div_int64_t(_729_x, _729_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _729_$retval;
}

int main(void) {
  printf("%ld",_727_main());
  return 0;
}
