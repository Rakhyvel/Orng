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
int64_t _104_main(void);
int64_t _107_add(int64_t _107_x,int64_t _107_y);

/* Function definitions */
int64_t _104_main(void) {
    function0 _105_f;
    int64_t _104_t2;
    int64_t _104_t3;
    int64_t _104_t1;
    int64_t _104_$retval;
    _105_f = _107_add;
    _104_t2 = 200;
    _104_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _104_t1 = _105_f(_104_t2, _104_t3);
    $line_idx--;
    _104_$retval = _104_t1;
    return _104_$retval;
}

int64_t _107_add(int64_t _107_x,int64_t _107_y) {
    int64_t _107_$retval;
    _107_$retval = $add_int64_t(_107_x, _107_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _107_$retval;
}

int main(void) {
  printf("%ld",_104_main());
  return 0;
}
