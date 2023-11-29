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
int64_t _735_main(void);
int64_t _737_div(int64_t _737_x,int64_t _737_y);

/* Function definitions */
int64_t _735_main(void) {
    function0 _735_t0;
    int64_t _735_t2;
    int64_t _735_t3;
    int64_t _735_t1;
    int64_t _735_$retval;
    _735_t0 = _737_div;
    _735_t2 = 510;
    _735_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _735_t1 = _735_t0(_735_t2, _735_t3);
    $line_idx--;
    _735_$retval = _735_t1;
    return _735_$retval;
}

int64_t _737_div(int64_t _737_x,int64_t _737_y) {
    int64_t _737_$retval;
    _737_$retval = $div_int64_t(_737_x, _737_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _737_$retval;
}

int main(void) {
  printf("%ld",_735_main());
  return 0;
}
