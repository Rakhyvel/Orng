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
int64_t _924_main(void);
int64_t _926_div(int64_t _926_x,int64_t _926_y);

/* Function definitions */
int64_t _924_main(void){
    function0 _924_t0;
    int64_t _924_t2;
    int64_t _924_t3;
    int64_t _924_t1;
    int64_t _924_$retval;
    _924_t0 = _926_div;
    _924_t2 = 510;
    _924_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _924_t1 = _924_t0(_924_t2, _924_t3);
    $line_idx--;
    _924_$retval = _924_t1;
    return _924_$retval;
}

int64_t _926_div(int64_t _926_x,int64_t _926_y){
    int64_t _926_$retval;
    _926_$retval = $div_int64_t(_926_x, _926_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _926_$retval;
}

int main(void) {
  printf("%ld",_924_main());
  return 0;
}
