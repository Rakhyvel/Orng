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
int64_t _60_main(void);
int64_t _62_add(int64_t _62_x,int64_t _62_y);

/* Function definitions */
int64_t _60_main(void) {
    function0 _61_f;
    int64_t _60_t2;
    int64_t _60_t3;
    int64_t _60_t1;
    int64_t _60_$retval;
    _61_f = _62_add;
    _60_t2 = 200;
    _60_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _60_t1 = _61_f(_60_t2, _60_t3);
    $line_idx--;
    _60_$retval = _60_t1;
    return _60_$retval;
}

int64_t _62_add(int64_t _62_x,int64_t _62_y) {
    int64_t _62_$retval;
    _62_$retval = $add_int64_t(_62_x, _62_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _62_$retval;
}

int main(void) {
  printf("%ld",_60_main());
  return 0;
}
