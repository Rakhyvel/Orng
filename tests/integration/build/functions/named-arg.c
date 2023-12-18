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
int64_t _1088_main(void);
int64_t _1090_div(int64_t _1090_x,int64_t _1090_y);

/* Function definitions */
int64_t _1088_main(void){
    function0 _1088_t0;
    int64_t _1088_t2;
    int64_t _1088_t3;
    int64_t _1088_t1;
    int64_t _1088_$retval;
    _1088_t0 = _1090_div;
    _1088_t2 = 510;
    _1088_t3 = 10;
    $lines[$line_idx++] = "tests/integration/functions/named-arg.orng:3:9:\n    div(.x = 510, .y = 10)\n       ^";
    _1088_t1 = _1088_t0(_1088_t2, _1088_t3);
    $line_idx--;
    _1088_$retval = _1088_t1;
    return _1088_$retval;
}

int64_t _1090_div(int64_t _1090_x,int64_t _1090_y){
    int64_t _1090_$retval;
    _1090_$retval = $div_int64_t(_1090_x, _1090_y, "tests/integration/functions/named-arg.orng:6:35:\nfn div(x: Int, y: Int) -> Int {x / y}\n                                 ^");
    return _1090_$retval;
}

int main(void) {
  printf("%ld",_1088_main());
  return 0;
}
