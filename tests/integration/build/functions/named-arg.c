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
int64_t _632_main(void);
int64_t _634_div(int64_t _634_x,int64_t _634_y);

/* Function definitions */
int64_t _632_main(void) {
    function0 _632_t0;
    int64_t _632_t2;
    int64_t _632_t3;
    int64_t _632_t1;
    int64_t _632_$retval;
    _632_t0 = _634_div;
    _632_t2 = 510;
    _632_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _632_t1 = _632_t0(_632_t2, _632_t3);
    $line_idx--;
    _632_$retval = _632_t1;
    return _632_$retval;
}

int64_t _634_div(int64_t _634_x,int64_t _634_y) {
    int64_t _634_$retval;
    _634_$retval = $div_int64_t(_634_x, _634_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _634_$retval;
}

int main(void) {
  printf("%ld",_632_main());
  return 0;
}
