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
int64_t _3_main(void);
int64_t _5_add(int64_t _5_x,int64_t _5_y);

/* Function definitions */
int64_t _3_main(void) {
    function0 _4_f;
    int64_t _3_t2;
    int64_t _3_t3;
    int64_t _3_t1;
    int64_t _3_$retval;
    _4_f = _5_add;
    _3_t2 = 200;
    _3_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _3_t1 = _4_f(_3_t2, _3_t3);
    $line_idx--;
    _3_$retval = _3_t1;
    return _3_$retval;
}

int64_t _5_add(int64_t _5_x,int64_t _5_y) {
    int64_t _5_$retval;
    _5_$retval = $add_int64_t(_5_x, _5_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _5_$retval;
}

int main(void) {
  printf("%ld",_3_main());
  return 0;
}
