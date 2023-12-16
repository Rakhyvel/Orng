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
int64_t _995_main(void);
int64_t _997_div(int64_t _997_x,int64_t _997_y);

/* Function definitions */
int64_t _995_main(void){
    function0 _995_t0;
    int64_t _995_t2;
    int64_t _995_t3;
    int64_t _995_t1;
    int64_t _995_$retval;
    _995_t0 = _997_div;
    _995_t2 = 510;
    _995_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _995_t1 = _995_t0(_995_t2, _995_t3);
    $line_idx--;
    _995_$retval = _995_t1;
    return _995_$retval;
}

int64_t _997_div(int64_t _997_x,int64_t _997_y){
    int64_t _997_$retval;
    _997_$retval = $div_int64_t(_997_x, _997_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _997_$retval;
}

int main(void) {
  printf("%ld",_995_main());
  return 0;
}
