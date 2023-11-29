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
int64_t _254_main(void);
int64_t _257_add(int64_t _257_x,int64_t _257_y);

/* Function definitions */
int64_t _254_main(void) {
    function0 _255_f;
    int64_t _254_t2;
    int64_t _254_t3;
    int64_t _254_t1;
    int64_t _254_$retval;
    _255_f = _257_add;
    _254_t2 = 200;
    _254_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _254_t1 = _255_f(_254_t2, _254_t3);
    $line_idx--;
    _254_$retval = _254_t1;
    return _254_$retval;
}

int64_t _257_add(int64_t _257_x,int64_t _257_y) {
    int64_t _257_$retval;
    _257_$retval = $add_int64_t(_257_x, _257_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _257_$retval;
}

int main(void) {
  printf("%ld",_254_main());
  return 0;
}
