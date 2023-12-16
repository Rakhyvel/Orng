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
int64_t _189_main(void);
int64_t _191_add(int64_t _191_x,int64_t _191_y);

/* Function definitions */
int64_t _189_main(void){
    function0 _190_f;
    int64_t _189_t2;
    int64_t _189_t3;
    int64_t _189_t1;
    int64_t _189_$retval;
    _190_f = _191_add;
    _189_t2 = 200;
    _189_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _189_t1 = _190_f(_189_t2, _189_t3);
    $line_idx--;
    _189_$retval = _189_t1;
    return _189_$retval;
}

int64_t _191_add(int64_t _191_x,int64_t _191_y){
    int64_t _191_$retval;
    _191_$retval = $add_int64_t(_191_x, _191_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _191_$retval;
}

int main(void) {
  printf("%ld",_189_main());
  return 0;
}
