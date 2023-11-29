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
int64_t _898_main(void);
int64_t _900_div(int64_t _900_x,int64_t _900_y);

/* Function definitions */
int64_t _898_main(void) {
    function0 _898_t0;
    int64_t _898_t2;
    int64_t _898_t3;
    int64_t _898_t1;
    int64_t _898_$retval;
    _898_t0 = _900_div;
    _898_t2 = 510;
    _898_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _898_t1 = _898_t0(_898_t2, _898_t3);
    $line_idx--;
    _898_$retval = _898_t1;
    return _898_$retval;
}

int64_t _900_div(int64_t _900_x,int64_t _900_y) {
    int64_t _900_$retval;
    _900_$retval = $div_int64_t(_900_x, _900_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _900_$retval;
}

int main(void) {
  printf("%ld",_898_main());
  return 0;
}
