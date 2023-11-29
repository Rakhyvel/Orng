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
int64_t _76_main(void);
int64_t _78_add(int64_t _78_x,int64_t _78_y);

/* Function definitions */
int64_t _76_main(void) {
    function0 _77_f;
    int64_t _76_t2;
    int64_t _76_t3;
    int64_t _76_t1;
    int64_t _76_$retval;
    _77_f = _78_add;
    _76_t2 = 200;
    _76_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _76_t1 = _77_f(_76_t2, _76_t3);
    $line_idx--;
    _76_$retval = _76_t1;
    return _76_$retval;
}

int64_t _78_add(int64_t _78_x,int64_t _78_y) {
    int64_t _78_$retval;
    _78_$retval = $add_int64_t(_78_x, _78_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _78_$retval;
}

int main(void) {
  printf("%ld",_76_main());
  return 0;
}
